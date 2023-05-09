#pragma once
#include "Processor.h"
#include "Process.h"
#include "LinkedList.h"
#include "Queue.h"
#include "PrioQueue.h"

class FCFS : public Processor
{
private:
	LinkedList<Process*> ReadyList;
	bool status;
public:
	FCFS();
    virtual Process* ScheduleAlgo();
	void AddProcessRd(Process* p);
	void AddProcessRn(Process* p);
	Process* getRun();
	void printRDY();

};