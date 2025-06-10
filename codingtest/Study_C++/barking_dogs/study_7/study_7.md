# BFS(Breadth First Search)
다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘

복잡도 = O(N)  
모든 배열에 한번씩 들어가야하므로

## 예시
```c++
#include <btis/stdc++.h>
using namespace std;

int main(void){
    pair<int, int> t1 = make_pair(10, 13);
    pair<int, int> t2 = {4, 6}; // c++11
    cout << t2.first << ' ' << t2.second << '\n';
    if (t2 < t1) cout << "t2 < t1\n";
    }
```
pair: 두 자료형을 한번에 묶어서 넣을 수 있는 STL
