#pragma once
/* hkNode_i16 */
#include "../core.h"



structdef(hkNode_i16) {
    hkNode_i16 *next;
    i16 data;
};

hkNode_i16 *hknode_i16_init(i16 data) {
    hkNode_i16 *node = malloc(sizeof(hkNode_i16));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hknode_i16_deinit(hkNode_i16 **node) {
    free(*node);
    *node = null;
}

