import sys
input = sys.stdin.buffer.readline

MOD = 10**9 + 7

q = int(input())
ans = []

for _ in range(q):
    a, b,c = map(int, input().split())
    d=pow(b,c,MOD-1)
    ans.append(str(pow(a, d, MOD)))

sys.stdout.write("\n".join(ans))