#include "rtsyn/internal/forwarder.h"
#include "rtsyn/internal/forwarder/start.h"

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_start(void *instance)
{
    rtsyn_forwarder_instance_t *forwarder = (rtsyn_forwarder_instance_t *)instance;

    if (!forwarder)
    {
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
    return RTSYN_ABI_STATUS_OK;
}
