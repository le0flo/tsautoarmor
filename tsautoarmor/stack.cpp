#include "minecraft.h"

Stack::Stack(jobject in) : MCObject(in) {
}

jobject Stack::get_item() {
    jclass clazz = hook::env->GetObjectClass(cached);
    jmethodID method = hook::env->GetMethodID(clazz, "b", "()Lzw;");

    if (compare::null(this->cached) || method == nullptr) return nullptr;

    return hook::env->CallObjectMethod(this->cached, method);
}

std::string Stack::name() {
    jobject item = get_item();
    
    jclass clazz = hook::env->GetObjectClass(item);
    jmethodID method = hook::env->GetMethodID(clazz, "a", "()Ljava/lang/String;");
    
    if (compare::null(item) || method == nullptr) return nullptr;

    return hook::env->GetStringUTFChars((jstring) hook::env->CallObjectMethod(item, method), 0);
}

int Stack::damage() {
    jclass clazz = hook::env->GetObjectClass(cached);
    jmethodID method = hook::env->GetMethodID(clazz, "h", "()I");

    if (compare::null(this->cached) || method == nullptr) return -1;

    return (int) hook::env->CallIntMethod(this->cached, method);
}

int Stack::max_damage() {
    jclass clazz = hook::env->GetObjectClass(cached);
    jmethodID method = hook::env->GetMethodID(clazz, "j", "()I");

    if (compare::null(this->cached) || method == nullptr) return -1;

    return (int) hook::env->CallIntMethod(this->cached, method);
}

bool Stack::is_armor() {
    jobject item = get_item();

    if (compare::null(item)) return false;

    return hook::env->IsInstanceOf(item, classes::item_armor);
}

int Stack::get_armor_type() {
    jobject item = get_item();

    jclass clazz = hook::env->GetObjectClass(cached);
    jfieldID field = hook::env->GetFieldID(clazz, "b", "I");
    
    if (compare::null(item)) return -1;

    return (int) hook::env->GetIntField(item, field);
}