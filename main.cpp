#include "TXLib.h"
#include <cstdio>
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#define PI 3.14159265359

#include <stdio.h>
#include "clLine.h"
#include "clCircle.h"
#include "clNode.h"
#include "clLineWithWeight.h"
#include "clGraph.h"
#include <math.h>

using namespace std;
int main(){
    int gd = CUSTOM;
    int gm = CUSTOM_MODE(600,600);
    initgraph(&gd, &gm,"");
    clGraph graph;
    graph.Show();
    readkey();
    graph.Boruvka();
    initgraph(&gd, &gm,"");
    graph.Show();
    readkey();
    closegraph();
    return 0;
}





















