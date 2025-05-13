# 0x05강 스택
## 정의와 성질
### 스택의 성질
원소의 추가가 O(1)  
원소의 제거가 O(1)  
제일 상단의 원소 확인이 O(1)  
제일 상단이 아닌 나머지 원소에 대한 확인은 원칙적으로 불가  
```C++
const int MX = 100005;
int dat[MX];
int pos = 0;
```

## STL 스택 예시
```c++
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  stack<int> S;
  S.push(10); // 10
  S.push(20); // 10 20
  S.push(30); // 10 20 30
  cout << S.size() << '\n'; // 3
  if(S.empty()) cout << "S is empty\n";
  else cout << "S is not empty\n"; // S is not empty
  S.pop(); // 10 20
  cout << S.top() << '\n'; // 20
  S.pop(); // 10
  cout << S.top() << '\n'; // 10
  S.pop(); // empty
  if(S.empty()) cout << "S is empty\n"; // S is empty
  cout << S.top() << '\n'; // runtime error 발생
}
```

스택이 비어있을 때 top/pop 함수는 Rutnime error 발생
