#include <iostream>
#include "algoStruct.cpp"

int main()
{
    // Create an object of class AssStruct
    AssStruct assComponent = {1.0,true,0.3,0.2,0.8};
    // create an object of time stamp bp
    TimeStampBP tsbp = {"2020-01-01 00:00:00",0.1};
    // create an object of vector of time stamp bp
    vector<TimeStampBP> tsbpVec;
    tsbpVec.push_back(tsbp);
    // create an object of AlgoStruct
    AlgoStruct algoComponent = AlgoStruct("AlgoID001");
    // set the update time stamp
    algoComponent.setUpdateTimeStamp("2020-01-01 00:00:00");
    // set the numAlloc
    algoComponent.setNumAlloc("600010.sh",10000);
    // set the numExec
    algoComponent.setNumExec("600010.sh",1000);
    // set the assStruct
    algoComponent.setAssStruct("600010.sh",assComponent);
    // set the bpMap
    algoComponent.BpMap["600010.sh"] = tsbpVec;
    // get the numAlloc
    cout << "algoComponent.getNumAlloc(\"600010.sh\") = " << algoComponent.getNumAlloc("600010.sh") << endl;
    // get the numExec
    cout << "algoComponent.getNumExec(\"600010.sh\") = " << algoComponent.getNumExec("600010.sh") << endl;
    // get the assStruct
    cout << "algoComponent.getAssStruct(\"600010.sh\").CompletionRate = " << algoComponent.getAssStruct("600010.sh").CompletionRate << endl;
    // get the bpMap
    cout << "algoComponent.BpMap[\"600010.sh\"][0].bp = " << algoComponent.BpMap["600010.sh"][0].BP << endl;
    // get the targets
    vector<string> targets = algoComponent.getTargets();
    for (int i = 0; i < targets.size(); i++)
    {
        cout << "targets[" << i << "] = " << targets[i] << endl;
    }
    // add one more timeseriesbp
    TimeStampBP tsbp2 = {"2020-01-01 00:00:01",0.2};
    algoComponent.BpMap["600010.sh"].push_back(tsbp2);
    // get the bpMap
    cout << "algoComponent.BpMap[\"600010.sh\"][1].bp = " << algoComponent.BpMap["600010.sh"][1].BP << endl;

    // add one more target
    algoComponent.setNumAlloc("600011.sh",10000);
    algoComponent.setNumExec("600011.sh",1000);
    algoComponent.setAssStruct("600011.sh",assComponent);
    algoComponent.BpMap["600011.sh"] = tsbpVec;
    // get the targets
    targets = algoComponent.getTargets();
    for (int i = 0; i < targets.size(); i++)
    {
        cout << "targets[" << i << "] = " << targets[i] << endl;
    }
    // get the bpMap
    cout << "algoComponent.BpMap[\"600011.sh\"][0].bp = " << algoComponent.BpMap["600011.sh"][0].BP << endl;

    // add one more target with addTarget function
    algoComponent.addTarget("600012.sh");
    // update all the values for new target
    algoComponent.setNumAlloc("600012.sh",10000);
    algoComponent.setNumExec("600012.sh",1000);
    algoComponent.setAssStruct("600012.sh",assComponent);
    algoComponent.BpMap["600012.sh"] = tsbpVec;
    // get the targets
    targets = algoComponent.getTargets();
    for (int i = 0; i < targets.size(); i++)
    {
        cout << "targets[" << i << "] = " << targets[i] << endl;
    }

    // test
    return 0;
}

