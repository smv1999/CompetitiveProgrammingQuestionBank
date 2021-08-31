#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four (int a, int b, int c, int d){
   int e= max(a, max(b, max(c,d)));
   return e;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
