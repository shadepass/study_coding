#include <bits/stdc++.h>
using namespace std;

//문제 자체가 이해하기가 매우 어려운데, 단순히 숫자놀이로 해도 풀림
//현재 스택에 열린 괄호가 있는데 레이저가 쏴지는 경우 그 개수만큼 정답에 ++
//그리고 그전에 있던게 닫힌 괄호에서 다음이 닫히는 경우 pop 하고 정답에 ++


int main(){
    cin.tie(0);
    stack<char> stick;
    string test;
    char prev;
    int answer = 0;

    cin >> test;


    for (auto a : test){
        if (a == '('){
            stick.push(a);
        }
        else if(a == ')'){
            if(prev == '('){
                stick.pop();
                answer += stick.size();
            }
            else{
                stick.pop();
                answer += 1;
            }
        }
        prev = a;
    }
    
    cout << answer;

    cin.get();
    return 0;
}