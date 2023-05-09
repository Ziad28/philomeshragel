#include "FCFS.h"
FCFS::FCFS()
{
    RunList ;
    status = true;
    Type = "FCFS";
    FinishTime = 0;
}
Process* FCFS::ScheduleAlgo()
{
    Process P;
    return &P;
    
}
void FCFS::AddProcessRd(Process* p)
{
	ReadyList.InsertEnd(p);
    FinishTime += p->getcpu_time();
    Rd = false;
}

void FCFS::AddProcessRn(Process* p)
{
	RunList = p;
}

Process* FCFS::getRun()
{
    //Make temp = to running
    Process* temp = RunList;
    //Set Running to NULL
    RunList = NULL;
    //return the temp
    return temp;
}
void FCFS::printRDY() {
 
}


