import sys
sys.stdin.readline

n,k=map(int,input().split())
arr=list(map(int,input().split()))

c=-1
ans=0

for i in range(len(arr)):
    if arr[i]>k:
        if c==0:
            ans+=1
        c=1
    elif arr[i]==k:
        ans+=1
        c=2
    else:
        if c==1:
            ans+=1
        c=0
        
print(ans)
