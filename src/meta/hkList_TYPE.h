#pragma once
/* hkList_TYPE */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>

#include "TYPE.h"
#include "hkNode_TYPE.h"

structdef(hkList_TYPE) {
    hkNode_TYPE *head;
    hkNode_TYPE *tail;
};

hkList_TYPE *hklist_TYPE_create() {
    hkList_TYPE *list = malloc(sizeof(hkList_TYPE));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_TYPE_append(hkList_TYPE *list, TYPE data) {
    if (!list->head) {
        list->head = hknode_TYPE_create(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_TYPE_create(data);
        list->head->next = list->tail;
        return;
    }
    hkNode_TYPE *temp = hknode_TYPE_create(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_TYPE_destroy(hkList_TYPE **list) {
    free(*list);
    *list = null;
}
