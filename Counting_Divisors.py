import sys
input = sys.stdin.readline

MOD = 10**9 + 7

fact = []
invfact = []

def init_combinatorics(n):
    global fact, invfact
    fact = [1] * (n + 1)
    invfact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = (fact[i - 1] * i) % MOD
    invfact[n] = pow(fact[n], MOD - 2, MOD)
    
    for i in range(n, 0, -1):
        invfact[i - 1] = (invfact[i] * i) % MOD

def nCr(n, r):
    if r < 0 or r > n:
        return 0
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD

def fun(v):
    i=2
    ans=1
    v2=v
    while(i*i<=v2):
        if((v2%i)!=0):
            i+=1
            continue
        cnt=0
        while(((v2)%i)==0):
            cnt+=1
            v2=v2//i
        ans=ans*(cnt+1)
        i+=1
    if(v2>1):
        ans=ans*2
    return ans

def solve():
    n=int(input())
    for _ in  range(n):
        v=int(input())
        print(fun(v))

if __name__ == '__main__':
    t=1
    for _ in range(t):
        solve()