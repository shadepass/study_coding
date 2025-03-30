# 0x03강 배열
## 배열의 성질
1. O(1)에 K번째 원소를 확인/변경 가능
2. 추가적으로 소모되는 메모리의 양(overhead)가 거의 없음
3. Cache hit rate가 높음
4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림


## 기능과 구현
임의의 위치에 있는 원소를 확인/변경, O(1)
원소를 끝에 배치, O(1)
마지막 원소 제거, O(1)
임의의 위치에 원소 추가 O(N)
임의의 위치에 원소 삭제 O(N)

### 사용 팁
특정 값 초기화 방법들
```
//1. memset
int a[21];
int b[21][21];
memset(a, 0, sizeof(a))
memset(b, 0, sizeof(b))

//2. for
for (int i =0; i<21; i++)
    a[i] = 0;
for(int i = 0; i<21; i++)
    for(int j = 0; j<21; j++)
        b[i][j] = 0;

//3. fill
fill(a, a+21, 0);
for(int i = 0; i< 21; i++)
    fill(b[i], b[i]+21, 0)
```
fill을 가장 추천함

## STL vector
C++의 STL vecotㄱ은 배열과 거의 동일한 기능을 수행하는 자료구조로 메모리에 연속으로 저장되어 있어,  
O(1)에 인덱스를 가지고 각 원소에 접근할수 있음

그런데 Vector는 배열과 달리 크기를 자유자재로 늘리거나 줄일 수 있음

1. insert, erase는 시간복잡도 O(N)
2. push_back, pop_back O(1)
3. vector 에서 '='는 deep copy 수행 

```
#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> v1(3, 5);
    cout << v1.size() << '\n';
    v1.push_back(7);

    vector<int> v2(2);
    v2.insert(v2.begin()+1, 3);

    vector<int> v3 = {1, 2, 3, 4}'
    v3.erase(v3.begin() + 2);

    vector<int> v4;
    v4 = v3;
    cout << v[0] << v[1]0 << v[2] << '\n';
    v4.pop_back();
    v4.clear()
}
```
### STL Vector iterator
```
for(vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
```
STL vector에 모든 요소에 접근하기 위한 반복자 개념

### STL Vector 모든 원소에 접근하기
```
vector<int> v1 = {1, 2, 3, 4, 5, 6};

1. range-based for loop
for(int e : v1)
    cout << e << ' ';
2.
for(int i = 0; i < v1.size(); i++)
    cout << v1[i] << ' ';

3. very wrong
for(int i = 0; i < v1.size()-1; i++)
    cout << v1[i] << '';
```
1번은 e에 v1의 원소들이 하나씩 들어가면서 for 문이됨
> python의 for문과 동일한 기능 수행  

하지만 int e : v1은 단순 deepcopy 지만  
int& e : v1 으로 넣으면 e 변경 시 v1도 변경되게 된다.

또한, 3번 방법은 `v1.size()`가 unsigned int를 출력하므로  
위와같은 방법으로 하면 unsigned int - int 꼴이 되서 예상하지 못한 오류가 발생할 수 있다.

