/**
 * @file rtsyn/internal/forwarder.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Module Plugin Forwarder.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_FORWARDER_H
#define RTSYN_INTERNAL_FORWARDER_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rtsyn_forwarder_instance_s {
    double value;
} rtsyn_forwarder_instance_t;

typedef enum rtsyn_forwarder_instance_ports_e : uint32_t {
    RTSYN_FORWARDER_PORT_OUT = 0,
    RTSYN_FORWARDER_PORT_COUNT,
} rtsyn_forwarder_instance_ports_t;

typedef enum rtsyn_forwarder_instance_params_e : uint32_t {
    RTSYN_FORWARDER_PARAM_VALUE = 0,
    RTSYN_FORWARDER_PARAM_COUNT,
} rtsyn_forwarder_instance_params_t;

typedef enum rtsyn_forwarder_instance_states_e : uint32_t {
    RTSYN_FORWARDER_STATE_COUNT = 0,
} rtsyn_forwarder_instance_states_t;

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_INTERNAL_FORWARDER_H */
