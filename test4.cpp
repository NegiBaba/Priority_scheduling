#include <bits/stdc++.h>
#define CLR system("cls")
using namespace std; 

int number; // total number of processes

struct process 
{
	int arival, btime, priority, pno; 
};

process p[50]; 

bool cmpr(process a, process b) 
{ 
	if(a.arival == b.arival) 
	{ 
		return a.priority < b.priority;  
	} 
	else
	{ 
		return a.arival<b.arival; 
	} 
} 

void waiting(int wt[]) 
{ 

	int burst[50]; 
	burst[0]=0; 
	wt[0]=0; 


	for(int i = 1; i < number; i++) 
	{ 
		burst[i] = p[i - 1].btime + burst[i - 1]; 

		wt[i] = burst[i] - p[i].arival + 1; 
	
		if(wt[i] < 0) 
		{ 
			wt[i] = 0; 
		}
	} 

}

void turnTime(int tat[],int wt[]) 
{ 

	for(int i=0;i<number;i++) 
	{ 
		tat[i] = p[i].btime + wt[i]; 
	} 
	
} 

void findgc() 
	{ 
		int wt[50], tat[50];

		waiting(wt); 
		turnTime(tat, wt); 
	
		int stime[50], ctime[50]; 
		stime[0] = 1; 
		ctime[0] = stime[0] + tat[0]; 

	for(int i = 1; i < number; i++) 
	{ 
		stime[i] = ctime[i - 1]; 
		ctime[i] = stime[i] + tat[i] - wt[i]; 
	} 
	
cout<<"Process    Start_time    Complete_time    Turn_Around_Time	Waiting_Time	"<<endl; 
	
	
for(int i = 0; i < number; i++) 
	{
		
		cout << p[i].pno << "		" << stime[i] << "		" << ctime[i] << "		" << tat[i] << "			" << wt[i] << endl; 
	} 

} 

int main() 
{ 
int aTime[1000], bursttime[1000], priority[10000];

// getting the total number of processes
cout << "Enter the number of processes: ";
cin >> number;
CLR;

cout << "Enter the priority of processes";
// getting the processes detail
for(int i = 0; i < number; i++)
{
	cin >> priority[i];
}
CLR;

cout << "Enter the arrival time: ";
for(int i = 0; i < number; i++)
{
	cin >> aTime[i];
}
CLR;

cout << "Enter the burst time: ";
for(int i = 0; i < number; i++)
{
	cin >> bursttime[i];
}
CLR;

for(int i = 0; i < number; i++) 
{ 
	p[i].arival = aTime[i]; 
	p[i].btime = bursttime[i]; 
	p[i].priority = priority[i]; 
	p[i].pno = i + 1; 
	} 
	
	//Using inbuilt sort function 
	
	sort(p,p+number,cmpr); 
	
	//Calling function findgc for finding Gantt Chart 
	
	findgc(); 

	return 0; 
} 

// This code is contributed by Anukul Chand. 
