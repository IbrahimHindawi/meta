#pragma once
/* hkNode_f64 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_f64 {
    struct hkNode_f64 *next;
    f64 data;
};

struct hkNode_f64 *hknode_f64_init(f64 data) {
    struct hkNode_f64 *node = malloc(sizeof(struct hkNode_f64));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hknode_f64_deinit(struct hkNode_f64 **node) {
    free(*node);
    *node = null;
}

