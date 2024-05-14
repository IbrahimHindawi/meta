#pragma once
/* hkList_u16 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_u16.h"

struct hkList_u16 {
    struct hkNode_u16 *head;
    struct hkNode_u16 *tail;
};

struct hkList_u16 *hkList_u16_init() {
    struct hkList_u16 *list = malloc(sizeof(struct hkList_u16));
    list->head = null;
    list->tail = null;
    return list;
}

void hkList_u16_append(struct hkList_u16 *list, u16 data) {
    if (!list->head) {
        list->head = hkNode_u16_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hkNode_u16_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_u16 *temp = hkNode_u16_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hkList_u16_deinit(struct hkList_u16 **list) {
    free(*list);
    *list = null;
}
