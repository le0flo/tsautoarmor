#include "classes.h"

void classes::load() {
    minecraft = hook::env->FindClass("ave");
    item_armor = hook::env->FindClass("yj");
}