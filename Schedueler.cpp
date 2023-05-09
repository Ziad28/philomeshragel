#include "Schedueler.h"
#include "UI.h"
#include <iostream>
#include <fstream>

using namespace std;

Schedueler::Schedueler()
{
	timestep = 0;
	
}


void Schedueler::load()
{
	ifstream fin("C:\\Users\\zizor\\OneDrive\\Desktop\\Phase 2\\test3.txt"); // open input file

	if (fin.fail())
	{
		std::cout << "Error opening input file\n";
	}

	// read number of processors for each scheduling algorithm
	fin >> NF >> NS >> NR;




	// read time slice for RR scheduling
	int time_slice;
	fin >> time_slice;

	// read RTF, Max, STL, and fork probability
	int RTF, Max, STL;
	double fork_prob;
	fin >> RTF >> Max >> STL >> fork_prob;

	// read number of processes
	fin >> M;


	int* arrival_times = new int[M];
	int* process_id = new int[M];
	int* cpu_time = new int[M];
	int* N = new int[M];
	int* killtimes = new int[M];
	int* IdKs = new int[M];
	int** io_times = new int* [M];




	for (int i = 0; i < M; i++) {
		fin >> arrival_times[i] >> process_id[i] >> cpu_time[i] >> N[i];

		io_times[i] = new int[N[i] * 2];
		for (int j = 0; j < N[i] * 2; j += 2) {
			char c;
			fin >> c;
			fin >> io_times[i][j] >> c >> io_times[i][j + 1]; // read io_r and io_d values
			fin >> c;
		}


	}

	fin.close();
	//creating the processors
	arrP = new Processor * [NF + NS + NR];
	for (int i = 0; i < NF; i++) {
		FCFS* F = new FCFS(); // Dynamically allocate FCFS object
		arrP[i] = F; // Store the pointer to the allocated object
	}

	for (int i = NF; i < NS + NF; i++) {
		SJF* S = new SJF(); // Dynamically allocate SJF object
		arrP[i] = S; // Store the pointer to the allocated object
	}

	arrR = new RoundRobin[NR];
	for (int i = NS + NF; i < NR + NS + NF; i++) {
		RoundRobin* R = new RoundRobin(); // Dynamically allocate RoundRobin object
		arrP[i] = R; // Store the pointer to the allocated object
	}

	for (int i = 0; i < NF + NS + NR; i++) {
		cout << "processor: " << i << " added Type is: " << arrP[i]->return_Type() << endl;
	}



	for (int i = 0; i < M; i++)
	{

		Process* p = new Process;

		p->setarrival_time(arrival_times[i]);
		p->setprocess_id(process_id[i]);
		p->setcpu_time(cpu_time[i]);
		p->setio_requesttime(io_times[i][0]);
		p->setio_duration(io_times[i][1]);
		newlist.enqueue(p);
	
	}

	delete[] arrival_times;
	delete[] process_id;
	delete[] cpu_time;

	for (int i = 0; i < M; i++)
	{
		delete[] io_times[i];
	}

	delete[] io_times;
	delete[] killtimes;
	delete[] IdKs;

}


void Schedueler::simulate()
{
	load();
	//NEW TO READY OF SHORTEST RDY QUEUE
	while (!newlist.isEmpty()) {
		int iLeast = 0;
		int c = 10000000;
		int i = 0;
		for (int i=0; i < NF + NS + NR; i++) {
			if (arrP[i]->getfinishtime() < c) {
				c = arrP[i]->getfinishtime();
				iLeast = i;
			}
		}
		cout << "processor with least finish time is no: " << iLeast << " finish time= " << c << endl;
		cout << "cpu time of added process is= " << newlist.peek()->getcpu_time()<<endl;
		arrP[iLeast]->AddProcessRd(newlist.dequeue());
		cout << "Finish time of processor= " << arrP[iLeast]->getfinishtime() << endl;
		
		
	}
}
