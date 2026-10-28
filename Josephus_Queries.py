import sys
input=sys.stdin.readline

q=int(input())
for _ in range(q):
    n,k= map(int,input().split())
    if k<=n/2:
        print(k*2)
        continue
    else:
        b=(n & 1)
        cnt=n//2
        d=4
        st=1
        fir=1
        rem=n-cnt
        if b==0:
            st=3
        while(cnt<k):
            v=(n-st+d)//d
            if cnt+v<k:
                cnt+=v
                if st==fir:
                    fir+=d//2
                    ends=(rem%2==0)
                else:
                    ends=(rem%2!=0)
                if ends:
                    st=fir
                else:
                    st=fir+d
                rem-=v
                if rem==1:
                    st=fir
            else:
                print(st+((k-cnt-1)*d))
                break
            d=d*2