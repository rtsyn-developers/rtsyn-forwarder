#ifndef RTSYN_INTERNAL_FORWARDER_READ_STATE_H
#define RTSYN_INTERNAL_FORWARDER_READ_STATE_H
#include <rtsyn/abi.h>
#include <stdint.h>

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_read_state(const void *instance, uint32_t state_index, void *out_value);

#endif /* RTSYN_INTERNAL_FORWARDER_READ_STATE_H */
