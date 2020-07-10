#pragma once
#include <iostream>

class Calc
{
private:
    int m_v;
public:
    Calc(int in_v);
    Calc& add(int value);
    Calc& sub(int value);
    Calc& mult(int value);
    Calc& print();
};