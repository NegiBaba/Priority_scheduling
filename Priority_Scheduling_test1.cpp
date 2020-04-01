#include<bits/stdc++.h>
#define CLR  system("cls")
using namespace std;

int process[100][5]; // [][0] == Priority [][1] == burst time [][2] == arrival time [][3] == finsished [][5] == process number
int waiting_time[100] = {0};
int total_time = 0;

void getProcess(int process[][5], int process_count)
{
	
	CLR;
	for(int i = 0; i < process_count; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(j == 0) cout << "\n\nPlease enter the Priority for P" << i + 1 << " := ";
			else if(j == 1) cout << "Please enter the Burst Time for P" << i + 1 << " := ";
			else cout << "Please enter the Arrival Time for P" << i + 1 << " := ";
			process[i][4] = i;
			cin >> process[i][j];
			
			if(j == 2 && i >= 1)
			{
				for(int l = i; l > 0; l--)
				{
					if(process[l][2] < process[l - 1][2])
					{
						int temp_priority = process[l][0];
						int temp_burst = process[l][1];
						int temp_arrival = process[l][2];
						int temp_number = process[l][4];
						
						process[l][0] = process[l - 1][0];
						process[l][1] = process[l - 1][1];
						process[l][2] = process[l - 1][2];
						process[l][4] = process[l - 1][4];
						
						process[l - 1][0] = temp_priority;
						process[l - 1][1] = temp_burst;
						process[l - 1][2] = temp_arrival;
						process[l - 1][4] = temp_number;
					}
				}
			}
		}
		process[i][3] = 0;
		
	}
}

void Working(int process[][5], int process_count)
{
	bool run = true;
	int current_process;
	
	while(run)
	{

		int process_finished = 0;
		int max_priority = INT_MAX;
		int priority_process = -1;

		//////////////////////////////////////  finding the max priority process
		for(int i = 0; i < process_count; i++)
		{
			if(process[i][0] < max_priority && process[i][1] > 0)
			{
				max_priority = process[i][0];
				priority_process = i;
				
			}
		}
		if(total_time == 0) current_process = priority_process;
		/////////////////////////////////////

		// calculating waiting time
		for(int i = 0; i < process_count; i++)
		{
			if(process[i][2] < total_time && process[i][1] > 0 && i != priority_process) waiting_time[i]++;
		}

		process[priority_process][1]--;

		for(int i = 0; i < process_count; i++) 
		{
			if(process[i][1] == 0) process_finished++;
		}
		if(process_finished == process_count) run = false;

		total_time++;
		if(total_time > 0 && total_time % 2 == 0)
		{
			for(int i = 0; i < process_count; i++)
			{
				if(i != priority_process && total_time > process[i][3]) process[i][0]--;
			}
		}

	}
	
	CLR;
	for(int i = 0; i < process_count; i++)
		{
			cout << " Process : " << i << " waiting time " << waiting_time[i] << endl;
		}
		
	cout << endl << endl << endl << endl;
	
	
	for(int i = 0; i < process_count; i++)
	{
		cout << process[i][4] << endl;
	}
		
}
int main()
{
	int process_count = 0;
	cout << "Please Enter the number of processes: " << endl;
	cin >> process_count;
	getProcess(process, process_count);
	Working(process, process_count);
	
	
	
	return 0;
}
