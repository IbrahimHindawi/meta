#pragma once
/* hkNode_f32 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_f32 {
    struct hkNode_f32 *next;
    f32 data;
};

struct hkNode_f32 *hkNode_f32_init(f32 data) {
    struct hkNode_f32 *node = malloc(sizeof(struct hkNode_f32));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hkNode_f32_deinit(struct hkNode_f32 **node) {
    free(*node);
    *node = null;
}

