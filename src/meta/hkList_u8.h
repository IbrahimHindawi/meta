#pragma once
/* hkList_u8 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_u8.h"

structdef(hkList_u8) {
    hkNode_u8 *head;
    hkNode_u8 *tail;
};

hkList_u8 *hklist_u8_init() {
    hkList_u8 *list = malloc(sizeof(hkList_u8));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_u8_append(hkList_u8 *list, u8 data) {
    if (!list->head) {
        list->head = hknode_u8_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_u8_init(data);
        list->head->next = list->tail;
        return;
    }
    hkNode_u8 *temp = hknode_u8_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_u8_deinit(hkList_u8 **list) {
    free(*list);
    *list = null;
}

