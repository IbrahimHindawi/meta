#pragma once
/* hkList_i8 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_i8.h"

struct hkList_i8 {
    struct hkNode_i8 *head;
    struct hkNode_i8 *tail;
};

struct hkList_i8 *hkList_i8_init() {
    struct hkList_i8 *list = malloc(sizeof(struct hkList_i8));
    list->head = null;
    list->tail = null;
    return list;
}

void hkList_i8_append(struct hkList_i8 *list, i8 data) {
    if (!list->head) {
        list->head = hkNode_i8_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hkNode_i8_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_i8 *temp = hkNode_i8_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hkList_i8_deinit(struct hkList_i8 **list) {
    free(*list);
    *list = null;
}

