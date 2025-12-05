#ifndef ACTIVE_H
#define ACTIVE_H
#include "Passive.h"
#include <vector>

class Active {
private:
    std::vector<Passive*> passives;

public:
    Active() = default;
    virtual ~Active() = default;

    void attach(Passive* p);
    void detach(Passive* p);
    void activate();
};
#endif // ACTIVE_H
