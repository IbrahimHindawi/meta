#pragma once
/* hkNode_u32 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_u32 {
    struct hkNode_u32 *next;
    u32 data;
};

struct hkNode_u32 *hknode_u32_init(u32 data) {
    struct hkNode_u32 *node = malloc(sizeof(struct hkNode_u32));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hknode_u32_deinit(struct hkNode_u32 **node) {
    free(*node);
    *node = null;
}

