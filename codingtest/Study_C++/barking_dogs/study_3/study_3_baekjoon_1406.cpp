#include <bits/stdc++.h>
using namespace std;

//최대 600,000 글자 입력 가능
//영어 소문자만 기록할 수 있는 편집기
//편집기에는 커서라는 개념이 있으며 문장의 앞, 사이, 뒤에 위치할 수 있음(L 문자열에 커서는 L+1에 위치 가능)
// 지원 명령어 "L": 커서를 왼쪽으로 한 칸(맨 앞이면 무시)
// "D": 커서를 오른쪽으로 한칸(맨 끝이면 무시)
// "B": 커서 왼쪽에 있는 문장 삭제(맨 앞이면 무시)
// "P $": $라는 문자를 커서 왼쪽에 추가

//주어진 문장에서 커서 조작후 최종 문자열 출력
//시작시 커서는 문장 맨 뒤에 위치

// 커서를 C++ 리스트의 iterator를 가지고 지정
// L, D → ++, --로 이동, B-> -1 후 delete, P → iterator에 바로 추가
int main(){
    string cursor_list;
    string order;
    vector<char> order_vector;
    string number_string;
    list<char> L;
    getline(cin, cursor_list);
    
    getline(cin, number_string);
    int number_int = stoi(number_string);

    //L = cursor_list;
    
    for (int i = 0; i<cursor_list.size(); i++){
        L.push_back(cursor_list[i]);
        //cout << cursor_list[i] << "\n";
    }
    /*
    for(auto iter = L.begin(); iter != L.end(); iter++){
        cout << *iter << "\n";
    }
    */
    list<char>::iterator iter = L.end();

    for (int i = 0; i < number_int; i++){
        getline(cin, order);
        char word;
        vector<char> order_vector;
        istringstream order_stream(order);

        while(order_stream >> word){
            order_vector.push_back(word);
        }
        //list가 가리킨다 → 커서가 앞에있다.
        //end()랑 같다 가장 마지막에 위치한다. 

        char main_order = order_vector[0];
        if(main_order == 'D'){
            if(iter == L.end()){
                continue;
            }
            else{
                iter++;
            }
        }
        else if(main_order == 'L'){
            if(iter == L.begin()){
                continue;
            }
            else {
                iter--;
            }
        }
        else if(main_order == 'B'){
            if(iter == L.begin()){
                continue;
            }
            else if (iter == L.end()){
                L.pop_back();
                iter = L.end();
            }
            else{
                iter--;
                iter = L.erase(iter);
            }

        }
        else{
            if(iter == L.begin()){
                L.push_front(order_vector[1]);
                iter == L.begin();
            }
            else if(iter == L.end()){
                L.push_back(order_vector[1]);
                iter == L.end();
            }
            else{
                L.insert(iter, order_vector[1]);
            }
        }

    }
    
    for (auto i = L.begin(); i != L.end(); i++){
        cout << *i;
    }

    
    cin.get();
    return 0;
}

