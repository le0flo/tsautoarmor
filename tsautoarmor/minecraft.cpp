#include "minecraft.h"

Minecraft::Minecraft(jobject in) : MCObject(in) {
}

Minecraft* Minecraft::get_minecraft() {
    jmethodID method = hook::env->GetStaticMethodID(classes::minecraft, "A", "()Lave;");

    if (method == nullptr) return nullptr;

    return new Minecraft(hook::env->CallStaticObjectMethod(classes::minecraft, method));
}

Player* Minecraft::get_local_player() {
    jclass clazz = hook::env->GetObjectClass(this->cached);
    jfieldID field = hook::env->GetFieldID(clazz, "h", "Lbew;");

    if (compare::null(this->cached)) return nullptr;

    return new Player(hook::env->GetObjectField(this->cached, field));
}