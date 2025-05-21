#include <bits/stdc++.h>
using namespace std;

// 괄호 종류는 소괄호/대괄호 두 종류
// 마지막에 온점에 찍힘으로 종료를 나타냄
// 각 줄마다 문제가 없다면 yes, 문제가 있다면 no 표시



int main(){
    //stack<char> balance;
    cin.tie(0);
    string test;

    while(1){
        stack<char> balance;
        getline(cin, test);
        if (test == "."){
            break;
        }
        else{
            int count = 0;
            while(count < test.length()){
                if (test[count] == '('){
                    balance.push('(');
                }
                else if(test[count] == ')'){
                    if(balance.empty() || balance.top() != '('){
                        cout << "no\n";
                        break;
                    }
                    else{
                        balance.pop();
                    }
                }
                else if(test[count] == '['){
                    balance.push('[');
                }                    
                else if(test[count] == ']'){
                    if(balance.empty() || balance.top() != '['){
                        cout << "no\n";
                        break;
                    }
                    else{
                        balance.pop();
                    }

                }
                else if(test[count] == '.'){
                    if (balance.empty()){
                        cout << "yes\n";
                    }
                    else{
                        cout << "no\n";
                    }
                }
                count++;

            }
        }
    }
    
    cin.get();
    return 0;
}