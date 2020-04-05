#ifndef STEELBARCUTTING_H
#define STEELBARCUTTING_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct LengthValue
{
    int leftLength;
    int rightLength;
    int totalValue;
    LengthValue()
    {leftLength = 0; rightLength = 0; totalValue = 0;}
    LengthValue(int left, int right, int value)
    {
        leftLength = left;
        rightLength = right;
        totalValue = value;
    }
};

bool cmp(LengthValue& a, LengthValue& b);


class SteelBarCutting
{
private:
    vector<LengthValue> dataBest;
    void firstStep();
public:
    SteelBarCutting();
    SteelBarCutting(string& filename);
    SteelBarCutting(vector<LengthValue>& data);
    const vector<LengthValue>&  getBest(int length);
    void show();
};

#endif // STEELBARCUTTING_H
