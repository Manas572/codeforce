from collections import defaultdict
import sys
import heapq
input=sys.stdin.readline
n=int(input())

dic= defaultdict(int)
heap=[]
for i in range(n):
    s=input().strip()
    if s in dic:
        print(dic[s])
    else:
        if not heap :
            heapq.heappush(heap,-1)
            dic[s]=1
        else:
            v=-1*heapq.heappop(heap)
            v+=1
            heapq.heappush(heap,-1*v)
            dic[s]=v
        print(dic[s])
