깃 명령어 ctrl + ` 
깃 로그 


깃 상태 변경 git status
히스토리 만들기 git commit -m "first commit"
깃 넣기 git push origin master

commit version "설명 "
- 커밋
변경 작업들을 저장소에 기록 
사진 찍듯이 복사해서 저장소에 보존
내부 저장소   

-브랜치 
커밋에서 분기되면 브랜치 댐 
독립적으로 어떤 작업을 진행하기 위한 개념
버전 나누는것 
깃허브에서는 저장한 파일을
 master 브랜치에 그대로 유지하면서 
기존 파일을 수정하거나 새로운 기능 구현

- fork
원격 저장소 코드 복사해서  갖고 오는것 
원본과 연결되 있음.
원격 
fetch pull로 바꿀수있음 

- clone 
원격 저장소로부터 프로젝트를 복제하는것 
동일 버전 유지 

-push 
local 디렉토리로 부터 원격저장소 보냄 

-pull
 각의 브랜치에서 개발하여 커밋한 소스코드를
합칠때 요청하는 과정 
업데이트한 파일이 있을때 동일하게 만들기위해
사용


브랜치 
하나의 프로잭트 파일 여러개 
같이 코딩 
다른 걸 하고있지 
a 파일 b 파일 c 파일
브랜치를 따서 합쳐주면 c파일 비교해주고
똑같은 부분은 그냥 넘어가고 다른 부분만
보여주는거지 ? 
작업을 동시에 


fork 떠온 레포 clone 만들어서
add commit push 해서 팀 레포에 풀리퀘스트 
 

//////////////////////////////////////////
서순 

클론 갖고오고
코딩
add  저장소에 올릴 파일 선택
commit 컴퓨터 - 내부 저장소 
push  내부 - 원격 

//////////////////////////////////////////////
.gitignore : 깃에서 옵로드를 안할 파일 필요할때 사용 (아디 비번 등 중요 )
file.c
/file.c 최상위 폴더
모든 .c 확장자 파일
*.c

git status -상태확인
git add 	  타임캡슐 추가
git commit 타임캡슐  묻기 (버전 만들기)
git commit -m "설명" : 코밋만들면서 메세지 추가 
git diff 차이점  j올라가기 k  내려가기 :q 종료 
git commit -am 'message' 커밋된후 새로운 버전을 만들면서 add  

reset : 과거로 돌아가 이후 히스토리 삭제
revert : 같은 상태로 돌아가는거 

git reset --hard (돌아갈 커밋 해시)
git reset --hard  마지막으로 다시 돌아감 

git revert 

branch 분기
git branch ' '
git switch 
git switch -c ' ' 생성과 동시에 변경
git branch -d (삭제할 브랜드명)
git branch -m (기존 브랜치명)(새 브랜치명)