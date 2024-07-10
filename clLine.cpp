#include "clLine.h"

void clLine::Show()
{
    //cos_t = (arr_node[j].Getx() - arr_node[i].Getx()) / sqrt(pow(arr_node[j].Getx() - arr_node[i].Getx(), 2) + pow(arr_node[j].Gety() - arr_node[i].Gety(), 2));
    //sin_t = (arr_node[j].Gety() - arr_node[i].Gety()) / sqrt(pow(arr_node[j].Getx() - arr_node[i].Getx(), 2) + pow(arr_node[j].Gety() - arr_node[i].Gety(), 2));
    //line(arr_node[i].Getx() + 35 * cos_t, arr_node[i].Gety() + 35 * sin_t, arr_node[j].Getx() - 35 * cos_t, arr_node[j].Gety() - 35 * sin_t);
    line(x1, y1, x2, y2);
}
clLine::clLine()
{
    //ctor empty
}
clLine::clLine(int x01, int y01, int x02, int y02): x1(x01), y1(y01), x2(x02), y2(y02) //Ќ≈полный конструктор
{

}
clLine::~clLine()
{
    //dtor empty
}
