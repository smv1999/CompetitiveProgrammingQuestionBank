#include<stdio.h>
#include<malloc.h>
// find the sum of the entire requirements 61
// divide that by 2
// 30
#define POSSIBLE 1
#define NOT_POSSIBLE 0
int findSubsetSum(int data[], int data_size, int sum);
int findSubsetSumDP(int data[], int data_size, int sum);

int findSubsetSum_worker(int data[], int data_size, int work_ind, int sum);
int main()
{
    int petrol_requirements [] = {1 ,2 ,3 ,4 ,5 ,10 ,11 ,3 ,6 ,16  };
 //int petrol_requirements[] = {2,3,7,4,9,6,5};
    int petrol_requirements_size, possible;
    int sum=31;
    petrol_requirements_size = sizeof(petrol_requirements ) / sizeof(petrol_requirements[0]);
    possible = findSubsetSum(petrol_requirements,petrol_requirements_size, sum);
    printf("%d\n\n", possible);
    possible = findSubsetSumDP(petrol_requirements,petrol_requirements_size, sum);
    printf("\n\n%d\n\n", possible);

    return 0;
}


int findSubsetSumDP(int data[], int size, int sum)
{
    int **DP = 0;
    int data_ind, sum_ind, final_res;
    DP = (int **) calloc( (size +1 ) , sizeof(int *));
    for(data_ind = 0; data_ind <= size; data_ind++)
        DP[data_ind] = (int * ) calloc( (sum+1) , sizeof(int) );
    DP[0][0] = 1;
    for(sum_ind=1;sum_ind <= sum; sum_ind++)
        DP[0][sum_ind] = 0;
    for(data_ind=1; data_ind <= size; data_ind++)
            DP[data_ind][0] = 1;
    for(data_ind = 1; data_ind <= size; data_ind++)
    {
        for(sum_ind = 1; sum_ind <= sum; sum_ind++)
            if(sum_ind < data[data_ind-1])
               DP[data_ind][sum_ind]=DP[data_ind-1][sum_ind];
            else
                DP[data_ind][sum_ind] = DP[data_ind-1][sum_ind] ||\
                DP[data_ind-1][sum_ind - data[data_ind-1]];
    }
    for(sum_ind=0;sum_ind<=sum;sum_ind++)
        printf("%d ", sum_ind%10);
    printf("\n");
    for(data_ind=0;data_ind<= size;data_ind++, printf("\n"))
    {
        for(sum_ind=0;sum_ind <= sum; sum_ind++)
            printf("%d ", DP[data_ind][sum_ind]);
    }
    final_res = DP[size][sum];

for(data_ind = 0; data_ind <= size; data_ind++)
        free(DP[data_ind]);
        free(DP);
return final_res;
}
int findSubsetSum(int data[], int data_size, int sum)
{
    int work_ind;
    work_ind= 0;
    return findSubsetSum_worker(data, data_size, work_ind, sum);
}

int findSubsetSum_worker(int data[], int data_size, int work_ind, int sum)
{
    int incl, excl;
    if(sum == 0) return POSSIBLE;
    if(sum < 0) return NOT_POSSIBLE;
    if(work_ind == data_size) return NOT_POSSIBLE;
    // have included data[work_ind]  as a part of my solution
    incl = findSubsetSum_worker(data, data_size, work_ind+1, sum - data[work_ind]);
    // have not included data[work_ind] as a part of my solution
    excl = findSubsetSum_worker(data, data_size, work_ind+1, sum);
      return incl || excl; // 0 || 0 , 0 || 1, 1||1, 1||0
}


