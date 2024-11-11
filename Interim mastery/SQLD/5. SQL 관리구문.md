## ALTER TABLE 관련
- PK 제약 조건 예시
```
CREATE TABLE PRODUCT
( PROD_ID VARCHAR2(10) NOT NULL
 ,PROD_NM VARCHAR2(100) NOT NULL
 ,REG_DT DATE NOT NULL
 ,REG_NO NUMBER(10) NULL );
 ALTER TABLE PRODUCT ADD CONSTRAINT PRODCUT_PK PRIMARY KEY (PROD_ID);
```

## 테이블 칼럼 정의 관련
- SQL server에서 여러 개의 칼럼을 ALTER COLUMN으로 동시에 수행하는 구문은 지원하지 않음
* 괄호 또한 사용하지 않음
- [Oracle] ALTER TABLE 테이블명 MODIFY 칼러명1 데이터 유형 ~
- [SLQ SERVER] ALTER TABLE 테이블명 ALTER COLUMN ~
- SQL Server는 자동으로 Commit 수행하지 않음
 - [ORacle] SAVEPOINT SVPT1; ... ROLLBACK TO SVPT1;
 -[SQL Server] SAVE TRANSACTION SVTR1; ... ROLLBACK TRANSACTIOn SVTR1;

## SQL에서 중복된 데이터를 출력하지 않으려면 DISTINCT 사용
- DISTINCT 키워드 뒤에 여러 개의 칼럼이 올 경우, 주어진 칼럼 값이 모두 동일한 행들만 중복 건으로 처리된다.

## 테이블 생성의 주의사항
- 테이블명은 객체를 의미할 수 있는 적절한 이름을 사용, 가능한 단수형 권고
- 테이블 명은 다른 테이블명과 중복이면 안됨
- 한 테이블 내에서는 칼럼명 중복 지정 불가
- 테이블 이름 지정 후 각 컬럼명은 괄호 묶어 지정
- 각 컬럼들은 콤마로 구분되고, 끝은 항상 세미콜론으로 끝난다.
- 칼럼 뒤에 데이터 유형은 꼭 지정되어야 한다.
- 벤더에서 사전에 정의한 예약어는 사용 불가
- VARCHAR 형태에 1, "100" 등 둘다 입력 가능
- DATE 칼럼에는 숫자값을 입력 받지 못함

## 외래키 관련 설명
- 테이블 생성 시 설정 가능
- 외래키 값은 null을 가질 수 있음
- 한 테이블에 하나 잇아 생성 가능
- 외래키 값은 참조 무결성 제약을 받을 수 있다.

## 테이블 칼럼 삭제 시 활용 문장
- ALTER TABLE 테이블명 DROP COLUMN 칼럼명;

## SQL 표준 데이터 타입
- CHAR, VARCHAR2
- NUMBER
- DATE

# FK 생성 관련 참조동작 
1. Delete(/Modify) Action
- Cascade: Master 삭제 시 Child 같이 삭제
- Set NUll: Master 삭제 시 CHild 해당 필드 NULL
- Set Default: Master 삭제 시 Child 해당 필드 Defatuli 값으로 설정
- Restrict: child 테이블에 PK 값이 없는 경우만 MASTER 삭제 허용
- No Action: 참조무결성을 위반하는 삭제.수정 액션을 취하지 않음
2. Insert Ation
- Automatic: Master 테이블에 PK가 없는 경우 Master PK를 생성 후 Child 입력
- Set Null: Master 테이블에 PK가 없는 경우 Child 외부키를 NULL 값으로 처리
- Set Default: Master 테이블에 PK가 없는 경우 Child 외부키를 지정된 기본값으로 입력
- Dependent: Master 테이블에 PK가 존재할 때만 Child 입력 허용
- No Action: 참조무결성을 위반하는 입력 액션을 취하지 않음

## DROP, TRUNCATE, DELETE
|DROP|TRUNCATE|DELETE|
|-|-|-|
|DDL|DDL(일부 DML 성격)|DML|
|Rollback 불가능|Rollback 불가능|Commit 이전 Rollback 가능|
|Auto Commit|Auto Commit|사용자 Commit 필요|
|테이블이 사용했던 Storage를 모두 release|테이블이 사용했떤 Storate 중 최초 테이블 생성 시 할당된 Storage 만 남기고 Release|데이터를 모두 Delete해도 사용했던 Storage는 Release되지 않음|
|테이블의 정의 자체를 완전히 삭제|테이블을 최초 생성된 초기상태로 만듦|데이터만 삭제|
- TRUNCATE 명령어는 UNDO를 위한 데이터를 생성하지 않기 떄문에 동일 데이터량 삭제 시 DELETE보다 빠르다.


## 데이터베이스 트랜잭션에 대한 설명
1. 원자성: 트랜잭션에서 정의된 연산들은 모두 성공적으로 실행되든지 아니면 전혀 실행되지 않은 상태로 남아 있어 한다.
2. 일관성: 트랜잭션이 실행 되기 전의 데이터베이스 내용이 잘못되어 있지 않다면 트랜잭션이 실행된 이휘에도 데이터베이스의 내용에 잘못이 있으면 안된다.
3. 고립성: 트잭션이 실행되는 도중에 다른 트랜잭션의 영향을 받아 잘못된 결과를 만들어서는 안된다.
4. 지속성: 트랜잭션이 성공적으로 수행되면 그 트랜잭션이 갱신한 데이터베이스의 내용은 영구적으로 저장된다.

## TOP 함수
- TOP(2): 2명까지 출력
- WITH TIES를 이용해서TOP N 질의문에서 N에 해당하는 값이 동일한 경우 동일한 경우 함께 출력하도록 정의