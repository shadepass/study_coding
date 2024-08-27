# 3. 코딩테스트 - BFS
- 그래프 탐색: 어떤 것들이 연속해서 이어질 때 모두 확인
  - BFS: Breadth-first search(너비 우선 탐색)
  - DFS: Depth-frist search(깊이 우선 탐색)
  - 예시
  
![image](https://github.com/user-attachments/assets/0f9e78a0-41fc-4d1e-b120-501829d89745)
  - BFS: 1->2->5->3->4->6
  - DFS: 1->2->3->4->6->5

## 아이디어
- 시작점에 연결된 Vertex 찾기
- 찾은 vertex를 queue에 저장
- Queue 뽑으면서 확인

## 시간복잡도
- BFS: O(V + E)

## 자료구조
- 검색할 그래프 있어야함
- 방문여부 확인 필요
- BFS -> Queue 사용

## 예시문제: 백준1926
- 문제: [백준링크](https://www.acmicpc.net/problem/1926)
- 