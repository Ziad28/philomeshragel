#include<iostream>
#include"ArrayStack.h"
#include"LinkedQueue.h"
using namespace std;


// LabExam 8:00 - 11:00  By:Mohamed Hazem
void rearrangeQueue(LinkedQueue<int>& Q)
{
	//First create 2 queues
	LinkedQueue<int>Odds;
	LinkedQueue<int>Evens;
	int temp;
	while(!Q.isEmpty())
	if (Q.dequeue(temp))
	{
		if (temp % 2 == 0)
			Evens.enqueue(temp);
		else
			Odds.enqueue(temp);
	}
	//Now that we have emptied our queue into 2 queues, Let's Arrange it back as required
	while (!Odds.isEmpty() && !Evens.isEmpty())
	{
		Odds.dequeue(temp);
		Q.enqueue(temp);
		Evens.dequeue(temp);
		Q.enqueue(temp);
	}
	//Now one of the 2 queues has finished, so let's put the remaining values back into Q
	if (!Odds.isEmpty() && Evens.isEmpty())
	{
		while (!Odds.isEmpty())
		{
			Odds.dequeue(temp);
			Q.enqueue(temp);
		}
	}
	else if (Odds.isEmpty() && !Evens.isEmpty())
	{
		while (!Evens.isEmpty())
		{
			Evens.dequeue(temp);
			Q.enqueue(temp);
		}	
	}
}
// Lab Exam 1:00 - 4:00  By:Youssef Hassanien
void sumOutsideIn(LinkedQueue<int>& queue)
{
	/*The solution idea is if the queue contains even number of elements just add the 1st and
	 last element then put them in the 1st element then move to the next 2 elements and so on
	and if it contains odd number of elements we will do the same as the even part then we will 
	handle the lonely element explicitly (element that does not have a pair)
	*/
	if (queue.isEmpty())
		return;
	int NodesCounter = 0;
	LinkedQueue<int>TempQ;
	ArrayStack<int>TempSt;
	int Temp1;
	int Temp2;
	while (!queue.isEmpty())
	{
		queue.dequeue(Temp1);
		NodesCounter++; //counter to know if the queue contains even or odd number of elements
		TempQ.enqueue(Temp1);
		TempSt.push(Temp1); //reversing the queue so we can add the 1st and last element
	}
	if ((NodesCounter % 2) == 0)  //even number of elements case
	{
		if (NodesCounter > 2) //if the queue has only 2 elements we do not need the for loop
		{
			for (int i = 0; i < (NodesCounter / 2); i++)
			{
				TempQ.dequeue(Temp1);
				TempSt.pop(Temp2);
				queue.enqueue(Temp1 + Temp2);
			}
		} 
		else
		{
			TempQ.dequeue(Temp1);
			TempSt.pop(Temp2);
			queue.enqueue(Temp1+Temp2);
		}
	} 
	else
	{
		if(NodesCounter > 1) //if the queue has only 1 element we do not need the for loop
		{
			for (int i = 0; i < (NodesCounter / 2); i++)
			{
				TempQ.dequeue(Temp1);
				TempSt.pop(Temp2);
				queue.enqueue(Temp1+Temp2);
			}
			TempQ.dequeue(Temp1);
			queue.enqueue(Temp1);
		}
		else
		{
			TempQ.dequeue(Temp1);
			queue.enqueue(Temp1);
		}
	}
}
// LabExam 4:00 - 7:00  By:Mohamed Maher
void ReverseEvenIndices(LinkedQueue<int>& Q)
{
	//idea of solution 
	// when index of number is odd we leave it as it is 
	// when index of number is even we push it in stack as we need to reverse index of even (make it last in first out)
	ArrayStack<int>s; //stack has even numbers
	LinkedQueue<int>q;//queue has odd numbers
	int indx = 0;
	while (!Q.isEmpty())
	{
		if (indx % 2 == 0)
		{
			int top;
			Q.dequeue(top);
			s.push(top);
		}
		else {
			int top;
			Q.dequeue(top);
			q.enqueue(top);
		}
		indx++;
	}
	int sizeq = indx; //size of queue
	indx = 0; //to iterate again from first
	for (int i = 0;i < sizeq;i++) {
		if (i % 2 == 0) {
			int top;
			s.pop(top);
			Q.enqueue(top);
		}
		else {
			int top;
			q.dequeue(top);
			Q.enqueue(top);
		}
	}

	return;
}

int main()
{
	LinkedQueue<int> MyQueue;	//create an object of class LinkedQueue
	int val;

	cout << "\nPlease enter int values to add to the queue (-1 to stop):\n";
	cin >> val;
	while (val != -1)
	{
		MyQueue.enqueue(val);
		cin >> val;
	}
	//rearrangeQueue(MyQueue);
    //sumOutsideIn(MyQueue);
	//ReverseEvenIndices(MyQueue);
	while (!MyQueue.isEmpty())
	{
		int x;
		MyQueue.dequeue(x);
		if (!MyQueue.isEmpty()) {
			cout << x << ", ";
		}
		else {
			cout << x;
		}
	}

	cout << endl;
}
