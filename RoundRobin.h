#pragma once
#include "Processor.h"
#include "Process.h"
#include "Queue.h"
class RoundRobin :public Processor {
private:
    Process* run;
    Queue<Process*> ReadyList;
    bool status;
    int timeslice;
    int timesum;
public:
    RoundRobin();
    void settimeslice(int t);
    virtual Process* ScheduleAlgo();
    void AddProcessRd(Process* p);
    void AddProcessRn(Process* p);
    Process* getRun();
    void printRDY();

};
