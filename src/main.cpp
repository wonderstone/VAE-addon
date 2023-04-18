#include <iostream>
#include "algoStruct.cpp"
#include "algoManager.cpp"

// stack memory: the compiler probably will allocate 1-8MB memory due to the size of the program
// it is faster but very limited. therefore pay attention to the size of the data stored in stack memory
// * may even fight against the compiler *
int main()
{
    // + Part 1 - AlgoStruct
    // Create an object of class AssStruct
    AssStruct assComponent = {1.0, true, 0.3, 0.2, 0.8};
    // create an object of time stamp bp
    TimeStampBP tsbp = {"2020-01-01 00:00:00", 0.1};
    // create an object of vector of time stamp bp
    vector<TimeStampBP> tsbpVec;
    tsbpVec.push_back(tsbp);
    // create two objects of AlgoStruct, the second is less important
    AlgoStruct algoComponent = AlgoStruct("AlgoID001");
    AlgoStruct algoComponent1 = AlgoStruct("AlgoID002");
    // set the update time stamp
    algoComponent.setUpdateTimeStamp("2020-01-01 00:00:00");
    // set the numAlloc
    algoComponent.setNumAlloc("600010.sh", 10000);
    // set the numExec
    algoComponent.setNumExec("600010.sh", 1000);
    // set the assStruct
    algoComponent.setAssStruct("600010.sh", assComponent);
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
    TimeStampBP tsbp2 = {"2020-01-01 00:00:01", 0.2};
    algoComponent.BpMap["600010.sh"].push_back(tsbp2);
    // get the bpMap
    cout << "algoComponent.BpMap[\"600010.sh\"][1].bp = " << algoComponent.BpMap["600010.sh"][1].BP << endl;

    // add one more target
    algoComponent.setNumAlloc("600011.sh", 10000);
    algoComponent.setNumExec("600011.sh", 1000);
    algoComponent.setAssStruct("600011.sh", assComponent);
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
    algoComponent.setNumAlloc("600012.sh", 10000);
    algoComponent.setNumExec("600012.sh", 1000);
    algoComponent.setAssStruct("600012.sh", assComponent);
    algoComponent.BpMap["600012.sh"] = tsbpVec;
    // get the targets
    targets = algoComponent.getTargets();
    for (int i = 0; i < targets.size(); i++)
    {
        cout << "targets[" << i << "] = " << targets[i] << endl;
    }

    // + Part 2 - AlgoManager
    // create a map with AlgoStruct referece as value and ID string as key
    map<string, AlgoStruct *> algoMap;
    // add the algoComponent to the map
    algoMap["AlgoID001"] = &algoComponent;
    // change the numAlloc of the algoComponent
    algoMap["AlgoID001"]->setNumAlloc("600010.sh", 20000);

    // create a manager object on the heap and manage it with a smart pointer
    // std::unique_ptr<AlgoManager> upalgoManager(new AlgoManager(algoMap));
    std::unique_ptr<AlgoManager> palgoManager(make_unique<AlgoManager>(algoMap));

    // get the numAlloc of the algoComponent
    cout << "algoManager->AlgoMap[\"AlgoID001\"]->getNumAlloc(\"600010.sh\") = " << palgoManager->AlgoMap["AlgoID001"]->getNumAlloc("600010.sh") << endl;

    // get the assessAlgo result
    cout << "algoManager->assessAlgo(\"AlgoID001\",\"600010.sh\") = " << palgoManager->assessAlgo("AlgoID001") << endl;

    // add one more algoComponent to the palgoManager map
    palgoManager->AlgoMap["AlgoID002"] = &algoComponent1;

    // get the assessAlgos result and store it in a map in the heap and manage it with a smart pointer
    std::unique_ptr<map<string, double>> assessAlgosMap(make_unique<map<string, double>>(palgoManager->assessAlgos()));
    // print the result
    for (auto it = assessAlgosMap->begin(); it != assessAlgosMap->end(); it++)
    {
        cout << "assessAlgosMap->at(\"" << it->first << "\") = " << it->second << endl;
    }

    // define an int variable to set nums
    int nums = 1000;
    // - wanna new a map on heap and store result return from delegateAlgoNums?
    // - the normal way can not pass the GodDamn compiler! F@ck the CPP coding thing!
    // map<string,int> delegateAlgoNumsMap = palgoManager->delegateAlgoNums(nums);
    std::unique_ptr<map<string, int>> delegateAlgoNumsMap(make_unique<map<string, int>>(palgoManager->delegateAlgoNums(nums)));

    // reset all smartPointers
    delegateAlgoNumsMap.reset();
    assessAlgosMap.reset();
    palgoManager.reset();

    return 0;
}
