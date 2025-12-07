#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include "Input.h"
class AbstractController{
public:
    virtual Input move() = 0; 
};

#endif // ABSTRACTCONTROLLER_H


