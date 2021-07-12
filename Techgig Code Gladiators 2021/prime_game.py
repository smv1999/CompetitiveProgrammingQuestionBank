def main():
    
    T = int(input())
    def isprime(n):
        if n<=1:
            return False
        for i in range(2,n):
            if n%i ==0:
                return False
        return True
    
    # to run each testcase
    while testCase >0:
        LR = list(map(int,input().strip().split()))
        L = LR[0]
        R = LR[1]
        f = 0
        l = 0
        for i in range(L,R+1):
            if f ==0:
                if isprime(i):
                    f=i
                else:
                    i = i+1
            if l==0:
                if isprime(R):
                    l=R
                else:
                    R -=1
            if f!=0 and l!=0:
                break
            
        if f!=0 and l!=0:
            print(l-f)
        else:
            print(-1)
        
        T -=1

main()
