### SQL 문장 종류
|명령어 종류|명령어|설명
|-|-|-|
|DML|SELECT, INSERT, UPDATE, DELETE|조회, 검색, 데이터 변경, 삭제, 추가|
|DDL|CREATE, ALTER, DROP, RENAME|데이터구조 생성, 변경, 삭제|
|DCL|GRANT, REVOKE|권한을 주고 회수하는 명령어|
|TCL|COMMIT, ROLLBACK|논리적인 작업의 단위를 묶어서 제어|

### SQL문에서 발생가능한 오류 원인
1. "Where" 절에는 집계 함수 사용 불가

### NULL 조건절 사용하기 위해서는
1. IS NULL, IS NOT NULL 키워드 사용

### Oracle과 SQL Server의 차이
1. (공통) 컬럼의 모든 데이터는 도메인 내에 있는 값이어야지 오류가 발생하지 않는다.
2. (Varchar(10), VARACHAR2(100), DATE)일 때 ("999", "", "2015-11-11")로 입력하면 Orcle은 ""부분을 NULL로 입력하고 조회할 때도 IS NULL로 해야한다. 반면 SQL Server은 "" 그대로 입력되고 회할 때 = ""로 조회해야한다.
3. Orcle에서는 OUTER JOIN 구문을 (+) 기호 사용

### SQL 함수
1. LOWER: 소문자로 변경
2. UPPER: 대문자로 변경
3. ASCII: 아스키 번호로 변경
4. LTRIM: 첫 번째 인자의 문자열의 왼쪽 첫 문자부터 확인해서 두 번째 인자값이 지정문자가 나타나면 해당 문자를 제거, 다른 문자 사이 또는 오른쪽에 있는 지정문자는 제거되지 않는다.
5. LENGTH: 문자열의 길이 반환
6. CHR: 주어진 ASCII 코드에 대한 문자를 반환
7. REPLACE: 문자열을 취환하는 함수
8. SUBSTR/SUBSTRING(문자열, m, n): 문자열 중 m 위치에서 n개의 문자 길이에 해당하는 문자를 돌려줌(n이 생략되면 마지막 문자까지)
9. LTRIM(문자열, 지정문자): 문자열의 첫 문자부터 확인해서 지정문자가 나타나면 해당 문자 제거
> SQL Server에서는 지정문자 사용 불가
10. RTRIM(문자열, 지정문자): 마지막 문장부터 확인해서 지정문자가 나타나는 동안 해당 문자를 제거
11. TRIM([leading|trailing|both] 지정문자 from 문자열): 문자열에서 머리말, 꼬리말 또는 양쪽에 있는 지정 문자를 제거

#### 확인
TO_CHAR, TO_DATE 구별할 것   
IN구문으로 구분한 것과 ON 절에 있는 것은 다름(이건 JOIN할 때 비교되는 컬럼 명시)

### Group by 절과 HAVING 절
1. 집계 함수의 통계 정보는 NULL 값을 가진 행을 제외하고 수행
2. GROUP BY 절에서는 SELECT절과 달리 ALIAS 명 사용 불가
3. WHERE절에는 집계함수 사용 불가
4. HAVING 절은 일반적으로 GROUP BY 절 뒤에 위치
5. GROUP BY 절에는 NULL 값도 포함해서 출력
6. SELECT절 이후에 ORDER BY가 수행되기 때문에 SELECT 절에 기술되지 않는 칼럼으로 정렬하는 것은 불가(but, 오라클은 가능)
7. GROUP BY를 사용할 경우 GROUP BY 표현식이 아닌 값은 기술 불가

### 오라클에서의 날짜 연산(숫자연산과 동일)
1. 1/24/60: 1분을 의미(24시간 -> 시간을 다시 60분 -> 1분)
2. 1/24/(60/10): 10분을 의미(24시간 -> 시간을 다시 60분 -> * 10분 -> 10분)
3. 1/12/(60/30): 1/24/60이 기본 1분인데 거기에 (*2), (*30) 되어 있으므로 1시간

### 동일한 표현
CASE WHEn LOC = "NEW YORK" THEN "EAST" ELSE "ETC"
CASE WHEN LOC IS "NEW YORK" THEN "EAST" ELSE "ETC"
DECODE (LOC, "NEW YORK", "EAST", "ETC")

### NULL 함수
1. NVL(표현식1, 표현식2)/ISNULL(표현식1, 표현식2)
 - 표현식1의 결과값이 NULL이면 표현식 2의 값을 출력
2. NULLIF(표현식1, 표현식2)
 - 표현식1이 표현식2와 같으면 NULL 같지 않으면 표현식1 리턴
3. COALESCE(표현식1, 표현식2...)
 - NULL이 아닌 최초의 표현식을 나타냄, 모든 표현식이 NULL이라면 NULL 리턴
4. 칼럼끼리 연산할 때 NULL을 포함하면 결과는 NULL이지만 레코드끼리 연산할 때 NULL을 포함하면 NULL을 연산에서 제외하기 때문에 결과가 NULL이 아니다.

### Order by 절에 컬럼은 select에 언급된 컬럼 순서로 명칭가능

### 집계 함수 종류
|집계함수|목적|
|-|-|
|COUNT(*)|NULL 값을 포함한 행의 수|
|COUNT(표현식)|표현식의 값이 NULL인 값을 제외하고 행의 수 출력|
|SUM(DISTINCT|ALL 표현식)|표현식의 NULL 값을 제외한 합계|
|AVG(DISTINCT|ALL 표현식)|표현식의 NULL 값을 제외한 평균|
|MAX, MIN, STDDEV, VARIAN|최댓값, 최솟값, 표준편차, 분산 출력|

### JOIN에 대한 설명
1. 일반적으로 조인은 PK와 FK 값의 연관성에 의해 성립
2. EQUI JOIN은 조인에 관여하는 테이블 간의 칼럼 값들이 정확하게 일치하는 경우 사용
3. EQUI JOIN은 "=" 연산자에 의해서만 수행되며, 그 이외의 비교연산자를 사용하는 경우에는 모두 NON EQUI JOIN이다.
4. 대부분 NON EQUI JOIN을 수행할 수 있지만, 때로는 설계상의 이유로 수행이 불가능한 경우도 있다.
5. DBMS 옵티마이저는 FROM 절에 테이블 중 최대 2개의 테이블씩 짝을 지어 JOIN 수행
6. 적절한 JOIN 조건이 없는 경우 카티시안 곱 발생
7. Between JOIN 구문 없음
8. USING 조건절을 이용한 EQUI JOIN에서도 NATURAL JOIN과 마찬가지로 ALIAS나 테이블 이름과 같은 접두사를 붙일 수 없다.
9. 조건절이 없는 경우 CROSS JOIN으로 PRODUCT가 발생
10. FULL OUTER JOIN: 좌측, 우측 테이블의 모든 데이터를 읽어 JOIN 하여 결과를 생성, RIGHT/LEFT OUTER JOIN의 결과를 합집합으로 처리한 결과와 동일


### 순수관계연산자
1. SELECT, PROJECT, JOIN, DIVIDE
