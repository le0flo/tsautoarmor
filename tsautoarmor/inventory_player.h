#ifndef INV_PLAYER_H
#define INV_PLAYER_H

#include "inventory.h"

class InventoryPlayer : public MCObject {
public:
    InventoryPlayer(jobject in);

    Inventory* get_main();
    Inventory* get_armor();

    bool set_slot_content(int slot, Stack* stack);
};

#endif