#pragma once
/* hkList_u32 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_u32.h"

structdef(hkList_u32) {
    hkNode_u32 *head;
    hkNode_u32 *tail;
};

hkList_u32 *hklist_u32_init() {
    hkList_u32 *list = malloc(sizeof(hkList_u32));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_u32_append(hkList_u32 *list, u32 data) {
    if (!list->head) {
        list->head = hknode_u32_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_u32_init(data);
        list->head->next = list->tail;
        return;
    }
    hkNode_u32 *temp = hknode_u32_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_u32_deinit(hkList_u32 **list) {
    free(*list);
    *list = null;
}

