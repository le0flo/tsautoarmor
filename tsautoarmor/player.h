#ifndef PLAYER_H
#define PLAYER_H

#include "inventory_player.h"
#include "container.h"

class Player : public MCObject {
public:
    Player(jobject in);

    InventoryPlayer* get_inventory_player();
    Container* get_container();
};

#endif