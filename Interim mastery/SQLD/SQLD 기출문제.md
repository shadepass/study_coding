## 반정규화에 대한 설명
### 기본적인 반정규화에 대한 설명
- 데이터를 조회할 때 디스크 I/O 량이 많아서 성능이 저하되거나 경로가 너무 멀어 조인으로 인한 성능저하가 예상될 때 수행
- 컬럼을 계산할 때 성능이 저하될 것이 예상되는 경우 수행
- 반정규화를 적용할 때는 기본적으로 데이터 무결성이 깨질 가능성이 많이 있으므로 반드시 데이터 무결성을 보장할 수 있는 방법을 고려해야한다.
- 통계, 중복, 이력 테이블 추가는 반정규화기법임
- 데이터를 조회할 때 디스크 입출력량이 많아서 성능이 저하될 때 반정규화 수행
- 경로가 너무 멀어 조인으로 인한 성능저하가 예상될 떄 반정규화 수행
- 칼럼을 계산하여 읽을때 성능이 저하 될 것이 예상되는 경우 반정규화 수행
### 반졍규화 대상
- 자주 사용되는 테이블에 접근하는 프로세스의 수가 많고 항상 일정한 범위만을 조회하는 경우
- 테이블의 대량의 데이터가 있고 대량의 데이터 범위를 자주 처리하는 경우 처리범위를 일정하게 줄이지 않으면 성능을 보장할 수 없을 경우
- 통계성 프로세스에 의해 통계 정보를 필요로 할 때 별도의 통계 테이블을 생성해야하는 경우
- 테이블에 지나치게 많은 조인과 Sorting, Order by 프로세스가 많은 경우는 해당사항 없다.
### 반정규화 기법
- 중복칼럼을 추가: 조인 감소를 위해 여러 테이블에 동일한 칼럼을 갖도록 한다
- 파생칼럼을 추가: 조회 성능을 우수하게 하기 위해 미리 계산된 칼럼을 갖도록 한다.
- 이력테이블에 기능 칼럼을 추가: 최신값을 처리하는 이력의 특성을 고려하여 기능성 컬럼을 추가한다.
- 배송 테이블에서 고객의 정보를 찾는 빈도가 높을 경우 고객과 배송 테이블의 관계를 추가하는 관계의 반정규화를 한다.
- 주문 목록 테이블에서 고객이 정보를 찾는 빈도가 높을 경우 고객과 주문 테이블의 비식별자 관계를 식별자 관계로 한다.
- 주문 테이블에서 항상 고객명을 같이 조회하는 경우 고객 테이블의 고객명을 주문 테이블에  넣어 컬럼 반정규화를 한다.
### 반정규화를 수행하는 이유
- 데이터를 조회할 떄 조인으로 인한 성능저하가 예상될 때
### 반정규화 절차
1. 반정규화 대상 조사
 - 범위처리빈도수 조사
 - 대량의 범위 처리 조사
 - 통계성 프로세스 조사 및 테입르 조인 개수 조사
2. 다른 방법 유도
 - 뷰(View) 테이블
 - 클러스터링 적용
 - 인덱스의 조정
 - 응용 애플리케이션
3. 반정규화 적용
 - 테이블 반정규화
 - 속성의 반정규화
 - 관계의 반정규화
### 테이블 반정규화
- 테이블 병합, 테이블 분할(수직/수평), 테이블 추가(중복/통계/이력/부분 테이블)
### 속성 반정규화
- 중복 칼럼 추가
- 파생 칼럼 추가
- 이력 테이블 칼럼 추가
- PK에 의한 칼럼 추가: 여러 칼럼으로 이루어진 PK를 가진 테이블을 조인할 경우 단순성을 위해서 인공키를 PK로 지정
- 응용시스템 오작동을 위한 칼럼 추가: 이전 데이터를 임시적으로 중복하여 보관
### 관계 반정규화
- 중복관계추가: 여러 경로를 거친 조인이 아닌 추가적인 관계를 맺음 
![image](https://github.com/user-attachments/assets/8dde24ca-f7ed-42bf-9b4b-bc1f6faababb)
![image](https://github.com/user-attachments/assets/ecdf5b99-8568-4995-8d77-e9e1d13b2841)

## 엔터티 분류
- 매출, 계약, 주문 : 중심 엔터티
- 사원: 기본 엔터티

## 아래 ERD에 대한 설명
![image](https://github.com/user-attachments/assets/02ae786c-af08-4b08-ae15-a93d9d2b2bcc)
- SQL 작성 시 B를 제외할 경우 A와 C는 카테시안 조인이 된다.
- N개 테이블을 모두 조인할 경우 최소 조건은 N-1개이다.
- B, C에서 C의 데이터는 모두 B에 존재하므로 Outer Join을 안해도 된다.
- B는 A의 모든 데이터를 포함하고 있지 않다.

## Row migration과 Row Chaining
1. Row Migration(행 이전)
- Update로 인해 행 길이가 증가했을 때, 저장 공간이 부족한 경우 발생
- 원래 정보를 기존블록에 남겨두고 실제 데이터는 다른 블록에 저장하므로 성능 감소
- 해결책: PCTFREE 영역을 충분히 할당(너무 크게 하면 데이터 저장 공간 부족으로 공간 효율성 감소)
2. ROw Chaining
- 데이터가 커서 여러 블록에 나누어 저장하는 현상, 2개의 데이터 블록을 검색해야하므로 성능 감소
- 해결책: DB_BLOCK_SIZE를 크게 하여 최소화 가능

## 가변 문자열에는 비교연산 사용불가(VARCHAR)

## Column이 2개 이상 같이 보는경우 둘다 만족해야함
![image](https://github.com/user-attachments/assets/310b6ffc-eee2-448b-bd5d-dc296a2e762b)

## 문제 풀이
![image](https://github.com/user-attachments/assets/d7bbd2a2-ad44-4631-b7b4-c5a01a658f7e)
- (계층구조) 선행 테이블 → 인덱스 → 조인

## 트리거에 대한 설명
- DELETE ON TRIGGER의 경우 :OLD는 삭제 전 데이터를, :NEW는 삭제 후 데이터를 나타낸다
- 특정 테이블에 DML 문이 수행되었을 때 자동으로 동작하도록 작성된 프로그램이다.
- 트리거는 DB 자체에 저장, 테이블, 뷰에 사용가능
![image](https://github.com/user-attachments/assets/22defccf-feee-47a8-85be-4c3e6ec3341c)


## Order by는 마지막에 처리되기 때문에 인라인뷰로 처리할 것
![image](https://github.com/user-attachments/assets/82a654d3-2c0b-49f1-808e-96178516fb4b)

## SQL Set Operation 에서 중복 제거를 위해 정렬 작업을 하지 않는 집합 연산자
- Union All

## 외래키를 사용하는 테이블에서 값을 추가할 때, 무결성 제약조건에 의해 외래키를 받는 테이블에도 해당 값이 있어야한다.

## Cross Join과 Natural Join의 차이점
- Cross join은 Where 절에 조건 사용 가능(Natural 불가)
- Natural Join에서는 특정 Join 컬럼을 명시적으로 적을 수 없음
- Cross Join은 join에 참여하는 테이블의 Join Key가 없을 경우 발생
- Natural Join에서 Join Key는 컬럼명으로 결정

## 적합한 파티셔닝 기법
- LIST: 대량의 데이터를 특정컬럼(생성일자)없을 때 사용

## SQL Merge 구문
- 변경할 테이블에 대해 데이터 존재하는가의 여부 체크 후, INSERT, UPDATE, DELETE를 한 번에 처리

## 식별자 관련 용어
1. 주식별자/보조식별자: 대표성 유무
2. 내부식별자(스스로 생성)/외부 식별자(받아옴)
3. 단일 식별자(속성 1개)/복합식별자(속성 N개)
4. 본질식별자(업무에 의해 생성)/인조식별자(인위적으로 생성)

## ERD 그림
![image](https://github.com/user-attachments/assets/6b82f7d6-f6ea-47ed-8f59-55518d6af463)

## Join 기법
![image](https://github.com/user-attachments/assets/c68ad07d-9c01-47fb-accf-32a1c2411ecc)
- SQL의 실행 순서는 2, 3, 1, 0이다.
- DEPARTMENTS 테이블이 EMPLOYEES 보다 소량으로 선행으로 하는 것이 좋다.
조인 조건이 Non-Equal 일 경우 Hash Join으로 수행되지 못하고 Merge Join으로 수행된다.
![image](https://github.com/user-attachments/assets/425ac512-6ae0-4ea7-84f2-57d421bc90b9)
- Hash Join은 정렬 작업이 없어 정렬이 부담되는 대량배치작업에 유리하다.
- Natural Join에서 "EMP.DEPTNO" 처럼 OWNER 조건 사용하면 에러 발생

## SQL 문제
![image](https://github.com/user-attachments/assets/d000249d-84b4-4683-b50f-043956bbff91)
![image](https://github.com/user-attachments/assets/d0d237ca-b5f4-4ac5-a1bc-e895286b05d8)
![image](https://github.com/user-attachments/assets/b4423af6-9327-442d-b7f8-dd9c51095e6d)
![image](https://github.com/user-attachments/assets/861d48f7-470a-40c9-9a71-99bdaafb839a)
- 2번만 5을 반환 나머지는 "05" 반환
- SUBSTR: 문자열 슬라이싱, 5번째 에서 2번째까지
- EXTRACT (YEAR/MONTH/DAY FROM SYSDATE) 년, 월, 일을 뽑아 출력(숫자)
- CONCAT: 문자열 결합
- TRIM: 공백제거
![image](https://github.com/user-attachments/assets/89fcd106-5363-47bd-8ad9-643e9e9e6385)
- 1번 Groupby 절로 인해서 여러 행이 반환되면서 단일행 연산자에서 오류 발생

## 컬럼을 명시하지 않으면 전체 컬럼과 입력하는 개수가 동일해야한다.
![image](https://github.com/user-attachments/assets/47468f3c-639f-4167-9a9f-e8f97af2be3f)

## 스키마 내용
1. 외부 스키마: 사용자 관점
2. 개념 스키마: 통합 관점
3. 내부 스키마: 물리적 관점

## 관계 설명
1. 관계명
- 엔터티간 관계에 맺어진 형태 
- 관계시작점 - 관계끝점
- 능동적/수동적
2. 관게차수(Dergree/Cardinality)
![image](https://github.com/user-attachments/assets/571fbd14-7154-47f4-be63-845aeb39de82)
3. 관계선택사양
- 필수참여관계, 선택참여 관계
- 선택참여하는 엔터티 쪽에 원 표시 필요

## 분산데이터베이스
![image](https://github.com/user-attachments/assets/6737d2a7-3233-4dbd-9e3f-d47c7c420706)

## 테이블 설계 시 인덱스와 관련된 설명
- 주로 B-Tree 인덱스로 되어 있다.
- 외래키가 설계되어 있는데 인덱스가 없는 상태에서는 입력/수정/수정의 부하가 덜하다
- 테이블에 만들 수 있는 인덱스의 수는 제한이 없으나, 너무 많이 만들면 오히려 성능 부하가 발생한다.
- 조회는 일반적으로 인덱스가 있는 것이 유리하다.

## SQL ESCAPE 문 
- 와일드카드 문자를 포함하는 패턴 검색 시 사용
 
## 윈도우 함수 관련
![image](https://github.com/user-attachments/assets/9a491a5f-b756-4ad0-a681-74724fc998ee)

## PL/SQL 문 
1. 변수와 상수 등을 사용하여 일반 SQL 문장을 실행할 떄 WHERE 절의 조건 등으로 대입할 수 있다.
2. Procedure, User Defined Function, Trigger 객체를 Pl/SQL로 작성할 수 있다. 
3. Procedure 내부에 작성된 절차적 코드는 PL/SQL 엔진이 처리하고 일반적인 SQL 문장은 SQL 실행기가 처리한다.
4. PL/SQL 문의 기본 구조로 DECLARE, BEGIN~END 이며, EXCEPTION은 필수가 아니다.

## 무결성을 보장하기 위한 방법
1. 애플리케이션
2. Trigger
3. 제약조건
4. Lock/Unlock은 병행성 제어(동시성) 기법이다.

## 제약조건에 대한 설명
- Check 제약조건은 데이터베이스에서 데이터의 무결성을 유지하기 위하여 테이블의 특정 칼럼에 설정하는 제약이다.
- 기본키(Primary Key)는 반드시 테이블 당 하나의 제약만을 정의할 수 있다.
- 고유키(Unique Key)로 지정된 모든 칼럼들은 중복된 값을 가져서는 안되며 Null 값을 가질 수있다.
- 외래키는 테이블간의 관계를 정의하기 위해 기본키를 다른 테이블의 외래키가 참조하도록 생성한다.