//
// Created by Admin on 3/10/2021.
//

#include "Run.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;


Run::Run(std::vector<Task>& jobList) {
    this->jobList = jobList;
}

void Run::activateTask(int ctime) {
    for(auto &job:jobList){
        if(job.arriveTime<= ctime)
            job.isActive = true;
    }
}

void Run::print() {
    int waitTime = 0;
    int count = 0;
    int worstTime = 0;
    for(auto &job:this->completeList){
        waitTime += job.waitTime;
        count++;
        worstTime = max(worstTime,job.waitTime);
    }
    cout<<setprecision(2)<<fixed<<"Average waiting time: "<<(double)waitTime/count<<endl;
    cout<<"Worst-case waiting time: "<<worstTime<<endl;
}
