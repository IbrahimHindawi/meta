#pragma once
/* hkList_f32 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_f32.h"

structdef(hkList_f32) {
    hkNode_f32 *head;
    hkNode_f32 *tail;
};

hkList_f32 *hklist_f32_init() {
    hkList_f32 *list = malloc(sizeof(hkList_f32));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_f32_append(hkList_f32 *list, f32 data) {
    if (!list->head) {
        list->head = hknode_f32_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_f32_init(data);
        list->head->next = list->tail;
        return;
    }
    hkNode_f32 *temp = hknode_f32_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_f32_deinit(hkList_f32 **list) {
    free(*list);
    *list = null;
}

