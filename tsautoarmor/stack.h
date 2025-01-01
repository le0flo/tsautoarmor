#ifndef STACK_H
#define STACK_H

#include "object.h"

class Stack : public MCObject {
private:
    jobject get_item();

public:
    Stack(jobject in);

    std::string name();
    int damage();
    int max_damage();
    
    bool is_armor();
    int get_armor_type();
};

#endif