//
// Created by Admin on 3/10/2021.
//

#ifndef EC_HW5_NP_H
#define EC_HW5_NP_H


#include "Run.h"

class NP : public Run {
public:
    NP(std::vector<Task> &jobList);

    void run();
};


#endif //EC_HW5_NP_H
