#ifndef CONTAINER_H
#define CONTAINER_H

#include "object.h"

class Container : public MCObject {
public:
    Container(jobject in);

    bool detect_send_changes();
};

#endif