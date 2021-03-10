//
// Created by Admin on 3/10/2021.
//

#include "Task.h"

Task::Task(int processId, int arriveTime, int burstTime, int priority) {
        this->processId = processId;
        this->arriveTime = arriveTime;
        this->burstTime = burstTime;
        this->priority = priority;
        remainingTime = burstTime;
}
