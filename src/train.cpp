// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :countOp(-1), first(nullptr), last(nullptr) {}

void Train::addCage(bool light) {
    if (!first) {
        Cage* newCage = new Cage;
        newCage->light = 0;
        newCage->next = newCage->prev = nullptr;
        first = newCage;
        last = first;
    }
    else {
        Cage* newCage = new Cage;
        newCage->light = light;
        newCage->next = last;
        newCage->prev = first;
        first->next = newCage;
        last->prev = newCage;
        last = newCage;
    }
}

int Train::getLength() {
    Cage* cur = first;
    cur->light = 1;
    int countTemp = 0;
    countOp = 0;
    while (cur) {
        cur = cur->next;
        countOp++;
        countTemp++;
        if (cur->light) {
            cur->light = 0;
            for (int i = countTemp; i > 0; i--) {
                cur = cur->prev;
                countOp++;
            }
            if (!cur->light) return countTemp;
            countTemp = 0;
        }
    }
}

int Train::getOpCount() {
    if (countOp == -1) getLength();
    return countOp;
}
