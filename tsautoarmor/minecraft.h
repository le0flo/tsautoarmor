#ifndef MINECRAFT_H
#define MINECRAFT_H

#include "player.h"

class Minecraft : public MCObject {
public:
    Minecraft(jobject in);

    static Minecraft* get_minecraft();
    Player* get_local_player();
};

#endif