## 서브쿼리 종류
1. 다중 칼럼 서브쿼리: 서브쿼리의 실행 결과로 여러 칼럼을 반환한다. 메인쿼리의 조건절에 여러 칼럼을 동시에 비교할 수 가 있다. 서브쿼리와 메인쿼리에서 비교하고자 하는 칼럼 개수와 칼럼의 위치가 동일해야한다.
2. Single Row 서브쿼리(단일 행 서브쿼리)  
항상 1건 이하인 서브쿼리를 의미, 단일 행 비교 연산자와 함께 사용(=, <, <>, > 등)
3. Multi Row 서브 쿼리(다중 행 서브쿼리)  
실행 결과가 여러 건인 서브쿼리로, 다중행 비교 연산자에는 IN, ALL, ANy, SOME, EXISTS가 있다.
4. Multi Column 서브쿼리(다중 칼럼 서브쿼리): 메인쿼리의 조건절에 여러 칼럼을 동시에 비교  
서브쿼리와 메인쿼리에서 비교하고자 하는 칼럼 개수와 칼럼의 위치가 동일해야한다.
5. SQL Server에서는 다중 칼럼 서브쿼리를 지원하지 않는다.
6. 연관 서브쿼리는 서브쿼리가 메인쿼리 칼럼을 포함하고 있는 형태의 서브쿼리
7. 단일 행 서브쿼리의 비교연산자는 다중 행 서브쿼리의 비교 연산자로 사용할 수 없지만 반대의 경우는 가능
8. 비 연관 서브쿼리가 주로 메인쿼리에 값을 제공하기 위한 목적으로 사용
9. 메인쿼리의 결과가 서브쿼리로 제공될수도, 서브쿼리가 메인쿼리로 제공될 수 있다.
10. 인라인뷰  
FROM 절에서 사용되는 서브쿼리를 의미함. 서브쿼리의 결과가 마치 실행 시에 동적으로 생성된 테이블인 것처럼 사용

## SQL 집계함수
1. ROLLUP: 소그룹간의 합계를 계산하는 함수  
GROUP BY로 묶은 각각의 소그룹 합계와 전체 합계를 모두 구한다.  
맨 처음 명시한 컬럼에 대해서만 소그룹 합계를 구해준다.
![image](https://github.com/user-attachments/assets/5fa448e3-d839-4884-b235-ad50a17a82d4)  
![image](https://github.com/user-attachments/assets/07c674e3-b5f7-423b-991e-fd288e5f43d4)  
2. CUBE: 항목들 간의 다차원적인 소계를 계산
GROUP BY절에 명시한 모든 컬럼에 대해 소그룹 합계를 계산
![image](https://github.com/user-attachments/assets/709b294d-e104-4fb7-aa3c-96e5571d9373)  
![image](https://github.com/user-attachments/assets/e7ef577c-b685-472e-9097-eb749f8c4341)  
3. GROUPING SETS: 특정 항목에 대한 소계를 계산하는 함수
![image](https://github.com/user-attachments/assets/5fdf065b-54e6-48cb-aa0b-1b8aed907816)  
![image](https://github.com/user-attachments/assets/f67edd1d-cfc0-40d1-9bb9-c35cf8e6f1d4)  
4. GROUPING: 집계함수들을 지원하는 함수  
집계가 계산된 결과에 대해서는 1의 값을 갖고 그렇지 않은 결과에 대해서는 0의 값을 가짐
5. 매개변수가 하나인 경우 ROLLUP과 CUBE는 동일한 결과
6. HAVING은 GROUP BY 없이 WHERE 절에서도 사용 가능
7. 각각의 소계 함수 내 폴더 주의할 것

## 집합 연산자
1. union: 여러개의 SQL문의 결과에 대해 합집합으로 결과에서 모든 중복된 행은 하나의 행으로
2. UNION ALL: UNION에서 중복된 행도 그대로 결과를 표시
3. INTERSECT: 여러 개의 SQL문 결과에 대한 교집합, 중복된 행은 하나의 행으로 만듬
4. EXECEPT: 앞 SQL 문의 결과에서 뒤의 SQL문의 결과에 대한 차집합, 중복된 행은 하나의 행으로
5. 집합연산자를 사용한 경우 ORDER BY 절은 최종 결과를 정렬하여 한 번만 사용 가능

## 동일한 SQL문 예시
1.
```
SELECT A.서비스ID, B.서비스명, B.서비스URL  
FROM (SELECT 서비스 ID  
      FROM 서비스  
        INTERSECT  
        SELECT 서비스ID  
        FROM 서비스 이용) A, 서비스 B  
WHERE A.서비스ID = B.서비스ID;    

SELECT A.서비스ID, B.서비스명, B.서비스URL  
FROM 서비스 X  
WHERE NOT EXIST(SELECT  
                FROM (SELECT 서비스 ID  
                      FROM 서비스  
                      MINUS  
                      SELECT 서비스ID  
                      FROM 서비스 이용) Y  
                WHERE X.서비스ID = Y.서비스ID);  
```
2. GROUP BY, HAVING 절
```
SELECT A.회원번호, A.회원명
FROM 회원 A, 동의항목 B
WHERE A.회원번호 = B.회원번호
GROUP BY A.회원번호, A.회원명
HAVING COUNT(CASE WHEN B.동의여부 = "N" THEN 0 ELSE NULL END) >= 1
ORDER BY A.회원번호;
--> 단 하나라도 "N" 인 회원을 출력하는 SQL

SELECT A.회원번호, A.회원명
FROm 회원 A
WHERE EXISTS (SELECT 1
              FROM 동의항목 BY
              WHERE A.회원번호 = B.회원번호
              AND B.동의여부 = "N")
ORDER BY A.회원번호;

SELECT A.회원번호, A.회원명
FROM 회원 ALL
WHERE A.회원번호 IN (SELECT B.회원번호
                    FROM 동의항목 B
                    WHERE B.동의여부 = "N")
ORDER BY A.회원번호;

SELECT A.회원번호, A.회원번명
FROM 회원 A, 동의항목 B
WHERE A.회원번호 = B.회원번호 AND B.동의여부 ="N"
GROUP BY A.회원번호, A.회원명
ORDER BY A.회원번호;
```

## 계층형 SQL
1. PRIOR
CONNECT BY절에 사용되며, 현재 읽은 칼럼을 지정  
PRIOR 자식 = 부모 형태인경우 부모 데이터에서 자식 데이터 방향으로 전개하는 순방향 전개  
PRIOR 부모 = 자식  형태인 경우 반대로 자식 데이터에서 부모 데이터 방향으로 전개하는 역방향 전개
2. START WITH 절은 계층 구조의 시작점을 지정하는 구문
3. ORDER SIBLINGS BY 절은 형제 노드 사이에서 정렬을 지정하는 구문
4. 루트 노드의 LEVEL 값은 1
5. CONNECT BY 절 조건문은 WHERE과 다르게 START WITH 절에서 필터링된 시작 데이터는 결과목록에 포함되며, 이후 CONNECT BY 절에 의해 추가 필터링됨
6. 오라클 계층형 질의문에서 PRIOR 키워드는 SELECT, WHERE, CONNECT By 절 모두 사용 가능
7. SQL Server에서는 CTE를 재귀 호출함으로써 게층 구조 전개

## 뷰에 대한 설명
1. 뷰는 단지 정의만을 가지고 있으며, 실행 시점에 질의를 재작성하여 수행
2. 뷰는 보안을 강화하기 위한 목적으로 활용 가능
3. 실제 데이터를 저장하고 있는 뷰를 생성하는 기능을 지원하는 DBMS도 있다.
4. 뷰의 장점 중 하나는 독립성으로 테이블 구조가 변경되어도 뷰를 사용하는 응용 프로그램은 변경하지 않아도 된다.
5. 장점
> 독립성: 테이블 구조가 변경되어도 뷰를 사용하는 응용프로그램은 변경 필요 없음  
> 편리성: 복잡한 질의를 뷰로 생성하여 관련 질의를 단순하게 작성  
> 보안성: 뷰를 생성할 때 컬럼을 빼고 생성하여 사용자에게 정보를 감출 수 있다.

## 다음 SQL 결과는
![image](https://github.com/user-attachments/assets/94a9846f-313f-4f21-b679-5259ae7a82d6)
- COL1는 부서ID별로 연봉의 내림차순으로 유일한 순위 부여
- COL2는 첫 행부터 지금까지 SUM 값 구함
- COL3는 전체 데이터에서 현재 행부터 현재 행까지 최대값 구함
* ROWS CURRENT ROW에서 BETWEEN이 없다면 뒤에 AND CURRENT ROW가 생략된 것
따라서,
1. COL1이 2인 값은 001, 004, 007
2. 각각 ROW를 1부터(사원 ID 순으로 오름차순) 자기자신까지 더하면, 2500, 7500, 7500
3. 자기자신 값 2500, 3000, 3000이므로 답은 2번 

## WINDOW 함수
1. PARTITION BYU 절과 GROUP BY 절은 의미적으로 유사하다.
2. PARTITION BY 절이 없으면 전체 집합을 하나의 Partition으로 정의한 것과 동일하다.
3. 윈도우 함수 처리로 결과 건수는 그대로이다.(각 Row 별로 출력값有)
4. 윈도우 함수 적용 범위는 Partition을 넘을 수 없다.
5. GROUP BY 절과 함께 WINDOW FUNCTION을 같이 사용한다고 하더라도 오류가 발생하지 않는다.
6. GROUPIGNG 된 그룹에 WINDOW Function을 적용한다.
7. LAG 함수를 이용하여 파티션별 윈도우에서 이전 몇 번째의 행의 값을 가져올 수있다.
9. LEAD을 이용하여 이후 몇 번째의 행의 값을 가져올 수 있으며 이는 SQL Server에서는 지원하지 않는다.