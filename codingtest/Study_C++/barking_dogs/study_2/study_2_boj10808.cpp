#include <bits/stdc++.h>
//#include <vector>
using namespace std;

int main(void){
//26개 크기의 vector 생성
    vector<int> S(26);

//단어 입력받음
    string word;
    cin >> word;
    
    for (int i =0; i < word.length(); i++){
        S[word[i] - 'a'] += 1; 
    }

//단어 루프 돌면서 해당 단어 숫자와 동일한 배열 넘버 ++ 하기

//vector 처음부터 돌면서 출력
    
    for(int e : S)
        cout << e << ' '; 

    //26개 크기의 vector 생성
    cin.get();
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(char s = 'a'; a <= 'z'; a++){
        int cnt = 0;
        for(auto c : s){
            if (a == c) cnt ++
        cout << cnt << ' ';
    }
}
*/