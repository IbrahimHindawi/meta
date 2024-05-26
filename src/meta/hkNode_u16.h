#pragma once
/* hkNode_u16 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_u16 {
    struct hkNode_u16 *next;
    u16 data;
};

struct hkNode_u16 *hknode_u16_init(u16 data) {
    struct hkNode_u16 *node = malloc(sizeof(struct hkNode_u16));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hknode_u16_deinit(struct hkNode_u16 **node) {
    free(*node);
    *node = null;
}

