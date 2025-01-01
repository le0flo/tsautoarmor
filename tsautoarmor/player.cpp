#include "minecraft.h"

Player::Player(jobject in) : MCObject(in) {
}

InventoryPlayer* Player::get_inventory_player() {
    jclass clazz = hook::env->GetObjectClass(this->cached);
    jfieldID field = hook::env->GetFieldID(clazz, "bi", "Lwm;");

    if (compare::null(this->cached)) return nullptr;

    return new InventoryPlayer(hook::env->GetObjectField(this->cached, field));
}

Container* Player::get_container() {
    jclass clazz = hook::env->GetObjectClass(this->cached);
    jfieldID field = hook::env->GetFieldID(clazz, "bj", "Lxi;");

    if (compare::null(this->cached)) return nullptr;

    return new Container(hook::env->GetObjectField(this->cached, field));
}