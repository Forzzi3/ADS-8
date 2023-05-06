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
    } else {
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
    Cage* temp = first;
    temp->light = 1;
    int countTemp = 1;
    countOp = 0;
    while (temp) {
        temp = temp->next;
        if (!temp->light) {
            countOp++;
            countTemp++;
        } else {
            countOp++;
            temp->light = false;
            for (int i = countTemp; i > 0; i--) {
                temp = temp->prev;
                countOp++;
            }
            if (!temp->light) {
                return countTemp;
            }
            countTemp = 1;
        }
    }
    return -1;
}

int Train::getOpCount() {
    if (countOp == -1) getLength();
    return countOp;
}
