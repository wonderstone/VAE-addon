#include "assessment.hpp"
using namespace std;

// AlgoManager constructor
AlgoManager::AlgoManager(std::map<std::string, AlgoStruct *> algoMap)
{
    AlgoMap = algoMap;
}

//
// AlgoManager::assessAlgo(): rewrite when apply to real algos
double AlgoManager::assessAlgo(std::string algoID)
{
    // ! deliberately return 0.0 for NOW!
    return 0.0;
}

// AlgoManager::assessAlgos(): rewrite when apply to real algos
std::map<std::string, double> AlgoManager::assessAlgos()
{
    std::map<std::string, double> algoAssessMap;
    for (auto it = AlgoMap.begin(); it != AlgoMap.end(); it++)
    {
        // ! may not need to use the assessAlgo() function
        // ! do anything you want to assess the algo
        algoAssessMap[it->first] = assessAlgo(it->first);
    }
    return algoAssessMap;
}

// AlgoManager::delegateAlgoNums(): rewrite when apply to real algos
std::map<std::string, int> AlgoManager::delegateAlgoNums(int totalNum)
{
    std::map<std::string, int> algoNumsMap;
    // ! delegate the totalNum to the algos and consider the remain
    int numAlgo = AlgoMap.size();
    int numPerAlgo = totalNum / numAlgo;
    int numRemain = totalNum % numAlgo;
    for (auto it = AlgoMap.begin(); it != AlgoMap.end(); it++)
    {
        // ! anything you want to do to delegate the numPerAlgo
        algoNumsMap[it->first] = numPerAlgo;
    }
    // ! add the remain to the first algo
    algoNumsMap[AlgoMap.begin()->first] += numRemain;

    return algoNumsMap;
}