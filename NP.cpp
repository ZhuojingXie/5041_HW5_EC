//
// Created by Admin on 3/10/2021.
//

#include "NP.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;


NP::NP(std::vector<Task> &jobList) : Run(jobList) {}

void NP::run() {
    int ctime = 0;
    int idleTime =0;

    vector<Task> waitingList;
    while(!jobList.empty() || !waitingList.empty()){
        activateTask(ctime);
        for(auto job = jobList.begin(); job != jobList.end();){
            if(job->isActive){
                waitingList.push_back(*job);
                job = jobList.erase(job);
            }else{
                ++job;
            }
        }

        sort(waitingList.begin(),waitingList.end(),
             [](Task const &a, Task const &b)
             {
                 if(a.isActive && b.isActive){
                     if(a.priority != b.priority)
                        return a.priority<b.priority;
                     else
                         return a.arriveTime<b.arriveTime;
                 }
                 return false;
             }
        );

        if(!waitingList[0].isCompleted){
            cout<<"Time "<<ctime<<" Process "<<waitingList[0].processId<<endl;
            while(waitingList[0].remainingTime > 0){
                ctime++;
                waitingList[0].remainingTime--;
            }
            waitingList[0].terminationTime = ctime;
            waitingList[0].turnAroundTime = ctime - waitingList[0].arriveTime;
            waitingList[0].waitTime = waitingList[0].turnAroundTime - waitingList[0].burstTime;
            waitingList[0].isCompleted = true;
            completeList.push_back(waitingList[0]);
            waitingList.erase(waitingList.begin());
        }else{
            cout<<"Time "<<ctime<<" Idle"<<endl;
            while(!jobList[0].isActive){
                ctime++;
                idleTime++;
                activateTask(ctime);
            }
        }
    }

    cout<<setprecision(0)<<fixed<<"CPU Utilization: "<< (1 - ((double)idleTime)/(ctime))*100<<"%"<<endl;
    print();
}
