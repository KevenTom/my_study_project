#include "calc.h"
using namespace std;

int main()
{
    Calc cal(10);
    cal.add(15).mult(2).sub(5).print();

    return 0;
}