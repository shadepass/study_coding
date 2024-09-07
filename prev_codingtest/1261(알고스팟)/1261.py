import sys
input = sys.stdin.readline

M, N = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(N)]
dp_maze = [[0 for _ in range(M)] for _ in range(N)]

print()