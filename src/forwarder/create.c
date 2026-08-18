
#include <stdlib.h>

#include "rtsyn/internal/forwarder.h"
#include "rtsyn/internal/forwarder/create.h"

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_create(void **out_instance)
{

    if (!out_instance)
    {
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }

    rtsyn_forwarder_instance_t *forwarder =
        (rtsyn_forwarder_instance_t *)malloc(sizeof(rtsyn_forwarder_instance_t));

    if (!forwarder)
    {
        return RTSYN_ABI_STATUS_ERROR;
    }

    forwarder->value = 0.0;
    *out_instance = forwarder;

    return RTSYN_ABI_STATUS_OK;
}
