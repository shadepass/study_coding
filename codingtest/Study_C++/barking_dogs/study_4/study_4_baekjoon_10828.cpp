//https://www.acmicpc.net/problem/10828
#include <bits/stdc++.h>
using namespace std;

/*
명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 
만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 
만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다
*/


int main(){
    //ios::sync_with_stdio(false); // C I/O 비활성화로 속도 향상
    //cin.tie(NULL);               // cin과 cout 분리

    int count;
    cin >> count;
    stack<int> test_stack;

    while(count--){
        string temp;
        cin >> temp;
        if (temp == "push"){
            int number;
            cin >> number;
            test_stack.push(number);
        }
        else if (temp == "pop"){
            if (test_stack.empty()){
                cout << "-1\n";
            }
            else{
                cout << test_stack.top() << "\n";
                test_stack.pop();
            }  
        }
        else if (temp == "size"){
            cout << test_stack.size() << '\n';
        }
        else if (temp == "empty"){
            if (test_stack.empty()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }            
        }
        else{ //top
            if (test_stack.size() >= 1){
                cout << test_stack.top() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
    }
    cin.get();
//    cout << "hello";
    return 0;
}
