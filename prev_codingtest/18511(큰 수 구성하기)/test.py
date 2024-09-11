import sys
input = sys.stdin.readline


def dfs(num):
    global ans
    if num > N:
        return
    ans = max(ans, num)

    for i in k_arr:
        dfs(num * 10 + i)


if __name__ == '__main__':
    N, K = map(int, input().split())
    k_arr = list(map(int, input().split()))

    ans = 0
    for k in k_arr:
        dfs(k)

    print(ans)