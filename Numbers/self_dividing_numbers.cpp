/*
Src : LeetCode
--------------

A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
*/

class Solution {
public:
    bool isSelfDividing(int num){
        int r, k = num;
        bool flag = true;
        while(num > 0)
        {
            r = num % 10;
            if(r == 0)
            {
                 flag = false;
                 break;
            }   
            if(k % r != 0)
                flag = false;
            num /= 10;
        }
        return flag;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        cout << isSelfDividing(21);
        for(int num = left ; num <= right ; num++)
        {
            if(isSelfDividing(num))
                res.push_back(num);
        }
        return res;
    }
};