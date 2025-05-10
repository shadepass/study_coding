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
    vector<string> order_vector;
    int number;
    list<char> L;
    cin >> cursor_list;
    
    cin >> number;

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

    for (int i = 0; i < number; i++){
        getline(cin, order);
        string word;
        istringstream order_stream(order);

        while(order_stream >> order){
            order_vector.push_back(word);
        }

        
        cout << *iter << "\n";

        string main_order = order_vector[0];

        if(main_order == "D"){

        }
        else if(main_order == "B"){

        }
        else{

        }

    }

    return 0;
}

