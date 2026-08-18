#ifndef RTSYN_INTERNAL_FORWARDER_SET_PARAM_H
#define RTSYN_INTERNAL_FORWARDER_SET_PARAM_H
#include <rtsyn/abi.h>
#include <stdint.h>

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_set_param(void *instance, uint32_t param_index, const void *value);

#endif /* RTSYN_INTERNAL_FORWARDER_SET_PARAM_H */
