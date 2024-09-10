import sys

input = sys.stdin.readline

N, K = map(int, input().split())

K_list = list(map(int, input().split()))
K_list.sort(reverse = True)

str_N = str(N)
N_legnth = len(str_N)

answer = []

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
    if keep_flag == False and out_flag == False or out_flag == True:
        break

for j in range(i+1, N_legnth):
    answer.append(str(K_list[0]))

answer = int(''.join(answer))
print(answer)


#print(f'{K_list}')