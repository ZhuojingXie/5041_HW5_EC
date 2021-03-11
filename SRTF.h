//
// Created by Admin on 3/10/2021.
//

#ifndef EC_HW5_SRTF_H
#define EC_HW5_SRTF_H


#include "Run.h"

class SRTF : public Run {
public:
    SRTF(std::vector<Task> &jobList);

    void run();

};


#endif //EC_HW5_SRTF_H
