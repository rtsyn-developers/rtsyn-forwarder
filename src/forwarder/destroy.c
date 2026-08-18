#include <stdlib.h>

#include "rtsyn/internal/forwarder.h"
#include "rtsyn/internal/forwarder/destroy.h"

void RTSYN_ABI_CALL
rtsyn_forwarder_destroy(void *instance)
{
    rtsyn_forwarder_instance_t *forwarder = (rtsyn_forwarder_instance_t *)instance;
    free(forwarder);
}
