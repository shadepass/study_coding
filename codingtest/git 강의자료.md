# 메타코드M 강의자료
- [Git & Github 핵심만 배우는 기초강의](https://www.youtube.com/watch?v=1kKed8cNzHU)

## init -> 파일 추가 -> commit 한 과정
- 현제 프로젝트 경로에 터미널 열기
- `git init` 명령어를 통해서 git 저장소로 만들기
- `git status` 변경된 파일이 있는지 확인하는 명령어
- `git add "파일명"` 해당 파일을 추적하도록 연결
- `git commit` 바로 실행하면 편집기로 로그 기록
  - `-m` 옵션달면 바로 이어서 로그 기록 가능
- `git log` 변경한 로그 확인 가능

## Commit
- 특정 시점을 기록한 단위(가장 중요한 기능)
- 서비스의 특정 배포 버전 = 특정 commit
- 파일의 네가지 상태
![파일의 네가지 상태](https://github.com/user-attachments/assets/1e268f13-0222-48d4-9582-68386e9dde50)
    - untracked: git 시스템에 의해 관리되고 있지 않은 상태
    - unmodified: commit된 이후로 수정되지 않은 상태
    - modified: commit 된 이후로 수정된 상태
      - 'change not staged for commit' 시현
    - staged: commit 대기중인 상태
      - staged 상태에 들어간 파일만 commit 됨
    - staged 상태와 modified 상태가 한 파일에 대해서 공존할 수 있음
      - 수정 후 add → staged 상태인데 이 상태에서 또 수정하게 되면
      - staged와 modified 두 상태가 나옴
      - commit 시 staged 상태일 때의 파일만 commit 되며 modified는 로컬에서 여전히 남아 있음
      - modified가 마지막 commit과 같아지는 후 다시 staged화 하는 경우 변경이 없는 걸로 git이 다 계산함

---
- `git checkout -- ./` modifed 된 것 초기화 하는 명령어
- 파일이 추가된 것 말고도 staged에 올리는 명령어가 `add` 명령어

## diff(파일 변경 내용 확인)
- 빨간색은 기존 상태, 초록색은 변경된 상태를 나타내줌
- `git diff "파일명"` or `git diff` 전체파일
  - modified 상태만 시현해줌
  - staged 상태는 안보여줌
- `git diff --staged` 명령어 수행 시 commit 파일과 staged 파일 비교
- staged 파일이 있는 상태에서 git diff 수행 시
  - staged와 modified 비교

## git log(commit 로그 확인)
- commit으로 돌아갈 때 commit ID 확인
- 파일이 큰 경우 편집기가 열리며 `:q` 명령어로 나올 수 있음
- `git log -p` 특정 파일에 어떤 수정 사항이 있는지를 알려줌

## git restore(커밋되지 않은 변경사항 되돌리기)
- `--staged` 옵션 추가해서 staged 상태도 modified로 돌릴 수 있음

## git revert
- `git revert commit_id` 명령어 수행 시 commit 로그 명령어 편집기 열림
- `wq` 문구 없이 바로 commit
- 완전히 이전 상태로 돌아가는 것이 아닌 이전 상태를 새롭게 commit하는거(그대로 가져와서 새로운 로그 작성 됨)

## git reset(히스토리를 완전 없애버리기) -> 한번 더 확인하자
- `git reset id 옵션(--mixed, --soft, --hard)`
  - mixed: 기본으로 modified 상태
  - soft: staged 상태로 넘어감
  - hard: 변경사항이 완전히 삭제되는 것
    - commit 그 자체가 사라지는 것, 다시 접근 불가능해짐
  - reset 말고 `revert` 쓰는게 훨신 안전함

## Github
- Git 프로젝트 전용 클라우드
- github, gitlab 등...
- 