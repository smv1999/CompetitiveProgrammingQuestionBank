/*Write a program to implement the job sequencing with  deadline problem using greedy method. Consider the  
following data for the problem. N=4 

    JOB:        J1   J2   J3   J4
    PROFIT:     100  10   15   27
    DEADLINE:    2    1   2     1
*/

#include <stdio.h>

// Structure of each job
struct job
{
    int id;
    int profit;
    int deadline;
};

/* Auxiliary Functions */

int scanJobs(struct job Jobs[], int n)
{
    // Scan n number of jobs
    int i, max_deadline = 0;
    for (i = 0; i < n; i++)
    {
        printf("Enter the profit and deadline of job (J%d): ", i + 1);
        scanf("%d %d", &Jobs[i].profit, &Jobs[i].deadline);
        Jobs[i].id = i + 1;
        if (Jobs[i].deadline > max_deadline)
        {
            max_deadline = Jobs[i].deadline;
        }
    }
    return max_deadline;
}

void sort(struct job Jobs[], int n)
{
    // Sort the job in descending order of profit
    int i, j;
    struct job key;
    for (i = 1; i < n; i++)
    {
        key = Jobs[i];
        j = i - 1;
        while ((j >= 0) && (Jobs[j].profit < key.profit))
        {
            Jobs[j + 1] = Jobs[j];
            j--;
        }
        Jobs[j + 1] = key;
    }
}

int isEmpty(int arr[], int i)
{
    // Returns True if i'th slot of an array is empty
    return arr[i] == 0 ? 1 : 0;
}

void initSlots(int arr[], int m)
{
    // Initialise job slots to 0
    int i;
    for (i = 0; i < m; i++)
    {
        arr[i] = 0;
    }
}

int job_sequencing(struct job Jobs[], int m)
{
    // Job sequencing function
    int slots[m], profit = 0;
    initSlots(slots, m);
    int i, j, deadlineIdx;
    for (i = 0; i < m; i++)
    {
        deadlineIdx = Jobs[i].deadline - 1;
        if (isEmpty(slots, deadlineIdx))
        {
            slots[deadlineIdx] = Jobs[i].id;
            profit += Jobs[i].profit;
        }
        else
        {
            for (j = deadlineIdx - 1; j >= 0; j--)
            {
                if (isEmpty(slots, j))
                {
                    slots[j] = Jobs[i].id;
                    profit += Jobs[i].profit;
                }
            }
        }
    }
    printf("\nJobs sequence: { ");
    for (i = 0; i < m; i++)
    {
        printf("J%d ", slots[i]);
    }
    printf("}");
    return profit;
}

int main()
{
    int n, m, max_profit;
    /* 
        n: number of jobs
        m: number of job slots
    */
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct job Jobs[n];
    m = scanJobs(Jobs, n);
    sort(Jobs, n);
    max_profit = job_sequencing(Jobs, m);
    printf("\nOptimal maximum profit: %d\n", max_profit);
    return 0;
}