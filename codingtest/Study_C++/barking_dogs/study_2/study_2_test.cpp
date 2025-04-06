#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N){
    int a[100] = {0};
    
    for (int i = 0; i<N; i++){
        if (arr[i] == 100 - arr[i]){
            a[arr[i]] += 1;
            continue;
        }
        a[arr[i]] +=1;
        a[100 - arr[i]] +=1; 
    }

    for(int i = 0; i<100; i++){
        if (a[i] >= 2)
            return 1;
    }
    return 0;
  }

/*
for (int i = 0; i < N; i++){
    if(occur[100 -arr[i]] == 1)
        return 1;
    occur[arr[i]] = 1;
}
*/

void test2(){
    //두 합이 100인 쌍이 있는가
    cout << "****** func2 test ******\n";
    int arr[3][4] = {{1,52,48}, {50,42}, {4,13,63,87}};
    int n[3] = {3, 2, 4};
    int ans[3] = {1, 0, 1};
    for(int i = 0; i < 3; i++){
      int result = func2(arr[i], n[i]);
      cout << "TC #" << i << '\n';
      cout << "expected : " << ans[i] << " result : " << result;
      if(ans[i] == result) cout << " ... Correct!\n";
      else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
  }

//주어진 길이 N의 int배열 arr에서 합이  100인 서로 다른 위치의 두 원소가 존재하면
// 1, 아니면 0을 반환하는 함수 func(int arr[], int N)
// arr의 각 수는 0이상 100이하, N는 1000이하

// 100개의 배열 만들기 자기 숫자있는데에 값 넣고, 100-자기값에 값넣기
// 그래서 100개 배열 돌면서 2이상 있으면 1출력 아니면 0 출력
int main(void){
    test2();
    cin.get();
  }