#include <bits/stdc++.h>
using namespace std;

int func1(int N){
    int n_3, n_5;
    int answer = 0;
    for(int i = 0; i<=N; i++){
        if(i % 3== 0){
            answer += i;
            continue;
        }
        if(i % 5 == 0){
            answer += i;
        }
    }
    
    return answer;
}

int func2(int arr[], int N){
  for (int i = 0; i<N; i++){
    for(int j = i+1; j<N; j++){
        if (arr[i] + arr[j] == 100){
            return 1;
        }
    }
  }
  return 0;
}

int func3(int N){
    for(int i = 1; i * i <= N; i++){
        if (i*i == N) return 1;
    }
  return 0;
}

int func4(int N){
    int count = 0;
    for(int temp = N; ; temp = temp/2){
        count+= 1;
        if (temp / 2 == 1)
            break;
    }

  return pow(2, count);
}

void test1(){
  cout << "****** func1 test ******\n";
  //3의 배수 또는 5의 배수를 모두 더하라
  int n[3] = {16, 34567, 27639};
  int ans[3] = {60, 278812814, 178254968};
  for(int i = 0; i < 3; i++){
    int result = func1(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if(ans[i] == result) cout << " ... Correct!\n";
    else cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

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

void test3(){
    //제곱근이면 1, 아니면 0
  cout << "****** func3 test ******\n";
  int n[3] = {9, 693953651, 756580036};
  int ans[3] = {1, 0, 1};
  for(int i = 0; i < 3; i++){
    int result = func3(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if(ans[i] == result) cout << " ... Correct!\n";
    else cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

void test4(){
    // N 이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 N 은 10억
  cout << "****** func4 test ******\n";
  int n[3] = {5, 97615282, 1024};
  int ans[3] = {4, 67108864, 1024};
  for(int i = 0; i < 3; i++){
    int result = func4(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if(ans[i] == result) cout << " ... Correct!\n";
    else cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

int main(void){
  test1();
  test2();
  test3();
  test4();
  cin.get();
}