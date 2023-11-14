#include<stdio.h>
int main()
{
	int i,j,n,temp;
	int bursttime[n],priority[n],waitingtime[n],turnaroundtime[n],totalwt,totaltt;
	float awt,atat;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter burst time and priority for each process:\n");
	for(i=1;i<=n;i++)
	{
		printf("p%d-Bursttime:",i);
		scanf("%d",&bursttime[i]);
		printf("p%d-priority:",i);
		scanf("%d",&priority[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(priority[i]<priority[j])
			{
				temp=priority[i];
				priority[i]=priority[j];
				priority[j]=temp;
				temp=bursttime[i];
				bursttime[i]=bursttime[j];
				bursttime[j]=temp;
			}
		}
	}
	waitingtime[1]=0;
	for(i=2;i<=n;i++)
	{
		waitingtime[i]=waitingtime[i-1]+bursttime[i-1];
		awt=awt+waitingtime[i];
	}
	for(i=1;i<=n;i++)
	{
		turnaroundtime[i]=waitingtime[i]+bursttime[i];
		atat=atat+turnaroundtime[i];
	}
	awt=awt/n;
	atat=atat/n;
	printf("\nProcess\tBursttime\tPriority\tWaitingtime\tTurnaroundtime\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i,bursttime[i],priority[i],waitingtime[i],turnaroundtime[i]);
	}	
	printf("Average Waiting time:%d",awt);
	printf("Average Turnaround time:%d",atat);
}
