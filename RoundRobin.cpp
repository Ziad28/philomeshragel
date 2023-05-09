#include "RoundRobin.h"

RoundRobin::RoundRobin()
{
	status = true;
	Type = "RoundRobin";
	FinishTime = 0;
}
void RoundRobin::settimeslice(int t) {
	timeslice = t;
}

Process* RoundRobin::ScheduleAlgo
()
{
	Process P;
	return &P;
}
void RoundRobin::AddProcessRd(Process* p)
{
	ReadyList.enqueue(p);
	FinishTime += p->getcpu_time();
	Rd = false;
}

void RoundRobin::AddProcessRn(Process* p)
{
	RunList = p;
}

Process* RoundRobin::getRun()
{
	//Make temp = to running
	Process* temp = RunList;
	//Set Running to NULL
	RunList = NULL;
	//return the temp
	return temp;
}
void RoundRobin::printRDY() {
	while (!ReadyList.isEmpty()) {
		cout << ReadyList.dequeue()->getprocess_id() << " ";
	}
}



