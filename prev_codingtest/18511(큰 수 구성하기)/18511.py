import sys

input = sys.stdin.readline

N, K = map(int, input().split())

K_list = list(map(int, input().split()))
K_list.sort(reverse = True)

str_N = str(N)
N_legnth = len(str_N)

answer = []
lower_case = False

for i in range(N_legnth):
    out_flag = False
    keep_flag = False
    for K in K_list:
        if K > int(str_N[i]):
            pass
        elif K == int(str_N[i]):
            keep_flag = True
            answer.append(str(K))
            break
        else:
            out_flag = True
            answer.append(str(K))
            break

    if keep_flag == False and out_flag == False:
        lower_case = True
        break
    if out_flag == True:
        break

if lower_case == True:
    answer = []
    for K in K_list:
        if K < int(str_N[0]):
            out_flag = True
            break
    
    if out_flag == True:
        answer.append(str(K))
        for j in range(1, N_legnth):
            answer.append(str(K_list[0])) 
    
    else:
        for j in range(1, N_legnth):
            answer.append(str(K_list[0]))  
else:
    for j in range(i+1, N_legnth):
        answer.append(str(K_list[0]))

answer = int(''.join(answer))
print(answer)


#print(f'{K_list}')