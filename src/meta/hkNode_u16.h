#pragma once
/* hkNode_u16 */
#include "../core.h"



structdef(hkNode_u16) {
    hkNode_u16 *next;
    u16 data;
};

hkNode_u16 *hknode_u16_init(u16 data) {
    hkNode_u16 *node = malloc(sizeof(hkNode_u16));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hknode_u16_deinit(hkNode_u16 **node) {
    free(*node);
    *node = null;
}

