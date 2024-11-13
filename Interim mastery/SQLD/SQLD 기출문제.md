### 반정규화에 대한 설명
- 데이터를 조회할 때 디스크 I/O 량이 많아서 성능이 저하되거나 경로가 너무 멀어 조인으로 인한 성능저하가 예상될 때 수행
- 컬럼을 계산할 때 성능이 저하될 것이 예상되는 경우 수행
- 반정규화를 적용할 때는 기본적으로 데이터 무결성이 깨질 가능성이 많이 있으므로 반드시 데이터 무결성을 보장할 수 있는 방법을 고려해야한다.
- 통계, 중복, 이력 테이블 추가는 반정규화기법임

### 반졍규화 대상
- 자주 사용되는 테이블에 접근하는 프로세스의 수가 많고 항상 일정한 범위만을 조회하는 경우
- 테이블의 대량의 데이터가 있고 대량의 데이터 범위를 자주 처리하는 경우 처리범위를 일정하게 줄이지 않으면 성능을 보장할 수 없을 경우
- 통계성 프로세스에 의해 통계 정보를 필요로 할 때 별도의 통계 테이블을 생성해야하는 경우
- 테이블에 지나치게 많은 조인과 Sorting, ORder by 프로세스가 많은 경우는 해당사항 없다.

### 엔터티 분류
- 매출, 계약, 주문 : 중심 엔터티
- 사원: 기본 엔터티

### 아래 ERD에 대한 설명
![image](https://github.com/user-attachments/assets/02ae786c-af08-4b08-ae15-a93d9d2b2bcc)
- SQL 작성 시 B를 제외할 경우 A와 C는 카테시안 조인이 된다.
- N개 테이블을 모두 조인할 경우 최소 조건은 N-1개이다.
- B, C에서 C의 데이터는 모두 B에 존재하므로 Outer Join을 안해도 된다.
- B는 A의 모든 데이터를 포함하고 있지 않다.

### Row migration과 Row Chaining
1. Row Migration(행 이전)
- Update로 인해 행 길이가 증가했을 때, 저장 공간이 부족한 경우 발생
- 원래 정보를 기존블록에 남겨두고 실제 데이터는 다른 블록에 저장하므로 성능 감소
- 해결책: PCTFREE 영역을 충분히 할당(너무 크게 하면 데이터 저장 공간 부족으로 공간 효율성 감소)
2. ROw Chaining
- 데이터가 커서 여러 블록에 나누어 저장하는 현상, 2개의 데이터 블록을 검색해야하므로 성능 감소
- 해결책: DB_BLOCK_SIZE를 크게 하여 최소화 가능


### 가변 문자열에는 비교연산 사용불가(VARCHAR)

## Column이 2개 이상 같이 보는경우 둘다 만족해야함
![image](https://github.com/user-attachments/assets/310b6ffc-eee2-448b-bd5d-dc296a2e762b)

## 문제 풀이
![image](https://github.com/user-attachments/assets/d7bbd2a2-ad44-4631-b7b4-c5a01a658f7e)
- (계층구조) 선행 테이블 → 인덱스 → 조인

### 트리거에 대한 설명
- DELETE ON TRIGGER의 경우 :OLD는 삭제 전 데이터를, :NEW는 삭제 후 데이터를 나타낸다
- 특정 테이블에 DML 문이 수행되었을 때 자동으로 동작하도록 작성된 프로그램이다.
- 트리거는 DB 자체에 저장, 테이블, 뷰에 사용가능
![image](https://github.com/user-attachments/assets/22defccf-feee-47a8-85be-4c3e6ec3341c)


### Order by는 마지막에 처리되기 때문에 인라인뷰로 처리할 것
![image](https://github.com/user-attachments/assets/82a654d3-2c0b-49f1-808e-96178516fb4b)

### SQL Set Operation 에서 중복 제거를 위해 정렬 작업을 하지 않는 집합 연산자
- Union All

### 왜래키를 사용하는 테이블에서 값을 추가할 때, 무결성 제약조건에 의해 외래키를 받는 테이블에도 해당 값이 있어야한다.

### Cross Join과 Natural Join의 차이점
- Cross join은 Where 절에 조건 사용 가능(Natural 불가)
- Natural Join에서는 특정 Join 컬럼을 명시적으로 적을 수 없음
- Cross Join은 join에 참여하는 테이블의 Join Key가 없을 경우 발생
- Natural Join에서 Join Key는 컬럼명으로 결정

### 적합한 파티셔닝 기법
- LIST: 대량의 데이터를 특정컬럼(생성일자)없을 때 사용

### SQL Merge 구문
- 변경할 테이블에 대해 데이터 존재하는가의 여부 체크 후, INSERT, UPDATE, DELETE를 한 번에 처리