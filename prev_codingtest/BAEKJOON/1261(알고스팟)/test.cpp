#include <cstdio>
#include <deque>  //deque를 활용하기 위한 import
#define MAX 100
using namespace std;

int n, m, ans;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 1,0,0,-1 }; //가로 이동
int dy[] = { 0,1,-1,0 }; //세로 이동

struct Info{
	int x, y, sum;
};
 
void bfs() {
	deque<Info> deq;
	deq.push_back({ 0,0,0 });
	visited[0][0] = 1;
	while (!deq.empty())
	{
		auto cur = deq.front(); deq.pop_front();
		int x = cur.x;
		int y = cur.y;
		int sum = cur.sum;
		if (x == n - 1 && y == m - 1) {
			printf("%d ", sum);
			return;
		}
        //핵심 코드 부분
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			if (map[nx][ny]) {// 가중치가 1이면
				deq.push_back({ nx,ny,sum + 1 });
			}
			else deq.push_front({ nx,ny,sum });
			
		}
	}
	return;
}

int main() {

	 scanf("%d %d", &m, &n);
	 for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &map[i][j]); 
		} 
	bfs();
	return 0;
}