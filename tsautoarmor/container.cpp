#include "minecraft.h"

Container::Container(jobject in) : MCObject(in) {
}

bool Container::detect_send_changes() {
    jclass clazz = hook::env->GetObjectClass(cached);
    jmethodID method = hook::env->GetMethodID(clazz, "b", "()V");

    if (compare::null(this->cached) || method == nullptr) return false;

    hook::env->CallVoidMethod(this->cached, method);
    return true;
}