#pragma once
/* hkNode_u8 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_u8 {
    struct hkNode_u8 *next;
    u8 data;
};

struct hkNode_u8 *hkNode_u8_init(u8 data) {
    struct hkNode_u8 *node = malloc(sizeof(struct hkNode_u8));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hkNode_u8_deinit(struct hkNode_u8 **node) {
    free(*node);
    *node = null;
}

