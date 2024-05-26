#pragma once
/* hkList_i8 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_i8.h"

structdef(hkList_i8) {
    hkNode_i8 *head;
    hkNode_i8 *tail;
};

hkList_i8 *hklist_i8_init() {
    hkList_i8 *list = malloc(sizeof(hkList_i8));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_i8_append(hkList_i8 *list, i8 data) {
    if (!list->head) {
        list->head = hknode_i8_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_i8_init(data);
        list->head->next = list->tail;
        return;
    }
    hkNode_i8 *temp = hknode_i8_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_i8_deinit(hkList_i8 **list) {
    free(*list);
    *list = null;
}

