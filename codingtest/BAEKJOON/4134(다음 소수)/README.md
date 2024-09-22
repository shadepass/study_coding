# 백준_4134(다음 소수)

## 난이도: Silver 4
## 문제: [백준](https://www.acmicpc.net/problem/4134)

## 문제해석
- n(0 <= n <= 4*10^9)인 n보다 크거나 같은 소수 중 가장 작은 소수
- 입력: 첫째 줄에 테스트 케이스 개수, 이어서 정수 n
- 출력: 한줄에 하나씩 크거나 같은 소수 출력

## 문제풀이💬
- 에르토스테네스의 체 이용해서 소수 식별하자
- 입력받은 수 제곱근 취해서 제곱근보다 낮은 수의 소수들 전부 구하기
- 구한 소수들로 나누어지지 않은 수가 있을 때까지 계산하기

## 복잡도, 자료구조
- 복잡도: O(n) = nlogn

## 다른사람 풀이
```
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def solve(n):
    while True:
        if is_prime(n):
            return n
        n += 1

t = int(input())
for _ in range(t):
    n = int(input())
    print(solve(n))
```
- 굳이 에르토스테네츠의 체를 사용해서 미리 수를 구할 필요없이
- 그냥 주어진 수를 **2부터 제곱근까지 계산해서 소수인지 계산하는걸로** 작성해도
- 시간 복잡도가 터지지 않는다. ㅠㅠ