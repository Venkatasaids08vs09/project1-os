//Ques. 14. Write a program to implement priority scheduling algorithm with context
// switching time. Prompt to user to enter the number of processes and then enter their 
 //priority, burst time and arrival time also. Now whenever operating system preempts a 
 //process and shifts cpu’s control to some another process of higher priority assume 
 //that it takes 2 seconds for context switching(dispatcher latency).Form a scenario, 
 //where we can give the processes are assigned with priority where the lower integer
  //number is higher priority and then context switch .. as the process waits the priority 
//of the process increase at rate of one per 2 time units of wait.
//Calculate waiting time and turnaround time for each process.


#include<stdio.h> 
void main() 
{ 
	int tq=2;  //time quantum is tq
	int cnt,np,time=0;
	  
	  printf("\nSelect the Number of Processes\t "); 
	  scanf("%d",&np); // np gives no of processes
	  int WT,TAT,prty[np],BT[np],RT[np],t[np],AT[np];
	
	  //WT=Waiting Time
	  //TAT=TurnAround Time
	  //BT=Burst Time
	  //RT=Response Time
	  //t is Array
	  //AT=Arival Time
	  //prty is priority array
	
	  for(cnt=0;cnt<np;cnt++) 
	  { 
	    printf("Enter Priority Burst Time Arrivaltime %d :",cnt+1); 
	   scanf("%d %d %d",&prty[cnt],&BT[cnt],&AT[cnt]);  
	    RT[cnt]=BT[cnt]; 
	  } 
	
	 int a,j;
	
	for(cnt=0;cnt<np;cnt++)
	{
		int min=100;	
		for(j=0;j<np;j++)
		{
			if(prty[j]<min && RT[j]!=0 && AT[j]<time)
			{
				min=prty[j];
				a=j;
			}
		}
		if(time==0)
		{
			time=time+RT[a];
			RT[a]=0;
			t[a]=time;
		}
		else
		{
			time=time+RT[a]+2;
			RT[a]=0 ;
			t[a] =time;
		}
	}
	printf("\n\nProcess\t     Priority   |   Burst Time   |Turnaround Time|Waiting Time\n\n");
	for (cnt=0;cnt<np;cnt++)
	{ 
	      printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",cnt+1,  prty[cnt]-((t[cnt]-AT[cnt])/2),BT[cnt],t[cnt]-AT[cnt],t[cnt]-BT[cnt]-AT[cnt]); 
	}
}
