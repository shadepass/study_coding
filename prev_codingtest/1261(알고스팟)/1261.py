import sys
input = sys.stdin.readline

M, N = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(N)]
dp_maze = [[-1 for _ in range(M)] for _ in range(N)]

#print()

#for i in range(M):
#    dp_maze[0][i] = maze[0][i]

dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]

if M > N:
    line = M
else:
    line = N
for _ in range(line):
     for i in range(N):
        for j in range(M):
            min = 99999
            for k in range(0, 4):        
                temp_j = j + dx[k]
                temp_i = i + dy[k]
                if 0 <= temp_j < M and 0 <= temp_i < N and dp_maze[temp_i][temp_j] != -1:
                    if maze[i][j] + dp_maze[temp_i][temp_j] < min:
                        min = maze[i][j] + dp_maze[temp_i][temp_j]
    #            elif 0 <= temp_j < M and 0 <= temp_i < N:
    #                if maze[i][j] < min:
    #                   min = maze[i][j]
            if i == 0 and j == 0:
                dp_maze[i][j] = 0
            elif min == 99999:
                dp_maze[i][j] = maze[i][j]
            else:
                dp_maze[i][j] = min

print(dp_maze[N-1][M-1])