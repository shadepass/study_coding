# 큐
## 정의와 성질
FIFO

원소의 추가가 O(1)
원소의 삭제가 O(1)
제일 앞/뒤 원소 확인 O(1)
나머지 원소는 원칙적으로 확인 불가

## 기능과 구현 
배열을 이용해서 큐 구현 가능
```c++
const int MAX = 10000005;
int dat[MX];
int head= 0; tail = 0;
```
push 할 때는, tail 증가, pop 할 때는 head 증가로 구현가능  

하지만 이렇게 배열을 가지고 구현하는 경우 앞에 쓸 수 있는 공간을 못 쓰게 됨  

따라서, 원형으로 구현(아이디어만), 실제로는 8개의 배열인 경우 7 인덱스에서 다시 9으로 돌아가게 설정  

## STL 큐
```C++
#include <bits/stdc++.h>
using namespace std;

int main(void){
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    cout << Q.size() << '\n';
    if (Q.empty()) cout << "Q is empty\n";
    else cout << "Q is not empty\n";
    Q.pop();
    cout << Q.front() << "\n";
    cout << Q.back() << "\n";
    Q.push(40);
    Q.pop();
    cout << Q.front() << "\n";
}
```
당연히 큐가 비어있는데 front, back, pop 호출 시 런타임 에러 발생


# 덱
## 정의와 성질
덱은 Restricted Structure의 끝판왕  
양쪽 끝에서 삭제와 삽입이 전부 가능  
덱 == deque == Double Ended Queue  

원소의 추가가 O(1)
원소의 삭제가 O(1)
원소의 앞, 뒤 원소 확인 O(1)
앞, 뒤가 아닌 원소는 원칙적으로 확인 불가

## 기능과 구현
```c++
const int MX = 10000005;
int dat[2*MX + 1];
int head = MX, tail = MX;
```
→ 양쪽으로 확장하기 위해서 head와 tail을 가운데에 위치

마찬가지로 원형으로 구현할 수 도 있지만, 배열을 크게 잡으면 되는거니깐 선형으로 구현 가능

## STL deque
vector와 비슷하지만 front에서도 O(1)에 추가와 제거가 가능하므로 상위호환 느낌
하지만 deque는 vector와 달리 연속한 주소를 가지고 있지 않음
```c++
include <bits/stdc++.h>
using namespace std;

int main(void){
    deque<int> DQ;
    DQ.push_front(10);
    DQ.push_back(50);
    DQ.push_front(24);
    for(auto x : DQ) cout << x << ' ';
    cout << DQ.size() << '\n';
    if(DQ.empty()) cout << "DQ is empty\n";
    else cout << "DQ is not empty\n";
    DQ.pop_front();
    DQ.pop_back();
    cout << DQ.back() << '\n';
    DQ.push_back(72);
    cout << DQ.front() << '\n';
    DQ.push_back(12);
    DQ[2] = 17;
    DQ.insert(DQ.begin() + 1, 33);
    DQ.insert(DQ.begin() + 4, 60);
    for (auto x: DQ) cout << x << ' ';
    cout << '\n';
    DQ.erase(DQ.begin()+3);
    cout << DQ[3] <<'n';
    DQ.clear();
}
```

[레퍼런스링크]<https://cplusplus.com/reference/deque/deque/>

