/*
    Program to execute Round Robin algorithm to perform process scheduling.
*/
#include <stdio.h>

int main()
{

    int p_id, n = 0, j, time, remaining, flag = 0, time_quantum;
    /*
        at = Ariving Time
        bt = Burst Time
        rt = Remaining Burst Time
        remaining = remaining processes
        p_id = process id
    */
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    printf("Enter Total number of Processes: ");
    scanf("%d", &n);
    remaining = n;
    for (p_id = 0; p_id < n; p_id++)
    {
        printf("Enter Arrival Time and Burst Time for Process process number %d :", p_id + 1);
        scanf("%d", &at[p_id]);
        scanf("%d", &bt[p_id]);
        rt[p_id] = bt[p_id];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d", &time_quantum);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for (time = 0, p_id = 0; remaining != 0;)
    {
        if (rt[p_id] <= time_quantum && rt[p_id] > 0)
        {
            time += rt[p_id];
            rt[p_id] = 0;
            flag = 1;
        }
        else if (rt[p_id] > 0)
        {
            rt[p_id] -= time_quantum;
            time += time_quantum;
        }
        if (rt[p_id] == 0 && flag == 1)
        {
            remaining--;
            printf("P[%d]\t|\t%d\t|\t%d\n", p_id + 1, time - at[p_id], time - at[p_id] - bt[p_id]);
            wait_time += time - at[p_id] - bt[p_id];
            turnaround_time += time - at[p_id];
            flag = 0;
        }
        if (p_id == n - 1)
            p_id = 0;
        else if (at[p_id + 1] <= time)
            p_id++;
        else
            p_id = 0;
    }
    printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
    printf("Average Turnaround Time = %f", turnaround_time * 1.0 / n);

    return 0;
}
