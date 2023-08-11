#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <string>
#include <vector>
using namespace std;


class FibLFSR {
public:
    FibLFSR(string seed);
    int step();
    int generate(int k);

private:
    vector<int> registers;
    vector<int> tapPositions = {2,3,5};
};



#endif
