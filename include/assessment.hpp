#ifndef ASS_COMPONENT_H
#define ASS_COMPONENT_H
#include <string>
#include <map>
#include "vector"

struct TimeStampBP
{
    std::string TimeStamp; // 时间标签
    double BP;             // 订单执行价(母单)基差
};

struct AssStruct
{
    // 算法评估信息：构成来自VAE吴佳凡
    double WithdrawRate;   // 撤单率
    bool IfCompliance;     // 合规性
    double Volatility;     // 波动率
    double Achievements;   // 绩效
    double CompletionRate; // 完成度
};

// define a class for Algo class
class AlgoStruct
{
    // 算法基础信息：用以唯一确定算法实例和确认信息更新时间
private:
    std::string AlgoID;
    std::string UpdateTimeStamp;
    // all maps with target as key
    // use maps to store NumAlloc and NumExecMap 分配额度
    std::map<std::string, int> NumAllocMap;
    std::map<std::string, int> NumExecMap;
    // panel: use a map to store target related assStruct
    std::map<std::string, AssStruct> AssMap;

public:
    AlgoStruct(std::string algoID);
    // timeseries: use a map to store target related vector of double bp
    std::map<std::string, std::vector<TimeStampBP>> BpMap;
    // get functions for AlgoID and UpdateTimeStamp
    std::string getAlgoID();
    std::string getUpdateTimeStamp();
    // get functions for NumAllocMap , NumExecMap and AssMap
    int getNumAlloc(std::string targetID);
    int getNumExec(std::string targetID);
    AssStruct getAssStruct(std::string targetID);
    // get all targets
    std::vector<std::string> getTargets();

    // set functions for UpdateTimeStamp
    void setUpdateTimeStamp(std::string timeStamp);
    // set functions for NumAllocMap , NumExecMap and AssMap
    void setNumAlloc(std::string targetID, int numAlloc);
    void setNumExec(std::string targetID, int numExec);
    void setAssStruct(std::string targetID, AssStruct assStruct);
    // add a new target to all maps
    void addTarget(std::string targetID);
};

class AlgoManager
{
public:
    AlgoManager(std::map<std::string, AlgoStruct *>);
    // map with AlgoID as key and AlgoStruct pointer as value
    std::map<std::string, AlgoStruct *> AlgoMap;
    // function to assessalgo
    double assessAlgo(std::string algoID);
    std::map<std::string, double> assessAlgos();
    // function to delegate algo nums with map<string,int> output
    std::map<std::string, int> delegateAlgoNums(int totalNum);
};

#endif