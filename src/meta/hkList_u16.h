#pragma once
/* hkList_u16 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_u16.h"

structdef(hkList_u16) {
    hkNode_u16 *head;
    hkNode_u16 *tail;
};

hkList_u16 *hklist_u16_init() {
    hkList_u16 *list = malloc(sizeof(hkList_u16));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_u16_append(hkList_u16 *list, u16 data) {
    if (!list->head) {
        list->head = hknode_u16_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_u16_init(data);
        list->head->next = list->tail;
        return;
    }
    hkNode_u16 *temp = hknode_u16_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_u16_deinit(hkList_u16 **list) {
    free(*list);
    *list = null;
}

