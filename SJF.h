//
// Created by Admin on 3/10/2021.
//

#ifndef EC_HW5_SJF_H
#define EC_HW5_SJF_H


#include "Run.h"

class SJF: public Run {
public:
    SJF(std::vector<Task> &jobList);

    void run();
};



#endif //EC_HW5_SJF_H
