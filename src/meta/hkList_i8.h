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

struct hkList_i8 *hklist_i8_init() {
    struct hkList_i8 *list = malloc(sizeof(struct hkList_i8));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_i8_append(struct hkList_i8 *list, i8 data) {
    if (!list->head) {
        list->head = hknode_i8_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_i8_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_i8 *temp = hknode_i8_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_i8_deinit(struct hkList_i8 **list) {
    free(*list);
    *list = null;
}

