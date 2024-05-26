#pragma once
/* hkList_i16 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_i16.h"

struct hkList_i16 {
    struct hkNode_i16 *head;
    struct hkNode_i16 *tail;
};

struct hkList_i16 *hklist_i16_init() {
    struct hkList_i16 *list = malloc(sizeof(struct hkList_i16));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_i16_append(struct hkList_i16 *list, i16 data) {
    if (!list->head) {
        list->head = hknode_i16_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_i16_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_i16 *temp = hknode_i16_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_i16_deinit(struct hkList_i16 **list) {
    free(*list);
    *list = null;
}

