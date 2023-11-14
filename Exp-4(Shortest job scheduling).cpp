#include<stdio.h>
int main()
{
	int i,j,n,temp;
	int bursttime[n],waitingtime[n],turnaroundtime[n];
	float awt=0,atat=0;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter burst time for each process:\n");
	for(i=1;i<=n;i++)
	{
		printf("P%d:",i);
		scanf("%d",&bursttime[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(bursttime[i]>bursttime[j])
			{
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
	printf("\nProcess\tBursttime\tWaitingtime\tTurnarondtime\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\n",i,bursttime[i],waitingtime[i],turnaroundtime[i]);
	}
	printf("Average waiting time:%f",awt);
	printf("Average turnaroundtime:%f",atat);
	return 0;
}
