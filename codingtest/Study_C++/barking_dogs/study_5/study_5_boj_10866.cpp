#include <bits/stdc++.h>
using namespace std;

int main(){
    int count;
    string order;
    deque<int> DQ;

    cin >> count;

    while(count--){
        cin >> order;
        int number;
        if(order == "push_front"){
            cin >> number;
            DQ.push_front(number);
        }
        else if (order == "push_back"){
            cin >> number;
            DQ.push_back(number);
        }
        else if (order == "pop_front"){
            if (DQ.empty()){
                cout << "-1\n";
            }
            else{
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
            
        } 
        else if (order == "pop_back"){
            if (DQ.empty()){
                cout << "-1\n";
            }
            else{
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }      
        else if (order == "size"){
            cout << DQ.size() << "\n";
            
        } 
        else if (order == "empty"){
            if (DQ.empty()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
            
            
        }
        else if (order == "front"){
            if (DQ.empty()){
                cout << "-1\n";
            }
            else{
                cout << DQ.front() << "\n";
            }
            
        }
        else{
            if (DQ.empty()){
                cout << "-1\n";
            }
            else{
                cout << DQ.back() << "\n";
            }
        
        }
    }
    cin.get();
    return 0;
}