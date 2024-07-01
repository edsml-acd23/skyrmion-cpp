#ifndef DRIVER_H
#define DRIVER_H

#include "system.h"

class Driver{
public:
    Driver();

    void drive(System system, int n, float alpha);
};

#endif