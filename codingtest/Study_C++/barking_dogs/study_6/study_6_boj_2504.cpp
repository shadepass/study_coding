#include <bits/stdc++.h>
using namespace std;

//10799랑 비슷하게 접근할 수 있겠다
//스택에 값들을 넣고, 닫히는 괄호가 나왔는데 스택에 top이 거기에 맞는 
//열리는게 아니라면 바로 0 출력하고 exit

//열리는 괄호랑 짝이 맞다면, 해당 괄호의 값이랑 스택에 남아있는 값(스택에 들어갈 때 곱해서 들어가기)
//이랑 곱해서 없애주기
//만약 스택에 값이 없는데, 이전 값이 열리는 괄호가 아니라면 그냥 pop만 하기

int main(){
    cin.tie(0);
    stack<char> pair;
    string test;
    char prev;
    int stack_value = 1;
    int answer = 0;

    cin >> test;

    for( auto a : test){
        if (a == '('){
            pair.push(a);
            stack_value *= 2;
        }
        else if(a == '['){
            pair.push(a);
            stack_value *= 3;
        }
        else if (a == ')'){
            if(pair.empty() || pair.top() != '('){
                answer = 0;
                break;
            }
            pair.pop();
            stack_value /= 2;
            
            if (prev == '('){
                if (pair.empty()){
                    answer += 2;
                }
                else{
                    answer = answer + (2 * stack_value);
                }
            }
            else{
                //다른 수와 곱했기 때문에 그냥 패스
            }
        }
        else if (a == ']'){
            if(pair.empty() || pair.top() != '['){
                answer = 0;
                break;
            }
            pair.pop();
            stack_value /= 3;
            
            if (prev == '['){
                if (pair.empty()){
                    answer += 3;
                }
                else{
                    answer = answer +  (3 * stack_value);
                }
            }
            else{
                //다른 수와 곱했기 때문에 그냥 패스
            }
        }
        prev = a;
    }
    if (!pair.empty()){
        answer = 0;
    }

    cout << answer;

    cin.get();
    return 0;
}