#include "assessment.hpp"
using namespace std;

// define construct function:
AlgoStruct::AlgoStruct( string algoID)
{
    AlgoID = algoID;
}
// define get function:
string AlgoStruct::getAlgoID()
{
    return AlgoID;
}
string AlgoStruct::getUpdateTimeStamp()
{
    return UpdateTimeStamp;
}

int AlgoStruct::getNumAlloc(string targetID)
{
    return NumAllocMap[targetID];
}

int AlgoStruct::getNumExec(string targetID)
{
    return NumExecMap[targetID];
}

AssStruct AlgoStruct::getAssStruct(string targetID)
{
    return AssMap[targetID];
}

vector<string> AlgoStruct::getTargets()
{
    vector<string> targets;
    for (auto it = AssMap.begin(); it != AssMap.end(); it++)
    {
        targets.push_back(it->first);
    }
    return targets;
}
// define set function:
void AlgoStruct::setUpdateTimeStamp(string timeStamp)
{
    UpdateTimeStamp = timeStamp;
}

void AlgoStruct::setNumAlloc(string targetID, int numAlloc)
{
    NumAllocMap[targetID] = numAlloc;// 利用数组覆盖的方式更新NumAllocMap
}

void AlgoStruct::setNumExec(string targetID, int numExec)
{
    NumExecMap[targetID] = numExec; // 利用数组覆盖的方式更新NumExecMap
}

void AlgoStruct::setAssStruct(string targetID, AssStruct assStruct)
{
    AssMap[targetID] = assStruct; // 利用数组覆盖的方式更新AssMap
}

void AlgoStruct::addTarget(string targetID)
{
    // add a new target to all maps and set the default value
    NumAllocMap[targetID] = 0;
    NumExecMap[targetID] = 0;
    AssMap[targetID] = {};
    BpMap[targetID] = {};

}



