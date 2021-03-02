// Problem taken from Binary Search

// Problem Statement :
//      You are given two strings 'typed' and 'target'.
//  You want to write 'target' but the keyboard is stuck so some characters may be written
//  one or more times. Return whether it's possible that 'typed' was meant to write 'target'

// Example :
//      Sample Input - 1 :
//          typed = "aaabcccc"
//          target = "abc"
//      Sample Output - 1 : 
//          true

//      Sample Input - 2 :
//          typed = "abc"
//          target = "ab"
//      Sample Output - 2 : 
//          false


bool solve(string typed, string target) {
    if(typed.size() == 0 && target.size() == 0)
        return true;
    int i = 0 , j = 0;
    int cnt1 , cnt2;
    while(i < typed.size() && j < target.size()) {
        int x = i + 1;
        int y = j + 1;
        while(x < typed.size() && typed[i] == typed[x]) {
            x++;
        }
        while(y < target.size() && target[j] == target[y]) {
            y++;
        }
        cnt1 = x - i;
        cnt2 = y - j;
        if(target[j] == typed[i]) {
            if(cnt1 < cnt2)
                return false;
        } else 
            return false;
        i = x;
        j = y;
    }
    if(cnt1 >= cnt2 && target[j] == typed[i])
        return true;
    return false;
}

    