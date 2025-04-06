#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
    //addr은 해당 주소 다음값에 넣고싶다는 의미
    //해당 주소를 가지고 있는 값을 찾아야 하기 때문에 배열은 한번 돌아야함
    //for 넣어서 nxt[0]부터 시작해서 addr 찾으면
    //0 nxt에 있는거 temp로 넣어놓고
    //0 nxt에는 unused로 넣고
    //temp 이전에는 unused, unused next에는 temp 넣어서 끝내기
    
    if (addr == 0){
        int temp = nxt[0];
        nxt[0] = unused;
        dat[unused] = num;
        pre[unused] = 0;
        nxt[unused] = temp;
        pre[temp] = unused;
        unused +=1;
    }
    else{
        int cur = nxt[0];
        while(cur != addr){
            cur = nxt[cur];
        }
        int temp = nxt[cur];
        nxt[cur] = unused;
        dat[unused] = num;
        pre[unused] = cur;
        nxt[unused] = temp;
        pre[temp] = unused;
        unused +=1;
    }
}

void erase(int addr){
    int cur = nxt[0];
    while(cur != addr){
        cur = nxt[cur];
    }
    int cur_next = nxt[cur];
    int cur_prev = pre[cur];
    int cur_dat = dat[cur];
    nxt[cur] = -1;
    dat[cur] = -1;
    pre[cur] = -1;
    unused -= 1;
    nxt[cur_prev] = cur_next;
    pre[cur_next] = cur_prev;
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
  cin.get();
}