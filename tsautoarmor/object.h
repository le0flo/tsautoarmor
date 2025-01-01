#ifndef OBJECT_H
#define OBJECT_H

#include "hook.h"
#include "classes.h"

class MCObject {
public:
    jobject cached;
    jobjectArray cached_array;

    MCObject(jobject in);
    MCObject(jobjectArray in);
    ~MCObject();
};

#define MCOBject_INSTANCIATE(ptr, val) if (ptr != nullptr) free(ptr);\
        ptr = val;\
        if (compare::null(ptr->cached) && compare::null(ptr->cached_array)) continue;

#endif