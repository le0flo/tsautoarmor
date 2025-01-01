#include "minecraft.h"

Inventory::Inventory(jobjectArray in) : MCObject(in) {
}

int Inventory::size() {
    if (compare::null(this->cached_array)) return -1;

    return (int) hook::env->GetArrayLength(this->cached_array);
}

Stack* Inventory::get(int slot) {
    if (compare::null(this->cached_array)) return nullptr;

    return new Stack(hook::env->GetObjectArrayElement(this->cached_array, slot));
}

bool Inventory::set(int slot, Stack* stack) {
    if (compare::null(this->cached_array) || compare::null(stack->cached)) return false;

    hook::env->SetObjectArrayElement(this->cached_array, slot, stack->cached);
    return true;
}