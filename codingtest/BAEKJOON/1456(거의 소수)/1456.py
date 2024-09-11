import sys
import math
#import numpy as np
input = sys.stdin.readline

#print(math.log(100, 17))

A, B = map(int, input().split())
dec_list = []
check_list = []
#if A == 1:
#    A = 2

#for i in range(A, B+1):
#    check_list.append(i)

#check_list = list(np.arange(A, B + 1))
max_value = int(math.pow(10, 7))

check_list = [1 for _ in range(max_value + 1)]

for i in range(2, max_value + 1):
    if check_list[i] == 1:
        for j in range(i * i, max_value + 1, i):
            check_list[j] = 0


#print("완료")
answer = 0

for i in range(2, max_value + 1):
    if check_list[i] == 1:
        temp = i
        while(temp <= B / i):
            if (A <= temp * i):
                answer += 1
            temp *= i

print(answer)

'''
for i in range(2, int(math.sqrt(B)+1)):
    for temp in check_list:
        if temp / i == 1:
            pass
        elif temp % i == 0:
            check_list.remove(temp)
        else:
            pass
    #print()

answer = 0
for temp in check_list:
    answer += int(math.log(B, temp)) - 1 

print(answer)

if A == 1 or A == 2:
    
    print()


#else:
'''