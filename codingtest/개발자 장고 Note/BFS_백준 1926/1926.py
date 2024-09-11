import sys
from collections import deque
# 개수 가지고 있는 리스트

input = sys.stdin.readline
n, m = map(int, input().split())
backboard = [list(map(int, input().split())) for _ in range(n)]
check_list = [[0 for _ in range(m)] for _ in range(n)]
size = 0
solution = []
BFS_list = deque()
current_x, current_y = 0, 0

#print(backboard)

while current_x < m and current_y < n:
    if backboard[current_y][current_x] == 1 and check_list[current_y][current_x] == 0:
        check_list[current_y][current_x] = 1
        temp_y, temp_x = current_y, current_x
        size += 1
        while True:
            if temp_x + 1 < m and backboard[temp_y][temp_x+1] == 1 and \
                                  check_list[temp_y][temp_x+1] == 0:
                BFS_list.append([temp_y, temp_x+1])
                check_list[temp_y][temp_x+1] = 1
                size += 1
            if temp_y + 1 < n and backboard[temp_y+1][temp_x] == 1 and\
                                  check_list[temp_y+1][temp_x] == 0:
                BFS_list.append([temp_y+1, temp_x])
                check_list[temp_y+1][temp_x] = 1
                size += 1
            if temp_y - 1 >=0  and backboard[temp_y - 1][temp_x] == 1 and\
                                  check_list[temp_y - 1][temp_x] == 0:
                BFS_list.append([temp_y - 1, temp_x])
                check_list[temp_y - 1][temp_x] = 1
                size += 1
            if temp_x - 1 >= 0 and backboard[temp_y][temp_x - 1] == 1 and\
                                  check_list[temp_y][temp_x - 1] == 0:
                BFS_list.append([temp_y, temp_x - 1])
                check_list[temp_y][temp_x - 1] = 1
                size += 1
            
            if not BFS_list:
                break
            temp_y, temp_x = BFS_list.popleft()
        solution.append(size)
        size = 0
    
    if current_x + 1 < m:
        current_x += 1
    elif current_y +1 < n:
        current_x = 0
        current_y += 1
    else:
        break

if not solution:
    print(0)
    print(0)
else:
    solution.sort()
    print(len(solution))
    print(solution[-1])