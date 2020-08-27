#include<stdio.h>
#include<stdlib.h>

int main()
{

    int N;
    scanf("%d", &N);
    int input[N], ind, rem;
    for(ind=0;ind<N;ind++) scanf("%d", &input[ind]); // 8 7 6 4
    int two_digits[22], two_digits_ind;
    unsigned long long int res = 0;
    two_digits[0] = 1;
    for(two_digits_ind=1;two_digits_ind<22;two_digits_ind++)
        two_digits[two_digits_ind] = ((two_digits[two_digits_ind-1])*2)%100;

    for(ind=0;ind<N;ind++)
    {
        if(input[ind]>21)
        {
            rem = input[ind] % 22;
            rem += 2;
        }
        else rem = input[ind];
        res = res + two_digits[rem];
    }

    printf("%llu", res%100);
    return 0;
}
