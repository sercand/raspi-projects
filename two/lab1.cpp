/*
    Created by Sercan Değirmenci on 01.03.2015
*/
#include "lab1.h"

#if __APPLE__

#include "dev/wiringPi.h"

#else
    #include <wiringPi.h>
#endif


namespace sercand {


Lab1::Lab1() {
    wiringPiSetupGpio();
    initPins();
}

Lab1::~Lab1() {

}

void Lab1::initPins() {
    pinMode(A3, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A0, OUTPUT);
}

void Lab1::output(int num) {
    auto a3 = num >> 3 & 1;
    auto a2 = num >> 2 & 1;
    auto a1 = num >> 1 & 1;
    auto a0 = num >> 0 & 1;

    std::cout << a3 << a2 << a1 << a0 << std::endl;

    digitalWrite(A3, a3);
    digitalWrite(A2, a2);
    digitalWrite(A1, a1);
    digitalWrite(A0, a0);
}

void Lab1::delayMs(unsigned int t) {
    delay(t);
}
} // namespace sercand