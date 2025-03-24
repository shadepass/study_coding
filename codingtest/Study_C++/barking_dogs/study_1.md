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