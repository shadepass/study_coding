import sys
from itertools import combinations

input = sys.stdin.readline
answer = set()

# 입출력
number = int(input())
weight_list = list(map(int, input().split()))
sum_weight = sum(weight_list)
weight_set = set(weight_list)

#print()

# 반복문1 : 합칠 개수
for i in range(1, number):
    # 해당 개수로 나올 수 있는 모든 조합 Set 원소로 리스트화
    combinations_list = list(combinations(weight_list, i))
    for temp_combination in combinations_list: # 나오는 조합을 input으로 받자
        # weight_set - 조합 set = 남은 list 추출
        less_list = list(weight_set - set(temp_combination))
        first_set = set()
        second_set = set()
        
        if len(temp_combination) >= len(less_list):
            for j in range(1, len(temp_combination) + 1):
                first_combinations_list = list(combinations(temp_combination, j))
                for temp in first_combinations_list:
                    temp_value = sum(temp)
                    first_set.add(temp_value)
                    answer.add(temp_value)
                if j <= len(less_list):
                    second_combinations_list = list(combinations(less_list, j))
                    for temp in second_combinations_list:
                        temp_value = sum(temp)
                        second_set.add(temp_value)
                        answer.add(temp_value)                        
        else:
            for j in range(1, len(less_list) + 1):
                if j <= len(temp_combination):
                    first_combinations_list = list(combinations(temp_combination, j))
                    for temp in first_combinations_list:
                        temp_value = sum(temp)
                        first_set.add(temp_value)
                        answer.add(temp_value)
                second_combinations_list = list(combinations(less_list, j))
                for temp in second_combinations_list:
                    temp_value = sum(temp)
                    second_set.add(temp_value)
                    answer.add(temp_value)      
        first_list = list(first_set)
        second_list = list(second_set)
        # 조합 set 상수 구하기
        #temp_value = sum(temp_combination) 
        #answer.add(temp_value)
        for first_value in first_list:
            for second_value in second_list:
                temp_value = abs(first_value - second_value)
                if temp_value == 0:
                    pass
                else:
                    answer.add(temp_value)
        '''            
        for k in second_set:
            # 조합 상수 - 나머지 리스트 값들 -> 결과 set에 넣기
            temp_value = sum(k)
            if temp_value == 0:
                pass
            else:
                answer.add(temp_value)
        ''' 

answer.add(sum_weight)
#print(answer)
print(sum_weight - len(answer))

# 반복문2 : 합친 개수에 따라 합 구하기
## 합 <-> 합 구한 나머지 변수 구하기
### 합 한 것도 리스트에 넣어 놓기
# 반복문3 : 각각 서로 뺄샘해서 절댓값 취한 값을 리스트에 계속 넣기
## 이때, 리스트는 Set으로 구성해서 중복된 값은 삭제하도록
