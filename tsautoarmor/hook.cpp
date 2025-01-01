#include "hook.h"

bool hook::attach() {
    JNI_GetCreatedJavaVMs(&jvm, 1, NULL);

    if (jvm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_8) == JNI_EDETACHED) {
        jvm->AttachCurrentThreadAsDaemon(reinterpret_cast<void**>(&env), NULL);
        return true;
    }

    return false;
}

void hook::detach() {
    jvm->DetachCurrentThread();
}

bool compare::null(jobject obj) {
    return hook::env->IsSameObject(obj, NULL);
}

bool compare::instanceof(jobject obj, jclass clazz) {
    return hook::env->IsInstanceOf(obj ,clazz);
}