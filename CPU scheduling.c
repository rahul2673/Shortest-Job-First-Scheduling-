/*
Consider a scheduling approach which is non pre-emptive similar to shortest job next in nature. The priority of each job is dependent on
its estimated run time, and also the amount of time it has spent waiting. Jobs gain higher priority the longer they wait, which prevents
indefinite postponement. The jobs that have spent a long time waiting compete against those estimated to have short run times. 
The priority can be computed as :
Priority = 1+ Waiting time / Estimated run time
Using the data given below compute the waiting time and turnaround time for each process and average waiting time and average turnaround
time.

Process	 Arrival  time	Burst time
 P1	        0	         20
 P2	        5	         36
 P3	       13	         19
 P4	       17	         42
*/
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
int n;
struct process
{
int p_no;
int arrival_time,burst_time,ctime,wait_time1,taround_time,p;
int priority;
int flag;
}
p1_list[100];
 void Sorting()
 {
struct process p;
int q, r;
for(q=0;q<n-1;q++)
{
for(r=q+1;r<n;r++)
{
if(p1_list[q].arrival_time > p1_list[r].arrival_time)
{
p = p1_list[q];
p1_list[q] = p1_list[r];
p1_list[r] = p;
}
}
}
 }  
 void Sorting2()
 {
    struct process p;
    int q, r;
for(q=0;q<n-1;q++)
{
for(r=q+1;r<n;r++)
{
if(p1_list[q].priority < p1_list[r].priority)
{
p = p1_list[q];
p1_list[q] = p1_list[r];
p1_list[r] = p;
}
}
}
} 
 int main()
 {
  int i,t=0,b_t=0,peak;
  int a[10];
  float wait_time = 0, taround_time = 0, avg_w_t1=0, avg_taround_time1=0;
  printf("enter the no. of processes: ");
  scanf("%d",&n);
  for(i = 0; i < n; i++)
{
p1_list[i].p_no = i+1;
printf("\nEnter Details For P%d process:-\n", p1_list[i].p_no);
printf("Enter Arrival Time: ");
scanf("%d", &p1_list[i].arrival_time );
printf("Enter Burst Time: ");
scanf("%d", &p1_list[i].burst_time);
p1_list[i].flag = 0;
b_t = b_t + p1_list[i].burst_time;
}
Sorting();
for(i=0;i<n;i++)
{
a[i]=p1_list[i].burst_time;
}
p1_list[9].burst_time = 9999;
for(t = p1_list[0].arrival_time; t <= b_t+1;)
{
peak = 9;
for(i=0;i<n;i++)
{
if(p1_list[i].arrival_time <= t && p1_list[i].burst_time < p1_list[peak].burst_time && p1_list[i].flag != 1)
{
peak = i;
}
if(p1_list[peak].burst_time==0 && p1_list[i].flag != 1)
{
p1_list[i].flag = 1;
p1_list[peak].ctime=t;p1_list[peak].burst_time=9999;
printf("P%d completes in %d\n",p1_list[i].p_no,p1_list[peak].ctime);
}
}
t++;
(p1_list[peak].burst_time)--;
}
for(i=0;i<n;i++)
{
p1_list[i].taround_time=(p1_list[i].ctime)-(p1_list[i].arrival_time);
avg_taround_time1=avg_taround_time1+p1_list[i].taround_time;
p1_list[i].wait_time1=((p1_list[i].taround_time)-a[i]);
p1_list[i].priority=1+(p1_list[i].wait_time1%p1_list[i].burst_time);
avg_w_t1=avg_w_t1+p1_list[i].wait_time1;
}
printf("PNO\tAT\tCT\tTA\tWTt\t Priority\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p1_list[i].p_no,p1_list[i].arrival_time,p1_list[i].ctime,p1_list[i].taround_time
,p1_list[i].wait_time1,p1_list[i].priority);}
printf("Average Turn around Time: %f\t\n\n",avg_taround_time1);
printf("Average Waiting Time :\t %f\t\n",avg_w_t1);
Sorting2();
printf("\nPNO\tAT\tCT\tTA\tWTt\t Priority\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p1_list[i].p_no,p1_list[i].arrival_time,p1_list[i].ctime,p1_list[i].taround_time
,p1_list[i].wait_time1,p1_list[i].priority);
}
printf("\n\n therefore the process are listed in terms of priority in descending order");
printf("\n therefore the process with higher priority will be executed first than the process with lowest priority.");
return 0;
}

