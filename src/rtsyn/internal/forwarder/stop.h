/**
 * @file rtsyn/internal/forwarder/stop.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Module Plugin Forwarder stop state.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_FORWARDER_STOP_H
#define RTSYN_INTERNAL_FORWARDER_STOP_H
#include <rtsyn/abi.h>

rtsyn_abi_status_t RTSYN_ABI_CALL
rtsyn_forwarder_stop(void *instance);

#endif /* RTSYN_INTERNAL_FORWARDER_STOP_H */
