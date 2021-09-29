/* Maximum difference in an array
Problem Statement Given an array of integers, a, return the maximum difference of any
pair of numbers such that the larger integer in the pair occurs at a higher index (in the
array) than the smaller integer. Return -1 if you cannot find a pair that satisfies this
condition.
Constraints: 1 ≤ N ≤ 1,000,000 -1,000,000 ≤ a[i] ≤ 1,000,000 ∀ i ∈ [0, N-1]
Input Format:
The first line of the input is N (the number of elements in the array), and then followed
by N elements each in a separate line.
Sample Input 0:
8
Explanation 0:
For the array { 2,3,10,2,4,8,1} given above, 10 is the largest number in the array and 1
is the smallest number in the array. However, the index of 10 is lower than the lowest
index that contains a 1 so the condition of the problem is not satisfied. Using zero-based
index notation, the correct answer is a[2] - a[0] = 10 - 2 = 8. This satisfies the condition
that the larger number in the pair should be positioned at a higher index in the array
than the smaller number.
Sample Input 1:
6
7
9
5
6
3
2
Sample Output 1:
2
Explanation 1:
The value of maxDifference is 9 - 7 = 2. 9 occurs at a[1] and 7 occurs at a[0]. This
satisfies the condition that the larger number must have a higher index than the smaller
number.*/


#include<stdio.h>
void max_diff(int a[], int n){
	int i,j,max;
	max = a[0] - a[1];
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if((a[j] -a[i])>max && a[j] > a[i] && j>i ){
				max = a[j] - a[i];
			} 
		}
	}
	printf("max difference = %d",max);
}
int main(){
	int n,i,a[50];
	printf("enter number of elements in array: ");
	scanf("%d",&n);
	printf("enter the %d elements of array: \n",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	max_diff(a,n);
	return 0;
}


/* OUTPUT: 
enter number of elements in the array: 7
enter the 7 elements of the array:
2
3
10
2
4
8
1
max difference = 8
*/
