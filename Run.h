//
// Created by Admin on 3/10/2021.
//

#ifndef EC_HW5_RUN_H
#define EC_HW5_RUN_H

#include <vector>
#include "Task.h"

/**Parent class for
 *
 */
class Run {
public:
    Run(std::vector<Task>& jobList);
    void activateTask(int ctime);
    void print();

protected:
    std::vector<Task> jobList;
    std::vector<Task> completeList;
};


#endif //EC_HW5_RUN_H
