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
메모리를 대따 많이 먹기 때문에 현실에서는 사용안하겟지만 코테에서는 사용 가능  

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
