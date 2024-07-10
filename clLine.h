#ifndef CLLINE_H
#define CLLINE_H

#include "clDraw.h"

class clLine : public clDraw
{
    public:
        clLine();
        clLine(int x01, int y01, int x02, int y02);
        virtual ~clLine();

        int Getx1() { return x1; }
        void Setx1(int val) { x1 = val; }
        int Getx2() { return x2; }
        void Setx2(int val) { x2 = val; }
        int Gety1() { return y1; }
        void Sety1(int val) { y1 = val; }
        int Gety2() { return y2; }
        void Sety2(int val) { y2 = val; }
        void Show();
    private:
        int x1;
        int x2;
        int y1;
        int y2;
};

#endif // CLLINE_H

