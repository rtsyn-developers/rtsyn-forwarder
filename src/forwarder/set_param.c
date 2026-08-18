#include "rtsyn/internal/forwarder.h"
#include "rtsyn/internal/forwarder/set_param.h"

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_set_param(void *instance, uint32_t param_index, const void *value)
{
    rtsyn_forwarder_instance_t *forwarder = (rtsyn_forwarder_instance_t *)instance;

    if (!forwarder || !value)
    {
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }

    switch (param_index)
    {
        case RTSYN_FORWARDER_PARAM_VALUE:
            forwarder->value = *(const double *)value;
            return RTSYN_ABI_STATUS_OK;
        default:
            return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
}
