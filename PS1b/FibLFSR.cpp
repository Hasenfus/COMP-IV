// Hunter M Hasenfus
// Computing IV
// Prof. Rykalova
//
//


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include "FibLFSR.h"

using namespace std;


// int main(int arg, char* argv[])
// {
//     string test = "1011011000110110";
//     FibLFSR tes(test);
//     tes.generate(5);
//     return 0;
// }

#define PRINT 0
FibLFSR::FibLFSR(string seed)
{
    this->registers = vector<int>(seed.size());
    for(long unsigned int i = 0; i < seed.size(); i++)
    {
        this->registers[i] = seed[i]-48;
    }
}

int FibLFSR::step()
{
    int x = this->registers[0];
    for(long unsigned int i = 0; i < this->tapPositions.size(); i++)
    {
        x = this->registers[this->tapPositions[i]] ^ x;
    }
    for(long unsigned int i = 0; i < this->registers.size()-1; i++)
    {
        this->registers[i] = this->registers[i+1];
    }
    this->registers[this->registers.size()-1] = x;
    
    return x;
}

int FibLFSR::generate(int k)
{
    int x= 0, y;
    for(int i = 0; i < k; i++)
    {
	    y = this->step();
        x+= y * pow(2,k-1-i);
    }
    if(PRINT)
    {
        for(long unsigned int j = 0; j < this->registers.size(); j++)
        {
            cout << this->registers[j];
        }
        cout << " " << x << endl;
    }

    return x;
}
