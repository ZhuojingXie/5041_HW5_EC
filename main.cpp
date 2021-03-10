#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Task.h"
#include "SJF.h"

using namespace std;

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

    SJF sjf(jobList);
    sjf.run();

    return 0;
}
