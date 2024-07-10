#ifndef CLDRAW_H
#define CLDRAW_H
#define N 7
#include <cstdlib>
#include <iostream>
#include <graphics.h>
#include <conio.h>
#define N 7
#define PI 3.14
#include <math.h>

using namespace std;

class clDraw
{
    public:
        virtual void Show()=0;
};
#endif // CLDRAW_H
