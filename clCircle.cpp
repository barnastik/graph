#include "clCircle.h"

void clCircle::Show()
{
    circle(x,y,r);
}

clCircle::clCircle()
{
    cout << "clCircle();\n";
}
clCircle::clCircle(int x0, int y0) : x(x0), y(y0)
{
    cout << x << " clCircle(int x0, int y0);\n";
}
clCircle::~clCircle()
{
    cout << x << " ~clCircle();\n";
}
