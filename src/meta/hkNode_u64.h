#pragma once
/* hkNode_u64 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_u64 {
    struct hkNode_u64 *next;
    u64 data;
};

struct hkNode_u64 *hkNode_u64_init(u64 data) {
    struct hkNode_u64 *node = malloc(sizeof(struct hkNode_u64));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hkNode_u64_deinit(struct hkNode_u64 **node) {
    free(*node);
    *node = null;
}

