#include "rtsyn/internal/forwarder.h"
#include "rtsyn/internal/forwarder/process.h"

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_process(void *instance, const rtsyn_abi_runtime_context_t *context)
{
    rtsyn_forwarder_instance_t *forwarder = (rtsyn_forwarder_instance_t *)instance;

    if (!forwarder || !context || !context->api || !context->api->write)
    {
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }

    return context->api->write(context, RTSYN_FORWARDER_PORT_OUT, &forwarder->value);
}
