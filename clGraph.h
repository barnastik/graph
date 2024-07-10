/*#ifndef CLGRAPH_H_INCLUDED
#define CLGRAPH_H_INCLUDED
#include <vector>
#include "clDraw.h"
#include "clNode.h"
#include "clLine.h"

class clGraph : public clDraw
{
    public:
        clGraph(int *ar, int size);
        virtual ~clGraph();

        int Getn() { return n; }
        void Setn(int val) { n = val; }
        //int* Getmatr() { return matr; }
        //void Setmatr(int* val) { matr = val; }
        void Show() const;
        void AddNode(int x, int y, int num);
        void AddLine(int x1, int y1, int x2, int y2);
        //int* Boruvka(int st);
        //void paint(int* ar);
        //void paint (vector < pair<int,int> >)

    protected:

    private:
        int n;
        int* matrix;
        std::vector<clNode*> nodes;
        std::vector<clLine> lines;

};


#endif // CLGRAPH_H_INCLUDED
*/

#ifndef CLGRAPH_H
#define CLGRAPH_H
#include "clNode.h"
#include "clLineWithWeight.h"
#include "clDraw.h"
#include <math.h>

class clGraph : public clDraw
{
    public:
        clGraph();
        virtual ~clGraph();
        void Show();
        void tran(int mat_c[][N], int rang);
        void Boruvka();

    private:
        int matr[N][N] = {
        {0, 0, 2, 8, 1, 10, 0},
        {0, 0, 0, 4, 0, 1, 0},
        {2, 0, 0, 1, 0, 0, 0},
        {8, 4, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 1},
        {10, 1, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 1, 2, 0}
    };
        clNode *arr_node;
        int mat_r[N][N];
        int mat_c[N][N];
        //clLineWithWeight *edge;
};


#endif // CLGRAPH_H_INCLUDED
