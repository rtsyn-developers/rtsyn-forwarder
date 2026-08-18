/**
 * @file rtsyn/forwarder.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Module Plugin Forwarder.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_FORWARDER_H
#define RTSYN_FORWARDER_H

#include <rtsyn/abi/node.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Return the ABI descriptor for the forwarder node.
 *
 * The returned descriptor has static storage duration and must not be modified
 * or freed by the caller.
 */
RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL
rtsyn_forwarder_get_descriptor(void);

/** Standard entry point used by the RTSyn module loader. */
RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL
rtsyn_module_get_descriptor(void);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_FORWARDER_H */
