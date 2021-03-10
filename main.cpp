#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Task{
    int processId = -1;
    int arriveTime = -1;
    int burstTime = -1;
    int priority =-1;
    int remainingTime = -1;
    int terminationTime = -1;
    int turnAroundTime = -1;
    int waitTime = -1;
    bool isActive = false;
    bool isCompleted = false;

    //constructor
    Task(int processId, int arriveTime, int burstTime, int priority){
        this->processId = processId;
        this->arriveTime = arriveTime;
        this->burstTime = burstTime;
        this->priority = priority;
        remainingTime = burstTime;
    }
};



/**
 * activate a task;
 * @param jobList
 * @param ctime
 */
void activateTask(vector<Task>& jobList, int ctime){
    for(auto &job:jobList){
        if(job.arriveTime<= ctime)
            job.isActive = true;
    }
}

void print(vector<Task>& completedList){
    int waitTime = 0;
    int count = 0;
    int worstTime = 0;
    for(auto &job:completedList){
        waitTime += job.waitTime;
        count++;
        worstTime = max(worstTime,job.waitTime);
    }
    cout<<setprecision(2)<<fixed<<"Average waiting time: "<<(double)waitTime/count<<endl;
    cout<<"Worst-case waiting time: "<<worstTime<<endl;
}

void SJF(vector<Task>& jobList){
    int ctime = 0;
    int idleTime =0;
    vector<Task> completeList;
    //sort the job list based on arriving time;

    sort(jobList.begin(),jobList.end(),
         [](Task const &a, Task const &b)
         {
            return a.arriveTime<b.arriveTime;
     });

    vector<Task> waitingList;
    while(!jobList.empty() || !waitingList.empty()){
        activateTask(jobList,ctime);
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
                     return a.burstTime<b.burstTime;
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
                activateTask(jobList,ctime);
            }
        }
    }

    cout<<setprecision(0)<<fixed<<"CPU Utilization: "<< (1 - ((double)idleTime)/(ctime))*100<<"%"<<endl;
    print(completeList);
}

int main() {
    Task task1(0,0,5,3);
    Task task2(1,10,20,3);
    Task task3(2,10,10,5);
    Task task4(3,15,3,2);
    Task task5(4,20,35,1);
    Task task6(5,25,5,4);

//    Task task1(0,0,5,3);
//    Task task2(1,35,20,3);
//    Task task3(2,10,10,5);
//    Task task4(3,15,3,2);
//    Task task5(4,20,35,1);
//    Task task6(5,25,5,4);

    vector<Task> jobList;
    jobList.push_back(task1);
    jobList.push_back(task2);
    jobList.push_back(task3);
    jobList.push_back(task4);
    jobList.push_back(task5);
    jobList.push_back(task6);

    SJF(jobList);




    return 0;
}
