//
// Created by Admin on 3/10/2021.
//

#ifndef EC_HW5_TASK_H
#define EC_HW5_TASK_H


class Task {
public:
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

    Task(int processId, int arriveTime, int burstTime, int priority);
    //todo big 4?
};


#endif //EC_HW5_TASK_H
