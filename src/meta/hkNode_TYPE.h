#pragma once
/* hkNode_TYPE */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>

#include "TYPE.h"

struct hkNode_TYPE {
    struct hkNode_TYPE *next;
    TYPE data;
};

struct hkNode_TYPE *hkNode_TYPE_init(TYPE data) {
    struct hkNode_TYPE *node = malloc(sizeof(struct hkNode_TYPE));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hkNode_TYPE_deinit(struct hkNode_TYPE **node) {
    free(*node);
    *node = null;
}
