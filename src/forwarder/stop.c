#include "rtsyn/internal/forwarder.h"
#include "rtsyn/internal/forwarder/stop.h"

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_stop(void *instance)
{
    rtsyn_forwarder_instance_t *forwarder = (rtsyn_forwarder_instance_t *)instance;
    if (!forwarder)
    {
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
    forwarder->value = 0.0;

    return RTSYN_ABI_STATUS_OK;
}
