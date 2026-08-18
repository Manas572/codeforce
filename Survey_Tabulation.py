n=int(input())
vec=[]
for i in range(n):
    s=input()
    s=s.lower()
    vec.append(s)

freq={}
for st in vec:
    freq[st]=freq.get(st,0)+1

m=max(freq.values())
print(m)

