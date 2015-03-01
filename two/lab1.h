/*
    Created by Sercan Değirmenci on 01.03.2015
*/

#pragma once

#include <iostream>

namespace sercand {

static const int A3 = 6;

static const int A2 = 13;

static const int A1 = 19;

static const int A0 = 26;

class Lab1 {

public:
    Lab1();

    ~Lab1();

    void output(int num);

    void delayMs(unsigned int t);

private:
    void initPins();
};

}