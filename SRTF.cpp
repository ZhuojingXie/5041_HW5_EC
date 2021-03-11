//
// Created by Admin on 3/10/2021.
//

#include "SRTF.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>


using namespace std;

SRTF::SRTF(std::vector<Task> &jobList) : Run(jobList) {}


void SRTF::run() {
    int ctime = 0;
    int idleTime = 0;

    vector<Task> waitingList;

    Task prev;

    while (!jobList.empty() || !waitingList.empty()) {
        activateTask(ctime);
        if(waitingList.empty() && !jobList[0].isActive)
            cout << "Time " << ctime << " Idle" << endl;
        while(waitingList.empty() &&!jobList[0].isActive){
            ctime++;
            idleTime++;
            activateTask(ctime);
        }
        for (auto job = jobList.begin(); job != jobList.end();) {
            if (job->isActive) {
                waitingList.push_back(*job);
                job = jobList.erase(job);
            } else {
                ++job;
            }
        }

        sort(waitingList.begin(), waitingList.end(), []
                     (const Task &a, const Task &b) {
                 if (a.remainingTime != b.remainingTime)
                     return a.remainingTime < b.remainingTime;
                 else
                     return a.processId < b.processId;
             }
        );

        if (!waitingList.empty()) {
            if (waitingList[0].processId != prev.processId) {
                cout << "Time " << ctime << " Process " << waitingList[0].processId << endl;
            }
            waitingList[0].remainingTime--;
            prev = waitingList[0];
            ++ctime;
            if (waitingList[0].remainingTime == 0) {
                waitingList[0].isCompleted = true;
                waitingList[0].terminationTime = ctime;
                waitingList[0].turnAroundTime = ctime - waitingList[0].arriveTime;
                waitingList[0].waitTime = waitingList[0].turnAroundTime - waitingList[0].burstTime;
                waitingList[0].isActive = false;
                completeList.push_back(waitingList[0]);
                waitingList.erase(waitingList.begin());
            }
        } else {
            cout << "Time " << ctime << " Idle" << endl;
            while (!jobList[0].isActive) {
                ctime++;
                idleTime++;
                activateTask(ctime);
            }
        }
    }

    cout << setprecision(0) << fixed << "CPU Utilization: " << (1 - ((double) idleTime) / (ctime)) * 100 << "%" << endl;
    print();
}
