#ifndef CLNODE_H
#define CLNODE_H
#include "clCircle.h"
class clNode : public clCircle
{
    public:
        clNode();
        clNode(int x0, int y0, int num0);
        virtual ~clNode();
        char *Getnum() { return num; }
        void Setnum(int val) { itoa(val,num,10); }
        void Show();
    private:
        char *num;
};
#endif // CLNODE_H
