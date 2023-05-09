#pragma once
#include "LinkedList.h"
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include "Process.h"

class Processor
{
protected:
	int timestep;
	int busytime;
	bool status;
	bool Rd;
	int FinishTime;
	Process* RunList;
	string Type;
public:
	Processor();
	void virtual AddProcessRd(Process* P) = 0;
	virtual Process* ScheduleAlgo() = 0;
	void SetStatus(bool s);
	bool GetStatus();
	bool Empty();
	int virtual PLoad();
	int virtual PUtil();
	string return_Type();
	virtual Process* getRun()=0;
	void virtual printRDY() = 0;
	int getfinishtime();
	void setFinishtime(int n);
};