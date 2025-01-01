#include "object.h"

MCObject::MCObject(jobject in) {
    this->cached = in;
    this->cached_array = nullptr;
}

MCObject::MCObject(jobjectArray in) {
    this->cached = nullptr;
    this->cached_array = in;
}

MCObject::~MCObject() {
    if (this->cached != nullptr) {
        hook::env->DeleteLocalRef(this->cached);
    }

    if (this->cached_array != nullptr) {
        hook::env->DeleteLocalRef(this->cached_array);
    }
}