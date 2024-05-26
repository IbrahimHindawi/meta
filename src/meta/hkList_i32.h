#pragma once
/* hkList_i32 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_i32.h"

structdef(hkList_i32) {
    hkNode_i32 *head;
    hkNode_i32 *tail;
};

hkList_i32 *hklist_i32_init() {
    hkList_i32 *list = malloc(sizeof(hkList_i32));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_i32_append(hkList_i32 *list, i32 data) {
    if (!list->head) {
        list->head = hknode_i32_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_i32_init(data);
        list->head->next = list->tail;
        return;
    }
    hkNode_i32 *temp = hknode_i32_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_i32_deinit(hkList_i32 **list) {
    free(*list);
    *list = null;
}

