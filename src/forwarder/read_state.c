#include "rtsyn/internal/forwarder.h"
#include "rtsyn/internal/forwarder/read_state.h"

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_read_state(const void *instance, uint32_t state_index, void *out_value)
{
    (void)instance;
    (void)state_index;
    (void)out_value;
    return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
}
