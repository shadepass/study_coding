# 0x04강 연결리스트
## 정의와 성질
1. k번째 원소를 확인/변경 하기 위해 O(k)가 필요
2. 임의의 위치에 원소를 추가/임의 위치의 원소 제거는 O(1)
3. 원소들이 메모리 상에 연속해있지 않아 Cache hit rate가 낮지만 할당이 다소 쉬움

### 연결리스트 종류
단일 연결 리스트  
이중 연결 리스트
 - STL에 있으며, 'list' 컨테이너로 활용    
원형 연결 리스트

> 연결리스트는 배열에 비해 추가적으로 O(N) 만큼 공간 더 필요

### 대표적이 활용처
메모장과 텍스트 에디터  
임의의 위치에 원소를 추가하거나, 임의 위치에 제거하는 연산을 많이 하는 경우

### 연결리스트의 구현
```
struct NODE {
    struct NODE * prev, *next;
    int data;
}
```  
보통은 STL에 있는 LIST를 사용하면됨

### 야매 연결리스트
```
const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

fill(pre, pre+MX, -1);
fill(nxt, nxt+MX, -1);
```
원소를 배열로 관리하고 pre와 nxt에 이전/다음 원소의 포인터 대신 배열 상의 인덱스를 저장하는 방식  
메모리를 대따 많이 먹기 때문에 현실에서는 사용안하겠지만 코테에서는 사용 가능  

0번지는 dummy node로 예외처리 시 활용도가 높음  

```
// 모든 값을 출력하는 함수
void traverse() {
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}
```

## STL List
STL list에서 push_back, pop_back, push_front, pop_front 모두 O(1)

번지(주소) → iterator

STL list에서는 제일 앞이 아닌 제일 뒤가 더미 노드
> L.begin()은 제일 앞에 있는 원소 / L.end()는 제일 뒤에 있는 원소의 한 칸 뒤

```c++
int main(void){
    list<int> L = {1, 2}; // 1, 2
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
    L.push_front(10); // 10 1 2
    cout << *t << '\n'; // t가 가리키는 값, 1을 출력
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
    t++; // t를 뒤로 증가, 2를 가르킴
    t = L.erase(t); // t가 가르키는 값 제거, 다음 원소인 5의 위치 반환
                    // 10 6 1 5, t가 가리키는 값은 5
    cout << *t << '\n'; //5
    for(auto i : L) cout << i << ' ' ;
    cout << 'n';
    for(list<int>iterator it = L.begin(); it != L.end(); it++)
        cout << *it << ' ';
}
```
## 손코딩 문제
1. 원형 연결 리스트 내의 임의의 노드 하나가 주어졌을 때, 해당 List의 길이를 효율적으로 구하는 방법
 - 앞 뒤로 가면서 끝에 닿을 때까지 간다
 - O(n)

2. 중간에 만나는 두 연결 리스트의 시작점들이 주어졌을 때, 만나는 지점을 구하는 방법은
 - 주소값을 하나씩 배열로 만든다음에 +1, 씩 했는데 +2가 되는 지점 식별..?
 - 두 리스트를 끝까지 이동한 다음에, 두 리스트의 길이 차이만큼을 길이가 긴 리스트에서 먼저 이동시킨다음에, 이제 하나씩 같이 이동하면서 비교하면 같은 값이 나옴  
> 공간복잡도O(1), 시간복잡도 O(A+B)

3. 주어진 연결 리스트에서 사이클이 있는지 판단
 - 정답 Floyd's cycle-finding algorithm, 공간복잡도 O(1), 시간복잡도 O(N)
 - 한칸 씩 가는 커서와, 두칸씩 가는 커서를 동일한 지점에서 출발 했을 떄, 사이클이 있는경우 무조건 만나게 되있다는 점을 이용
 