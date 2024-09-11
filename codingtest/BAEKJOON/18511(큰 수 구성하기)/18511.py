import sys

input = sys.stdin.readline

N, K = map(int, input().split())

K_list = list(map(int, input().split()))
K_list.sort(reverse = True)

str_N = str(N)
N_length = len(str_N)
answer = []
out_flag = False
count = 0
current_j = -1

while len(answer) != N_length:
    keep_flag = False
    
    for j in range(current_j+1, len(K_list)):
        if K_list[j] > int(str_N[count]):
            pass
        elif K_list[j] == int(str_N[count]):
            keep_flag = True
            answer.append(j)
            break
        else:
            out_flag = True
            answer.append(j)
            break

    if out_flag == True:
        break

    if keep_flag == False:
        count -= 1
        if not answer:
            break
        current_j = answer.pop()
    else:
        count += 1

if out_flag == True:
    for j in range(count+1, N_length):
        answer.append(0)
elif not answer:
    for j in range(N_length-1):
        answer.append(0)

temp_answer = []
for i in range(len(answer)):
    temp_answer.append(str(K_list[answer[i]]))

temp_answer = int(''.join(temp_answer))
print(temp_answer)