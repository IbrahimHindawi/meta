#pragma once
/* hkNode_i32 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_i32 {
    struct hkNode_i32 *next;
    i32 data;
};

struct hkNode_i32 *hknode_i32_init(i32 data) {
    struct hkNode_i32 *node = malloc(sizeof(struct hkNode_i32));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hknode_i32_deinit(struct hkNode_i32 **node) {
    free(*node);
    *node = null;
}

