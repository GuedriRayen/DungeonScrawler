#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H
#include "level.h"
#include "Input.h"
class AbstractView{
public:
    virtual void draw(Level* level) = 0;
    virtual Input move() = 0;
    virtual ~AbstractView() = default;
};

#endif // ABSTRACTVIEW_H
