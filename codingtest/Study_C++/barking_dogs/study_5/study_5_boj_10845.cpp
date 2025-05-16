#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> answer;
    cin.tie(0);

    int count;
    cin >> count;
    while(count--){
        string order;
        cin >> order;
        if (order == "push"){
            int number;
            cin >> number;
            answer.push(number);
        }
        else if(order == "pop"){
            if (answer.empty()){
                cout << "-1\n";
            }
            else{
                cout << answer.front() << "\n";
                answer.pop();
            }
        }
        else if(order =="size"){
            cout << answer.size() << "\n";

        }
        else if(order == "empty"){
            if (answer.empty()){
                cout << "1\n";
            }
            else cout << "0\n";
        }
        else if(order == "front"){
            if (answer.empty()){
                cout << "-1\n";
            }
            else{
                cout << answer.front() << "\n";
            }
        }
        else{
            if (answer.empty()){
                cout << "-1\n";
            }
            else{
                cout << answer.back() << "\n";
            }
        }
    }
    cin.get();
    return 0;
}