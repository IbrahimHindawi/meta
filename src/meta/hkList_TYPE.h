#pragma once
/* hkList_TYPE */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>

#include "TYPE.h"
#include "hkNode_TYPE.h"

struct hkList_TYPE {
    struct hkNode_TYPE *head;
    struct hkNode_TYPE *tail;
};

struct hkList_TYPE *hkList_TYPE_init() {
    struct hkList_TYPE *list = malloc(sizeof(struct hkList_TYPE));
    list->head = null;
    list->tail = null;
    return list;
}

void hkList_TYPE_append(struct hkList_TYPE *list, TYPE data) {
    if (!list->head) {
        list->head = hkNode_TYPE_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hkNode_TYPE_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_TYPE *temp = hkNode_TYPE_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hkList_TYPE_deinit(struct hkList_TYPE **list) {
    free(*list);
    *list = null;
}
