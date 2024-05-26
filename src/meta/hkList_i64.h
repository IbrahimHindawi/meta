#pragma once
/* hkList_i64 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_i64.h"

struct hkList_i64 {
    struct hkNode_i64 *head;
    struct hkNode_i64 *tail;
};

struct hkList_i64 *hklist_i64_init() {
    struct hkList_i64 *list = malloc(sizeof(struct hkList_i64));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_i64_append(struct hkList_i64 *list, i64 data) {
    if (!list->head) {
        list->head = hknode_i64_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_i64_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_i64 *temp = hknode_i64_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_i64_deinit(struct hkList_i64 **list) {
    free(*list);
    *list = null;
}

