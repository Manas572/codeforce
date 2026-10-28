import sys
input = sys.stdin.buffer.readline

MOD = 10**9 + 7

q = int(input())
ans = []

for _ in range(q):
    a, b = map(int, input().split())
    ans.append(str(pow(a, b, MOD)))

sys.stdout.write("\n".join(ans))