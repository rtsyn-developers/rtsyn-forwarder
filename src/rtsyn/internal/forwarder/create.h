/**
 * @file rtsyn/internal/forwarder/create.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Module Plugin Forwarder create state.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_FORWARDER_CREATE_H
#define RTSYN_INTERNAL_FORWARDER_CREATE_H
#include <rtsyn/abi.h>

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_create(void **out_instance);

#endif /* RTSYN_INTERNAL_FORWARDER_CREATE_H */
