#ifndef HOOK_H
#define HOOK_H

#define MODE_DEBUG

#include <iostream>
#include <thread>
#include <windows.h>
#include <jni.h>

namespace hook {
    inline JavaVM* jvm = nullptr;
    inline JNIEnv* env = nullptr;

    bool attach();
    void detach();
};

namespace compare {
    bool null(jobject obj);
    bool instanceof(jobject obj, jclass clazz);
}

#endif