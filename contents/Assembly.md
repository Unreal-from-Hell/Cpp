# 어셈블리 언어 입문


## 범용 레지스터 
<img src='./Images/Assembly/GPR.png' width=500/>

다양한 목적으로 사용되는 레지스터 들이 존재하지만 일반적으로 프로그래밍시 rax, rbx, rcx, rdx 종류를 사용한다


<br>

## 범용 레지스터 구조
<img src='./Images/Assembly/register.png' width=500/>

<br>

* RAX: 전체 64비트 
* EAX: RAX의 하위 32비트
* AX: EAX의 하위 16비트
* AH: AX의 상위 8비트
* AL: AX의 하위 8비트


<br>


### 메모리 구조
<img src='./Images/Assembly/Memory.png' width=400/>

메모리의 data 영역은 초기화 된 데이터를 올려두고 bss 영역에는 초기화 되지 않은 데이터를 올려둔다.
 * 주로 data 영역을 사용한다

초기화 된 데이터 
> 변수이름  크기 초기값
> * 크기: db(byte), dw(word), dd(dword), dq(qword)

초기화 되지 않은 데이터
> 변수이름 크기 개수
> * 크기: resb(byte), resw(word), resd(dword), resq(qword)

<br>

### 레지스터 연산 
```
%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    
    ; mov reg1, cst   // reg1 에 cst 데이터를 삽입
    ; mov reg1, reg2  // reg2 의 데이터를 reg1로 복사
    ; mov rax, a      // a의 주소값을 rax에 복사 
    ; mov rax, [a]    // a에 있는 값을 rax에다 복사 -> a범위 밖의 값까지 복사됨
    ; mov al, [a]     // a에 있는 값을 rax의 하위 8비트에 복사
    ; mov [a], byte 0x55 // a에 1바이트 크기의 0x55 값을 삽입
    ; mov [a], word 0x6666 // a에 word 크기의 0x6666 값을 삽입
    ; mov [a], cl     // a에 rcx의 하위 8비트 값을 복사
    xor rax, rax
    ret
    
; section .data
   a db 0x11
    
```

<br><br>

## 엔디안

<img src='./Images/Assembly/Endian.png' width=600/>
