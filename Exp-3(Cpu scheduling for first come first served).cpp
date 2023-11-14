#include<stdio.h>
int main()
{
	int n,i;
	int bursttime[n],waitingtime[n],turnaroundtime[n],totalwt,totaltt;
	float awt,atat;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter burst time for each process:\n");
	for(i=1;i<=n;i++)
	{
		printf("P%d:",i);
		scanf("%d",&bursttime[i]);
	}
	waitingtime[1]=0;
	for(i=2;i<=n;i++)
	{
		waitingtime[i]=waitingtime[i-1]+bursttime[i-1];
		totalwt=totalwt+waitingtime[i];
	}
	for(i=1;i<=n;i++)
	{
		turnaroundtime[i]=waitingtime[i]+bursttime[i];
		totaltt=totaltt+turnaroundtime[i];
	}
	awt=totalwt/n;
	atat=totaltt/n;
	printf("\nProcess\tBursttime\tWaitingtime\tTurnaroundtime\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\n",i,bursttime[i],waitingtime[i],turnaroundtime[i]);
	}
		printf("Average waitingtime:%.2f",awt);
		printf("\nAverage turnaround time:%.2f",atat);
}
