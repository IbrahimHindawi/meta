#pragma once
/* hkList_i32 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_i32.h"

struct hkList_i32 {
    struct hkNode_i32 *head;
    struct hkNode_i32 *tail;
};

struct hkList_i32 *hklist_i32_init() {
    struct hkList_i32 *list = malloc(sizeof(struct hkList_i32));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_i32_append(struct hkList_i32 *list, i32 data) {
    if (!list->head) {
        list->head = hknode_i32_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_i32_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_i32 *temp = hknode_i32_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_i32_deinit(struct hkList_i32 **list) {
    free(*list);
    *list = null;
}

