#ifndef CLLINEWITHWEIGHT_H_INCLUDED
#define CLLINEWITHWEIGHT_H_INCLUDED
#include "clLine.h"

class clLineWithWeight : public clLine
{
    public:
        clLineWithWeight();
        clLineWithWeight(int x01, int y01, int x02, int y02, int weight0);
        virtual ~clLineWithWeight();

        char *Getweight() { return weight; }
        void Setweight(int val) { itoa(val, weight,10); }
        void Show();

    private:
        char *weight;
};
#endif // CLLINEWITHWEIGHT_H_INCLUDED
