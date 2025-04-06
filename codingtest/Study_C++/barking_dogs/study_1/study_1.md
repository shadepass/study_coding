[공부블로그](https://blog.encrypted.gg/921)

# baa-arkingdog 홈페이지를 통한 공부
고수님이 올려주신 코딩테스트 대비 C++를 공부해서 c++를 우선 익히자


# 0x01강 기초 코드 작성 요령 Ⅰ
시간, 공간 복잡도
![Image](https://github.com/user-attachments/assets/60b1fda6-f953-4a34-b008-dc855a0052e1)

## 메모리 제한이 512MB 인 경우 int 변수를 대략 1.2억개 선언 가능

## 1초에 3~5억번 연산 가능

## int 자료형은 21억까지 표시할 수 있어 그이상은 오류 발생

## float은 유효숫자가 6자리, double은 유호숫자가 15자리
코딩테스트를 하면서 double 대신에 float을 써본적은 없다

실수형 비교는 동일하다고 하면안되고  
`abs(a-b) < 1e-12`  
와 같이 작성해야한다.

# 0x02강 기초 코드 작성 요령 Ⅱ
## 참조자(Reference)
```
void swap3(int& a, int& b){
    int tmp = a;
    a = b;
    b = a;
}
```
원본을 그대로 변경하는 방법

## STL(Standard Template Library)
### vector
→ 배열과 비슷한 기능 수행
가변 배열임
```
vector<int> v(100);
v[20] = 10;
v[60] = -4;
```

STL도 함수 인자로 실어 보내면 복사본을 만들어서 발송하는거라서 원본에는 변경 없음

STL을 인자로 넘기는 함수를 만드는 경우 복잡도는 O(N)이 발생
> N개를 복사하는 시간이 발생하기 때문

이때, 사용가능한 방법은 Reference 이용

```
bool cmp2(vector<int>& v1, vector<int>& v2, int idx){
    return v1[idx] > v2[idx]
}
```
→ 이렇게 사용하면 복잡도는 O(1)이 나옴, 주소값을 전달했기 때문에

## 표준 입출력
```
int main(void){
    char a[10];
    printf("input: ");
    scanf("%s", a);
    string s(a); // or string s = a;
    printf("a is %s\n", a);
    printf("s is %s\n", s.c_str());
}
```
scanf/pritnf는 c++의 string을 처리 불가  
char*으로 입력받은경우 string으로 형 변환 후 c_str() 메소드를 이용해서 출력하는게 훨씬 좋음

### 공백을 포함한 입력값 받기
```
해결책
1. scanf 옵션 활용
char a1[10];
scanf("%[^\n]", a1);

2. gets 함수(보안성 문제로 삭제 됨)
char a2[10];
gets(a2);
puts(a2;)

3. getline 함수(type이 c++ string이어야 함)
string s;
getline(cin, s);
cout << s;
```

### ios::sync_with_stdio(0)
c print/scanf와 c++ cin/cout 동기화를 끊여주는 명령어

두 stream이 동기화 되어있는데 한 입력/출력문만 사용할 꺼면 굳이 동기화할 필요가 없으므로  
두 동기화를 끊어주는 역할임

→ 다만 이렇게 했을 떄 printf와 cout을 같이 쓰면 순서가 깨짐

### cin.tie(0)
입력과 출력은 버퍼라는 공간에 입력값/출력값을 잠시 넣어놨다가 변수에 넣고/출력함

이때, 입력과 출력이 번갈아 나오고 한 화면에 보여지는 경우 버퍼로 인해서 순서가 꼬일 수 있음  
따라서, cin 명령을 수행하기전에 cout 버퍼를 비워준다. 

저지사이트는 출력 글자만 확인하기 때문에, 출력과 입력이 꼬인다고 문제가 되지 않음

따라서 굳이 필요없는 버퍼를 쓰지 않도록 하는 명령어임

위 두 명령어를 사용한 경우에는 printf/scanf 사용하면 안됨

## endl는 절때 사용하지 말 것
개행문자를 출력하고 출력 버퍼를 비워라는 명령어인데 굳이 필요없다.

## 코드작성 팁
출력 맨 마지막 공백 혹은 줄바꿈이 추가로 있어도 상관 없음
