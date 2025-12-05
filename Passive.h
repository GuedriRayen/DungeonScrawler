#ifndef PASSIVE_H
#define PASSIVE_H
class Active;


class Passive {
public:
    Passive() = default;
    virtual ~Passive() = default;
    virtual void notify() = 0;
};

#endif // PASSIVE_H
