#include "steelbarcutting.h"

SteelBarCutting::SteelBarCutting()
{
    ifstream ifs;
    ifs.open("/home/jeremy/CPPproject/Algorithms/Dpproble/1");
    string sTemp;
    stringstream ssTemp;
    int iTempA;
    int iTempB;
    while(getline(ifs, sTemp))
    {
        ssTemp << sTemp;
        ssTemp >> iTempA >> iTempB;
        dataBest.push_back(LengthValue(iTempA, 0, iTempB));
        sTemp.clear();
        ssTemp.clear();
    }
    ifs.close();
    firstStep();
}
SteelBarCutting::SteelBarCutting(string &filename)
{
    ifstream ifs;
    ifs.open(filename);
    string sTemp;
    stringstream ssTemp;
    int iTempA;
    int iTempB;
    while(getline(ifs, sTemp))
    {
        ssTemp << sTemp;
        ssTemp >> iTempA >> iTempB;
        dataBest.push_back(LengthValue(iTempA, 0, iTempB));
        sTemp.clear();
        ssTemp.clear();
    }
    ifs.close();
    firstStep();
}

SteelBarCutting::SteelBarCutting(vector<LengthValue>& data)
{
    dataBest = data;
    firstStep();
}
void SteelBarCutting:: firstStep()
{
    vector<LengthValue> temp;
    for(int i = 1; i <= dataBest.size(); i++)
    {
        temp.push_back(dataBest[i  - 1]);
        for(int j = 1; j <= i / 2; j++)
        {
            temp.push_back(LengthValue(i - j, j , dataBest[i - j - 1].totalValue + dataBest[j - 1].totalValue));

        }
        vector<LengthValue>::iterator it = max_element(temp.begin(), temp.end(), cmp);
        if(it->totalValue == dataBest[i - 1].totalValue)
            continue;
        dataBest[i - 1] = *it;
    }
}

void SteelBarCutting::show()
{
    vector<LengthValue>::iterator ite = dataBest.begin();
    while(ite != dataBest.end())
    {

        cout << ite->leftLength << '\t' << ite->rightLength << '\t' << ite->totalValue << endl;
        ite++;
    }
}

const vector<LengthValue>& SteelBarCutting::getBest(int length)
{
    if(length <= dataBest.size())
    {
        return dataBest;
    }

    vector<LengthValue> temp;
    for(int i = dataBest.size() + 1  ; i <= length; i++)
    {
        for(int j = 1; j <= i / 2; j++)
        {
            temp.push_back(LengthValue(i - j, j , dataBest[i - j - 1].totalValue + dataBest[j - 1].totalValue));
        }
        vector<LengthValue>::iterator it = max_element(temp.begin(), temp.end(), cmp);
        if(it->totalValue == dataBest[i - 1].totalValue)
            continue;
        dataBest.push_back(*it);
    }


    return dataBest;
}


bool cmp(LengthValue& a, LengthValue& b)
{
    if(a.totalValue <= b.totalValue)
        return true;
    return false;
}

