#pragma once
/* hkList_u8 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_u8.h"

struct hkList_u8 {
    struct hkNode_u8 *head;
    struct hkNode_u8 *tail;
};

struct hkList_u8 *hklist_u8_init() {
    struct hkList_u8 *list = malloc(sizeof(struct hkList_u8));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_u8_append(struct hkList_u8 *list, u8 data) {
    if (!list->head) {
        list->head = hknode_u8_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_u8_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_u8 *temp = hknode_u8_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_u8_deinit(struct hkList_u8 **list) {
    free(*list);
    *list = null;
}

