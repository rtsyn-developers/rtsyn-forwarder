#include <cstdint>
#include <cstring>
#include <gtest/gtest.h>

#include "rtsyn/forwarder.h"

namespace {

struct HostContext {
    double output;
};

rtsyn_abi_status_t
read(const rtsyn_abi_runtime_context_t *context, uint32_t port_index, void *out_value)
{
    (void)context;
    (void)port_index;
    (void)out_value;
    return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
}

rtsyn_abi_status_t
write(const rtsyn_abi_runtime_context_t *context, uint32_t port_index, const void *value)
{
    if (port_index != 0 || value == nullptr)
    {
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
    auto *host = const_cast<HostContext *>(static_cast<const HostContext *>(context->host_context));
    std::memcpy(&host->output, value, sizeof(double));
    return RTSYN_ABI_STATUS_OK;
}

TEST(ForwarderPlugin, DescribesOneOutputAndOneParameter)
{
    const auto *descriptor = rtsyn_forwarder_get_descriptor();

    ASSERT_NE(descriptor, nullptr);
    EXPECT_STREQ(descriptor->name, "forwarder");
    ASSERT_EQ(descriptor->port_count, 1U);
    EXPECT_EQ(descriptor->ports[0].value_type, RTSYN_ABI_VALUE_F64);
    EXPECT_EQ(descriptor->ports[0].direction, RTSYN_ABI_PORT_DIRECTION_OUT);
    EXPECT_STREQ(descriptor->ports[0].name, "out");
    ASSERT_EQ(descriptor->param_count, 1U);
    EXPECT_STREQ(descriptor->params[0].name, "value");
    EXPECT_EQ(descriptor->params[0].value_type, RTSYN_ABI_VALUE_F64);
    EXPECT_EQ(descriptor->state_count, 0U);
    EXPECT_EQ(descriptor->states, nullptr);
}

TEST(ForwarderPlugin, ForwardsParameterToOutputPort)
{
    const auto *descriptor = rtsyn_forwarder_get_descriptor();
    void *instance = nullptr;
    HostContext host{0.0};
    const rtsyn_abi_runtime_api_t api{read, write};
    const rtsyn_abi_runtime_context_t context{0,    0,    0, RTSYN_RUNTIME_CYCLE_STAGE_INTERMEDIATE,
                                              &api, &host};
    const double value = 42.5;

    ASSERT_EQ(descriptor->callbacks.create(&instance), RTSYN_ABI_STATUS_OK);
    ASSERT_NE(instance, nullptr);
    ASSERT_EQ(descriptor->callbacks.set_param(instance, 0, &value), RTSYN_ABI_STATUS_OK);
    ASSERT_EQ(descriptor->callbacks.start(instance), RTSYN_ABI_STATUS_OK);
    ASSERT_EQ(descriptor->callbacks.process(instance, &context), RTSYN_ABI_STATUS_OK);
    EXPECT_DOUBLE_EQ(host.output, value);
    descriptor->callbacks.destroy(instance);
}

TEST(ForwarderPlugin, RejectsInvalidParameterAndStateAccess)
{
    const auto *descriptor = rtsyn_forwarder_get_descriptor();
    void *instance = nullptr;
    const double value = 1.0;
    double state = 0.0;

    ASSERT_EQ(descriptor->callbacks.create(&instance), RTSYN_ABI_STATUS_OK);
    ASSERT_NE(instance, nullptr);
    EXPECT_EQ(descriptor->callbacks.set_param(instance, 1, &value),
              RTSYN_ABI_STATUS_INVALID_ARGUMENT);
    EXPECT_EQ(descriptor->callbacks.read_state(instance, 0, &state),
              RTSYN_ABI_STATUS_INVALID_ARGUMENT);
    descriptor->callbacks.destroy(instance);
}

} // namespace
