#include "clNode.h"

void clNode::Show()
{
    const char *nums[10];
    nums[0] = "A"; nums[1] = "B"; nums[2] = "C"; nums[3] = "D"; nums[4] = "E";
    nums[5] = "F"; nums[6] = "G"; nums[7] = "H"; nums[8] = "I"; nums[9] = "J";
    clCircle::Show();
    int number = std::stoi(num)-1;
    outtextxy(Getx() - 5, Gety() - 10, nums[number]);
    //outtextxy(Getx(), Gety(), num);
}

clNode::clNode(): num(new char[4])
{
    cout << "clNode();\n";
}

clNode::clNode(int x0, int y0, int num0) : clCircle(x0,y0), num(new char[4])
{
    Setnum(num0);
    cout << Getx() << " clNode(int x0, int y0, int num0);\n";
}
clNode::~clNode()
{
    delete [] num; //освободить память
    cout << Getx() << " ~clNode();\n";
}

