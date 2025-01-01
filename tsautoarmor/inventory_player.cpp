#include "minecraft.h"

InventoryPlayer::InventoryPlayer(jobject in) : MCObject(in) {
}

Inventory* InventoryPlayer::get_main() {
    jclass clazz = hook::env->GetObjectClass(this->cached);
    jfieldID field = hook::env->GetFieldID(clazz, "a", "[Lzx;");

    if (compare::null(this->cached)) return nullptr;

    return new Inventory((jobjectArray) hook::env->GetObjectField(this->cached, field));
}

Inventory* InventoryPlayer::get_armor() {
    jclass clazz = hook::env->GetObjectClass(this->cached);
    jfieldID field = hook::env->GetFieldID(clazz, "b", "[Lzx;");

    if (compare::null(this->cached)) return nullptr;

    return new Inventory((jobjectArray) hook::env->GetObjectField(this->cached, field));
}

bool InventoryPlayer::set_slot_content(int slot, Stack* stack) {
    jclass clazz = hook::env->GetObjectClass(this->cached);
    jmethodID method = hook::env->GetMethodID(clazz, "a", "(ILzx;)V");
    
    if (compare::null(this->cached) || method == nullptr) return false;

    hook::env->CallVoidMethod(this->cached, method, slot, stack->cached);
    return true;
}