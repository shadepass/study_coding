마크다운(Markdown)이란
 - 웹상에서 글을 쓰는 모든 사람들 위한 글쓰기 도구(서식, 포맷, 양식)
 - HTML 형식으로 변환시켜주는 간소한 서식이다.
 - 간소한 서식이기에 모든 HTML을 지원하지는 않는다
 - 표준이 없기 떄문에 표현하는 도구/플랫폼에서 서로 다르게 시현될 수 있다.
---
---
> github에서는 font size, font 색, font 배경색이 불가함(HTML 문법들은 안 먹히는 듯) 

마크다운 문법 목차

<span style = "font-size: 200%">[1. 구분선](#구분선)</span><br>
<span style = "font-size: 200%">[2. 줄바꿈](#줄바꿈)</span><br>
<span style = "font-size: 200%">[3. 제목](#제목타이틀---크기지정)</span><br>
<span style = "font-size: 200%">[4. 인용](#인용-구문)</span><br>
<span style = "font-size: 200%">[5. 폰트](#폰트)</span><br>


# 구분선
구분선은 "---" or "***"을 이용해서 만들 수 있다.

# 줄바꿈
한 문단 내 줄바꿈을 위해서는 **스페이스바**를 두 번 누르고 엔터를 입력하거나  
```
<br> → 문법을 사용하면 문단 내 줄바꿈
```

# 제목(타이틀) - 크기지정
"#"을 이용해서 1단게부터 6단계 까지 지정가능
```
HTML의 <h1> ~ <h6> 태그와 동일한 문법이다.
```
# 제목1
## 제목2
### 제목3
#### 제목4
##### 제목5
###### 제목6
github의 경우 제목1과 제목2에는 자동으로 줄이 생성된다.

# 인용 구문
```
HTML의 <blockquote> 문법이며
```
마크다운에서는 ">" 기호로 나타낸다.  
중첩이 가능하며 인용문 안에서도 마크다운 문법 사용 가능
> ## 제일 바깥 인용
>> 인용의 인용
>>> 인용의 인용의 인용
>> 인용의 인용
```
>
>>
>
Github의 경우 위와 같이 작성된 경우,
2번째 깊이까지 내려갔으므로 같은 문단에서는 다시 깊이가 낮아지지 않는다.
(3번째 줄 인용문구가 생략되고 2번째줄에 인용 깊이와 같아진다.)
```

# 폰트
## 폰트 굵게(bold)
```
HTML 및 CSS 문법
  - <b> b 태그 </b>
  - <strong> strong 태그 </strong>
  - front-weight 속성(css)
```

```
**굵게**, __굵게__
```
> 단축키 : ctrl + B

**굵게**, __굵게__

## 폰트 기울이기
```
HTML의 <i> 문법이며
```

```
*굵게*, _굵게_
```
>단추키: ctrl + i

*굵게*, _굵게_

## 폰트 굵게 + 기울이기
```
***굵게 기울이기***, ___굵게 길울이기___
```
***굵게 기울이기***, ___굵게 기울이기___

## 취소선
```
~~취소~~
```
~~취소~~

## 글자 색깔
```
<span style ="color:red"> 입력문자 </span>
<span style ="color:blue"> 입력문자 </span>
```
<span style = "color:yellow"> 노란색 글씨 </span>

![PNG 색상표](image.png)

## 형광펜
```
<span style ="background-color:red"> 입력문자 </span>
<span style ="background-color:blue"> 입력문자 </span>
...
```
<span style = "background-color:red"> 빨강색 배경 </span><br>

## 글자 크기 조정
```
<span style ="font-size:250%"> 입력문자 </span>
<span style ="font-size:100%"> 입력문자 </span>
기본 글자에서 크기로 퍼센트로 글자 크기 조절
```
<span style ="font-size:200%"> 글자크기 기본 사이즈의 200% </span>

## HTML 태그를 이용한 폰트 수정 한번에 하기
```
<b?<span style = "color:white; background-color:red; font-size:150%"> 글자는 흰색, 배경은 빨강, 사이즈는 150% </span></b>
```
<b><span style = "color:white; background-color:red; font-size:150%"> 글자는 흰색, 배경은 빨강, 사이즈는 150% 굵기는 b태그로 설정</span>></b>

# 목차
```
목차는 "[]" + ()"를 이용해서 만들 수 있다.
[보여지는 부분](#링크 부분)
예시: [3. 제목](#제목타이틀---크기지정)
```
> 이때, 링크부분은 실제 "제목"과 동일하게 작성해야하며  
> 띄어쓰기는 "-"로 연결해야한다.  
> 또한, 제목1~제목5 동일하게 "#" 문구로 접근가능하다.

# 문자 박스(notice)
입력하는 문자를 강조하기 위해 박스에 넣는 문법
|Notice type|Class|
|:-:|:-|
|Dafult|.notice|
|Primary|.notice--primary|
|info|.notice--info|
|warning|.notice--warning|
|success|.notice-success|
|Danger|.notice-danger|

★ **notice가 안되는뎅
{: .notice--primary}

# 표(table)
파이프(|)를 이용해서 컬럼 만들기
기본 형태: 제목 한줄 + "-"를 이용한 표(table) 입력임을 표시
"-"개수는 의미 없다.
```
|제목1|제목2|제목3
|-|-|-|
|내용|내용|내용|
|내용|내용|내용|
```
> ---   정렬하지 않음  
> :---  왼쪽으로 정렬  
> ---:  오른쪽 정렬  
> :---: 가운대 정렬

|이름|나이|횟수|
|-|:-|-:|
|강아지|50|5
|고양이|30|4


# 링크 삽입
```
HTML의 <a href = "https://exapmle.com" alt = "설명문구 생략가능">링크</a>로 해석되는 문법
```
이것은 [링크](http://www.example.com) 입니다.

이것은 [링크](http://www.example.com " 설명문구 생략가능") 입니다.<br>
이것은 [구글링크][1] 입니다.
이것은 [마이크로소프트 링크][b] 입니다.
이것은 [애플링크][three] 입니다.<br>

[1] : https://www.google.co.kr "구글"
[b] : https://www.microsoft.com/ko-kr/ "마이크로소프트"
[three] : https://www.apple.com/kr/ "애플"

# 이미지 삽입
HTML의 <img src = "https:\\guides.github.com/images/log@2x.png", title = "깃헙">

![깃헙](https://guides.github.com/images/log@2x.png "설명문구 생략가능")
![깃허브][imgGithub]

[imgGithub] : https://www.google.co.kr/images/nav_log242.png "설명문구 생략가능"

1. 리스트
5.1. 순서있는 리스트: HTML의 <ol><li>번호</li></ol>
    1. 번호1
    2. 번호2
    3. 번호3
5.2. 순서없는 리스트: HTML의 <ul><li>번호</li></ol>
- 리스트
* 리스트
+ 리스트

*리스트
* 리스트
 * 리스트
 1. 리스트

6. 박스로 감싸기 -> 마크다운을 그래도 보여줌
6.1. 스페이스바 4번 누르고 글쓰기
``` 글 ```로 작성하기
    이렇게 하면 마크다운이 사라진다고?
    바로 이어서 하면 전체적으로 묶이는 건가

``` 테스트 ```
```
테스트
```
'''테스트'''
'''
테스트
'''

```
제목 : # , =====
인용 : >
강조 : * , _
링크 : [텍스트](주소 "설명 생략가능")
이미지 : ![텍스트](이미지주소 "설명 생략가능")
리스트 : 1 , * , - , +
코드표시 : <code>코드</code> , 한줄 띄우고 스페이스 4칸 , ```코드```
줄바꿈 : 엔터 2번 , 강제 줄바꿈은 문장끝에 스페이스바 2칸
가로선 : ----- , ***** , ++++
```
→ 가장 많이 사용되는 마크다운 태그

마크다운의 각 문법은 HTML로 변환되어 CSS와 함께 출력되기 때문에, 화면에 표시되는 모양은
사용하는 곳의 스타일 구성에 따라 달라짐

# 문법

마크다운 문법은 HTML 태그로 변환되어 브라우저에 출력됨
전부 대체하지 않으며 중요한 문법만을 제공

" # " 개수로 <h1>, <h2>, ... <h6> 태그로 변환할 수 있다.
이때, <h1> == #제목1 은 대재목으로 한 파일에 하나만 존재해야함

