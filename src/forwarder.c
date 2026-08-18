#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "rtsyn/forwarder.h"
#include "rtsyn/internal/forwarder.h"
#include "rtsyn/internal/forwarder/create.h"
#include "rtsyn/internal/forwarder/destroy.h"
#include "rtsyn/internal/forwarder/process.h"
#include "rtsyn/internal/forwarder/read_state.h"
#include "rtsyn/internal/forwarder/set_param.h"
#include "rtsyn/internal/forwarder/start.h"
#include "rtsyn/internal/forwarder/stop.h"

static const rtsyn_abi_port_descriptor_t rtsyn_forwarder_ports[RTSYN_FORWARDER_PORT_COUNT] = {
    [RTSYN_FORWARDER_PORT_OUT] =
        {
            .name = "out",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
};

static const rtsyn_abi_param_descriptor_t rtsyn_forwarder_params[RTSYN_FORWARDER_PARAM_COUNT] = {
    [RTSYN_FORWARDER_PARAM_VALUE] =
        {
            .name = "value",
            .description = "Value forwarded to the output port",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
};

static const rtsyn_abi_node_descriptor_t rtsyn_forwarder_descriptor = {
    .name = "forwarder",
    .node_type = RTSYN_ABI_NODE_PLUGIN,
    .port_count = RTSYN_FORWARDER_PORT_COUNT,
    .ports = rtsyn_forwarder_ports,
    .param_count = RTSYN_FORWARDER_PARAM_COUNT,
    .params = rtsyn_forwarder_params,
    .state_count = RTSYN_FORWARDER_STATE_COUNT,
    .states = NULL,
    .callbacks =
        {
            .create = rtsyn_forwarder_create,
            .set_param = rtsyn_forwarder_set_param,
            .read_state = rtsyn_forwarder_read_state,
            .start = rtsyn_forwarder_start,
            .process = rtsyn_forwarder_process,
            .stop = rtsyn_forwarder_stop,
            .destroy = rtsyn_forwarder_destroy,
        },
};

const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL
rtsyn_forwarder_get_descriptor(void)
{
    return &rtsyn_forwarder_descriptor;
}

const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL
rtsyn_module_get_descriptor(void)
{
    return rtsyn_forwarder_get_descriptor();
}
