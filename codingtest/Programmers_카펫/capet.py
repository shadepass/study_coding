def solution(brown, yellow):
    answer = []
    value = 1  # 처음 가로 길이
    while 1:
        if yellow % value == 0:
            width = value
            height = yellow // value  
            # 나누어 떨어지는 경우 --> 사각형 만들 수 있음
            if ((width * 2) + 4 + (height *2)) == brown:
                # 사각형의 외부를 감싸는 사각형 개수 구하는 공식
                width += 2
                height += 2
                if width < height:
                    answer = [height, width]
                else:
                    answer = [width, height]
                break
        value += 1
    return answer

#brown, yellow = 24, 24
#print(solution(brown, yellow))
