#pragma once
/* hkList_f64 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_f64.h"

struct hkList_f64 {
    struct hkNode_f64 *head;
    struct hkNode_f64 *tail;
};

struct hkList_f64 *hkList_f64_init() {
    struct hkList_f64 *list = malloc(sizeof(struct hkList_f64));
    list->head = null;
    list->tail = null;
    return list;
}

void hkList_f64_append(struct hkList_f64 *list, f64 data) {
    if (!list->head) {
        list->head = hkNode_f64_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hkNode_f64_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_f64 *temp = hkNode_f64_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hkList_f64_deinit(struct hkList_f64 **list) {
    free(*list);
    *list = null;
}
