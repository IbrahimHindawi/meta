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

struct hkList_i16 *hkList_i16_init() {
    struct hkList_i16 *list = malloc(sizeof(struct hkList_i16));
    list->head = null;
    list->tail = null;
    return list;
}

void hkList_i16_append(struct hkList_i16 *list, i16 data) {
    if (!list->head) {
        list->head = hkNode_i16_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hkNode_i16_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_i16 *temp = hkNode_i16_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hkList_i16_deinit(struct hkList_i16 **list) {
    free(*list);
    *list = null;
}

