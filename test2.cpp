#include<bits/stdc++.h>
#define CLR  system("cls")
using namespace std; 

int main()
{
	int process[10000][5]; // arrival time, burst time, priority, completed, waited
	int wait[10000] = {0}; 
	int t;
	cout << "Enter the number of Processes: " << endl;
	cin >> t;
	CLR;
	
	for(int i = 0; i < t; i++)
	{
		cout << "Enter the Priority for process " << i + 1 << ": ";
		cin >> process[i][2];
		
		cout << "Enter the Burst Time for process " << i + 1 << ": ";
		cin >> process[i][1];
		
		cout << "Enter the Arrival Time for process " << i + 1 << ": ";
		cin >> process[i][0];
		
		process[i][3] = 1;  // process is not completed
		cout << endl;
	}
	
	int curent = 0, curentpr = 10000;
		for(int i = 0; i < t; i++)
		{
			if(process[i][3] == 1 && process[i][2] < curentpr && process[i][0] <= 0)
			{
				curentpr = process[i][2];
				curent = i;
			}
		}
	
	
	int time = 0;
	bool run = true;
	while(run)
	{
		int maxp = 0, maxpr = 10000;
		for(int i = 0; i < t; i++)
		{
			if(process[i][3] == 1 && process[i][2] < maxpr && process[i][0] <= time)
			{
				maxpr = process[i][2];
				maxp = i;
			}
		}
		
		if(maxp == curent)
		{
			process[maxp][1]--;
			time++;
			if(process[maxp][1] == 0)
			{
				process[maxp][3] = 0;   // /process completed
				cout << "done: " << maxp + 1;
			}
		}
		else if(maxp != curent)
		{
			time += 2;
			for(int i = 0; i < t; i++)
			{
				if(process[i][3] == 1) process[i][2]--;
			}
			
			process[maxp][1]--;
			
		}
		
		int all = 0;
		for(int i = 0; i < t; i++)
		{
			if(process[i][3] == 0) all++;
		}
		if(all == t) run = false;
	}
	return 0;
}
