#include "clLineWithWeight.h"
#include "clLine.h"
void clLineWithWeight::Show()
{
    clLine::Show();
    setcolor(15);
    outtextxy((Getx1()+Getx2())/2, (Gety1()+Gety2())/2, weight);
}
clLineWithWeight::clLineWithWeight(): weight(new char[4])
{
    //ctor
}
clLineWithWeight::clLineWithWeight(int x01, int y01, int x02, int y02, int weight0): clLine(x01,y01,x02,y02), weight(new char[4])

{
    Setweight(weight0);
}
clLineWithWeight::~clLineWithWeight()
{
    delete [] weight;
}
