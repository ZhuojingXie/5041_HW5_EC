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

using namespace std;

vector<vector<int>> filebuff (){
    string filepath = "input.txt";
    vector<vector<int>> res;



    string buff;
    ifstream inFile;
    inFile.open(filepath);
    if(!inFile)
        throw runtime_error("File Not Found");

    if(inFile){
        while(getline(inFile,buff)){
            istringstream iss(buff);
            vector<int> process;
            for(int n =0;n<4;n++){
                int val;
                iss>>val;
                process.push_back(val);
            }
            res.push_back(process);
        }
    }

    inFile.close();
    return res;
}


int main() {
    /*
    Task task1(0,0,5,3);
    Task task2(1,10,20,3);
    Task task3(2,10,10,5);
    Task task4(3,15,3,2);
    Task task5(4,20,30,1);
    Task task6(5,25,5,4);


    vector<Task> jobList;
    jobList.push_back(task1);
    jobList.push_back(task2);
    jobList.push_back(task3);
    jobList.push_back(task4);
    jobList.push_back(task5);
    jobList.push_back(task6);

    SJF sjf(jobList);
    sjf.run();


    cout<<"====================NP===================\n\n";
    NP np(jobList);
    np.run();


    cout<<"====================SRTF===================\n\n";
    SRTF srtf(jobList);
    srtf.run();


    cout<<"====================PP===================\n\n";
    PP pp(jobList);
    pp.run();
     */

    vector<vector<int>> list = filebuff();
    vector<Task> jobList;
    for(auto process:list){
        Task task(process[0],process[1],process[2],process[3]);
        jobList.push_back(task);
    }

    cout<<"====================SFJ===================\n\n";
    SJF sjf(jobList);
    sjf.run();

    cout<<"====================NP===================\n\n";
    NP np(jobList);
    np.run();

    cout<<"====================SRTF===================\n\n";
    SRTF srtf(jobList);
    srtf.run();

    cout<<"====================PP===================\n\n";
    PP pp(jobList);
    pp.run();

    return 0;
}
