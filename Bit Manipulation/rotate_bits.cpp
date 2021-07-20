/*A rotation (or circular shift) is an operation similar to shift except that the
bits that fall off at one end are put back to the other end. 
In left rotation, the bits that fall off at left end are put back at right end. 
In right rotation, the bits that fall off at right end are put back at left end.
*/

#include <bits/stdc++.h> 
using namespace std; 

// Left Rotate 'cnt' number of bits of the given number 'n'
int left_rotate_bits(int n, int cnt)
{
    int msb;
    
    // 32 is the total number of bits used to store an INT variable in C++
    for(cnt = cnt % 31;cnt>0;cnt--)
    {
        //Store the current MSB in a temporary variable
        msb = (n >> 31) & 1;
        //Left rotate the given number by one bit
        n = (n<<1);
        //Set the dropped MSB as the new LSB
        n = n | msb;
    }
    return n;
}

// Right Rotate 'cnt' number of bits of the given number 'n'
int right_rotate_bits(int n, int cnt)
{
    int lsb;
    
    // 32 is the total number of bits used to store an INT variable in C++
    for(cnt = cnt % 31;cnt>0;cnt--)
    {
        //Store the current LSB in a temporary variable
        lsb = n & 1;
        //Right rotate the given number by one bit and drop its LSB
        n = (n >> 1) & (~(1 << 31));
        //Set the dropped LSB as the new MSB
        n = n | (lsb << 31);
    }
    return n;
}


int main()
{
    int n,cnt,left,right;
    cout<<"\nEnter the number : ";
    cin>>n;

    cout<<"How many bits do you want to rotate : ";
    cin>>cnt;
  
    //Call the sort function 
    left = left_rotate_bits(n, cnt);  
    right = right_rotate_bits(n,cnt);

    cout<<"The Left-rotated number is : "<<left<<endl;
    cout<<"The Right-rotated number is : "<<right<<endl;

    return 0;
}

/*
INPUT 
Enter the number : 39
How many bits do you want to rotate : 17
OUTPUT
The Left-rotated number is : 5111808 
The Right-rotated number is : 1277952

Time Complexity: O(n)
Space Complexity: O(1)
*/