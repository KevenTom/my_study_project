#include "calc.h"
using namespace std;

Calc::Calc(int in_v)
    : m_v(in_v)
{}

Calc& Calc::add(int value)
{
    m_v += value;
    return *this;
}

Calc& Calc::sub(int value)
{
    m_v -= value;
    return *this;
}

Calc& Calc::mult(int value)
{
    m_v *= value;
    return *this;
}

Calc& Calc::print()
{
    cout << m_v << endl;
    return *this;
}
