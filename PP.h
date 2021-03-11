//
// Created by Admin on 3/10/2021.
//

#ifndef EC_HW5_PP_H
#define EC_HW5_PP_H


#include "Run.h"

class PP : public Run {
public:
    PP(std::vector<Task> &jobList);

    void run();

};


#endif //EC_HW5_PP_H
