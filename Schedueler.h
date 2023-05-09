

#include "LinkedList.h"
#include "Queue.h"
#include "SJF.h"
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
#include "RoundRobin.h"
#include "Processor.h"
#include "UI.h"
class Schedueler
{
private:

    Queue<Process*> newlist;
    Queue<Process*> Blk;
    Queue<Process*> TRM;
    int timestep ;
    int NF, NS, NR;
    int M;
    int n;
    FCFS* arrF;
    SJF* arrS;
    RoundRobin* arrR;
    Processor** arrP;

public:
    Schedueler();
    void load();
    void simulate();
};
