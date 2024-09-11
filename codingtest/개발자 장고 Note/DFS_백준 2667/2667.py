import sys

input = sys.stdin.readline

# 아이디어
# 정사각형 지도
# 1 집, 0 집 없는 곳
# 좌우, 아래로 연결되어 있으면 같은 단지

# 대각선은 같은 단지 아님
# 출력: 단지수, 각 단지 내 집의 개수를 내림차순으로 출력

# 입력: 지도크기(N)
# 자료구조
# 지도 배열
# 방문 여부 배열

# 복잡도
# O(NM), 재귀 복잡도도 NM 이상 안들어감

# 재귀함수(개수, [i, j])
## 4방향에서 재귀함수 호출1
### 끝에는 return으로 개수 반환
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n = int(input())
#temp = 

mapping_list = [list(map(int, list(input().strip()))) for _ in range(n)]
check_list = [[0 for _ in range(n)] for _ in range(n)]
solution = []

def DFS(count, i, j):
    if 0<= i + dy[0] < n and 0<= j+dx[0] < n\
        and mapping_list[i + dy[0]][j+dx[0]] == 1 and check_list[i + dy[0]][j+dx[0]] == 0:
        check_list[i + dy[0]][j+dx[0]] = 1
        temp = DFS(count+1, i + dy[0], j+dx[0])

    if 0<= i + dy[1] < n and 0<= j+dx[1] < n\
        and mapping_list[i + dy[1]][j+dx[1]] == 1 and check_list[i + dy[1]][j+dx[1]] == 0:
        check_list[i + dy[1]][j+dx[1]] = 1
        temp = DFS(temp+1, i + dy[1], j+dx[1])

    if 0<= i + dy[2] < n and 0<= j+dx[2] < n\
        and mapping_list[i + dy[2]][j+dx[2]] == 1 and check_list[i + dy[2]][j+dx[2]] == 0:
        check_list[i + dy[2]][j+dx[2]] = 1
        temp = DFS(temp+1, i + dy[2], j+dx[2])

    if 0<= i + dy[3] < n and 0<= j+dx[3] < n\
        and mapping_list[i + dy[3]][j+dx[3]] == 1 and check_list[i + dy[3]][j+dx[3]] == 0:
        check_list[i + dy[3]][j+dx[3]] = 1
        temp = DFS(temp+1, i + dy[3], j+dx[3])

    return temp

for i in range(n):
    for j in range(n):
        '''
        if 0<= i + dy[k] < n and 0 <= j + dx[k] < n \
            and map_list[i + dy[k]][j + dx[k]] == 1 and \
                check_list[i + dy[k]][j + dx[k]]== 0:
            DFS(0,  )
        '''
        if mapping_list[i][j] == 1 and check_list[i][j] == 0:
            solution.append(DFS(0, i, j))



# 오른쪽 우선으로 전체 그래프 탐색


# 그래프가 집이면 재귀함수 호출

