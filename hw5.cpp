#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Task.h"
#include "SJF.h"
#include "NP.h"
#include "SRTF.h"
#include "PP.h"


/**
 * Team member
 * Xie, Zhuojing
 * Liao, Jun
 * Lu, Menglin
 * 
 * For the input file, the following assumptions applied:
 * o    Each line consists of four integers.
 * o    The process id is unique for each line (and is greater than zero).
 * o    The arrival time is greater than or equal to zero.
 * o    The burst time is strictly greater than zero.
 * o    The priority is greater than or equal to zero.
 *
 * For the command line, assumption all input are Uppercase
 *
 */

using namespace std;

vector<vector<int>> fileReader(const string& filename) {
    const string& filepath = filename;
    vector<vector<int>> res;

    string buff;
    ifstream inFile;
    inFile.open(filepath);
    if (!inFile)
        throw runtime_error("File Not Found");

    if (inFile) {
        while (getline(inFile, buff)) {
            istringstream iss(buff);
            vector<int> process;
            for (int n = 0; n < 4; n++) {
                int val;
                iss >> val;
                process.push_back(val);
            }
            res.push_back(process);
        }
    }

    inFile.close();
    return res;
}


int main(int argc, char* argv[]) {


    string filename = argv[1];
    string cmd =  argv[2];

    vector<vector<int>> list = fileReader(filename);
    vector<Task> jobList;
    for (auto process:list) {
        Task task(process[0], process[1], process[2], process[3]);
        jobList.push_back(task);
    }


    if(cmd == "SJF"){
    SJF sjf(jobList);
    sjf.run();
    }
    else if(cmd == "SRTF") {
        SRTF srtf(jobList);
        srtf.run();
    }
    else if(cmd == "NP") {
        NP np(jobList);
        np.run();
    }
    else if(cmd == "PP") {
        PP pp(jobList);
        pp.run();
    }else{
        cout<<"Invalid instruction\n";
    }

    return 0;
}
