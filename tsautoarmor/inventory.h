#ifndef INVENTORY_H
#define INVENTORY_H

#include "stack.h"

class Inventory : public MCObject {
public:
    Inventory(jobjectArray in);

    int size();
    Stack* get(int slot);
    bool set(int slot, Stack* stack);
};

#endif