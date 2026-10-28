import sys
sys.stdin.readline

a,b=map(int,input().split())
c=a+b
d=0
while(c>0):
    d+=1
    c=c//10

print(d)