#include <bits/stdc++.h>
#define CLR  system("cls")
using namespace std; 

int number; // number of processes

struct process {
	int arival, bt, priority, pno; 
}; 

process proc[50]; 


bool comp(process a,process b) 
{ 
	if(a.arival == b.arival) 
	{
		return a.priority < b.priority; 
	}	 
	else
	{ 
		return a.arival < b.arival; 
	} 
} 

void get_waiting(int wt[], number) 
{ 

	int burst[50]; 

	burst[0]=0; 
	wt[0]=0; 


	for(int i = 1; i < number; i++) 
	{	 
		service[i]=proc[i-1].bt+service[i-1]; 

		wt[i] = burst[i] - proc[i].arival + 1; 

		if(wt[i] < 0) 
		{ 
			wt[i]=0; 
		}	 
	} 

} 

void get_turn(int turn[], int wt[]) 
{ 

	for(int i = 0; i < number ;i++) 
	{ 
		turn[i]=proc[i].bt+wt[i]; 
	}	 
	
} 

void findgc() 
{ 
//Declare waiting time and turnaround time array 
int wt[50],tat[50]; 

double wavg=0,tavg=0; 

// Function call to find waiting time array 
get_wt_time(wt); 
//Function call to find turnaround time 
get_tat_time(tat,wt); 
	
int stime[50],ctime[50]; 
stime[0]=1; 
ctime[0]=stime[0]+tat[0]; 
// calculating starting and ending time 
for(int i=1;i<totalprocess;i++) 
	{ 
		stime[i]=ctime[i-1]; 
		ctime[i]=stime[i]+tat[i]-wt[i]; 
	} 
	
cout<<"Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time"<<endl; 
	
	// display the process details 
	
for(int i=0;i<totalprocess;i++) 
	{ 
		wavg += wt[i]; 
		tavg += tat[i]; 
		
		cout<<proc[i].pno<<"\t\t"<< 
			stime[i]<<"\t\t"<<ctime[i]<<"\t\t"<< 
			tat[i]<<"\t\t\t"<<wt[i]<<endl; 
	} 
	
		// display the average waiting time 
		//and average turn around time 
	
	cout<<"Average waiting time is : "; 
	cout<<wavg/(float)totalprocess<<endl; 
	cout<<"average turnaround time : "; 
	cout<<tavg/(float)totalprocess<<endl; 

} 

int main() 
{
	cout << "Enter the number of process: "
	cin >> number; // getting the number of processes
	CLR;
for(int i=0;i<totalprocess;i++) 
{ 
	proc[i].at=arrivaltime[i]; 
	proc[i].bt=bursttime[i]; 
	proc[i].pr=priority[i]; 
	proc[i].pno=i+1; 
	} 
	
	//Using inbuilt sort function 
	
	sort(proc,proc+totalprocess,comp); 
	
	//Calling function findgc for finding Gantt Chart 
	
	findgc(); 

	return 0; 
} 

// This code is contributed by Anukul Chand. 

