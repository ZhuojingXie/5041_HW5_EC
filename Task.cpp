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

Task::Task() {

}

//overload assgiment;
Task &Task::operator=(const Task &rhs) {
    if(this != &rhs){
        this->processId = rhs.processId;
        this->priority = rhs.priority;
        this-> arriveTime=rhs.arriveTime;
        this-> burstTime=rhs.burstTime;
        this-> priority=rhs.priority;
        this-> remainingTime = rhs.remainingTime;
        this-> terminationTime = rhs.remainingTime;
        this-> turnAroundTime =rhs.turnAroundTime;
        this-> waitTime = rhs.waitTime;
        this->isActive = rhs.isActive;
        this-> isCompleted = rhs.isCompleted;
    }
    return *this;
}
