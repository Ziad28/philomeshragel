#include "SJF.h"

SJF::SJF()
{
    status = true;
    RunList = NULL;
    Type = "SJF";
    FinishTime = 0;
}
Process* SJF::ScheduleAlgo()
{
    Process P;
    return &P;
}



void SJF::AddProcessRd(Process* p)
{
	ReadyList.enqueue(*p, p->getcpu_time());
    FinishTime += p->getcpu_time();
}

void SJF::AddProcessRn(Process* p)
{
	RunList = p;
    Rd = false;
}


Process* SJF::getRun()
{
    //Make temp = to running
    Process* temp = RunList;
    //Set Running to NULL
    RunList = NULL;
    //return the temp
    return temp;
}
void SJF::printRDY() {
}