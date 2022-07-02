# AssemblyStudy

## 환경설정
> 22.06.27
- SASM설치
- HelloWorld 출력
- 어셈블러(번역기), 실행 파일 구조, 컴퓨터 구조, 메모리 구조

## 데이터 기초
> 22.06.27
- 비트, 바이트(8비트)
- 2진수, 8진수, 10진수, 16진수
- 2의 보수
- ; <- 주석
- 단위  
8bit = 1byte  
16bit = 2byte = 1word  
32bit = 4byte = 2word = 1dword(double-word)  
64bit = 8byte = 4word = 1qword(quad-word)  

## 레지스터 기초
> 22.06.27
- 레지스터 사용 이유 : 연산 결과 임시 저장소 역할
- a, b, c, d 레지스터 있음
- 레지스터 사용 단위  
rax => 64bit 사용(레지스터의 크기 전체 사용)  
eax => 32bit 사용  
ax => 16bit  
ah, al => 8bit 사용  
- 문법  
mov reg1, cst     : 어떤 값(cst) 레지스터에(reg1)에 넣어주세요  
mov reg1, reg2    : 두 번째 레지스터(reg2)의 값을 첫 번째 레지스터(reg1)에 복사해주세요

## 변수와 레지스터
> 22.06.27
- section .data
메모리를 사용하겠다는 것을 알려주기 위해 사용  
초기화 된 데이터  
[변수이름] [크기] [초기값]  
[크기] db(1byte) dw(2byte) dd(4byte) dq(8byte)  
ex)  
a db 0x11  
b dw 0x2222  
c dd 0x33333333  
d dq 0x4444444444444444  
- section .bss  
초기화 되지 않은 데이터  
[변수이름] [크기] [개수]  
[크기] resb(1byte) resw(2byte) resd(4byte) resq(8byte)  
ex)  
e resb 10  
- 변수의 선언 및 사용  
변수는 그냥 데이터를 저장하는 바구니  
처음에 바구니 사용하겠다 선언 (이름과 크기 지정)  
메모리에는 구분할 수 있도록 주소(번지수)가 있다  
- 메모리 <-> 레지스터  
ex)  
mov rax, a -> a라는 바구니의 주소값을 rax에 복사  
mov rax, [a] -> a라는 바구니 안에 있는 값을 rax에다 복사  
mov [a], byte 0x55 -> a 바구니에 0x55값을 넣음  

## 문자와 엔디안
> 22.06.27
- Big-Endian, Little-Endian  
Big-Endian의 경우 메모리에 숫자를 그대로 저장, 숫자 비교에 유리  
Little-Endian의 경우 메모리에 숫자를 거꾸로 저장, 캐스팅에 유리  
ex)  
b dd 0x12345678 으로 데이터 저장 하면  
메모리에 {0x78} {0x56} {0x34} {0x12} 로 저장(Little-Endian)  
- 같은 데이터를 다양한 방식으로 해석 할 수 있다

## 사칙연산
> 22.06.27
- 더하기 연산  
add a, b (a = a + b)  
a는 레지스터 or 메모리
b는 레지스터 or 메모리 or 상수  
단! a, b 모두 메모리는 X  
ex)  
add al, 1 (레지스터 + 상수)  
add al, [num] (레지스터 + 메모리)  
add al, bl (레지스터 + 레지스터)  
add [num], byte 1 (메모리 + 상수, 상수 크기 지정 필요)  
add [num], al (메모리 + 레지스터)  
- 빼기 연산  
sub a, b (a = a - b)  
문법은 더하기 연산과 동일  
- 곱하기 연산  
mul reg  
ex) mul bl => al * bl, 연산 결과를 ax에 저장  
ex) mul bx => ax * bx, 연산 결과를 dx(상위 16비트), ax(하위 16비트)에 저장  
ex) 5 * 8 은?  
```
mov ax, 0
mov al, 5
mov bl, 8
mul bl
```
- 나누기 연산  
```
div reg
ex) div bl => ax / bl, 연산 결과를 al(몫), ah(나머지)에 저장
ex) 100 / 3 은?
mov ax, 100
mov bl, 3
div bl
```

## 시프트 연산과 논리 연산
> 22.06.27
- 시프트(shift) 연산  
shift left는 2배 커짐  
shift right는 2배 작아짐  
곱셈/나눗셈에 용이  
게임서버에서 ObjectID를 만들어줄 때 사용  
ex)  
```
mov eax, 0x12345678
shl eax, 8
shr eax, 8
```
- 논리(logical) 연산  
bitflag에서 사용  
not and or xor  
not A : 0이면 1, 1이면 0  
A and B : 둘다 1이면 1, 아니면 0  
A or B : 둘중 하나라도 1이면 1, 아니면 0  
A xor B : 둘다 1이거나 둘다 0이면 0, 아니면 1  
동일한 값으로 xor 두번하면 자기 자신으로 되돌아오는 특성  
-> 암호학에서 유용하다! (value xor key)  
```
ex)
and al, bl
not al
or al, bl
xor al, bl
```

## 분기문 (if)
> 22.06.27
- 의미  
특정 조건에 따라서 코드 흐름을 제어하는 것  
ex) 스킬 버튼 눌렀는가? YES -> 스킬 사용  
ex) 제한 시간 내에 던전 입장 수락 버튼을 눌렀는가? YES -> 입장, NO -> 던전 취소  
- 문법  
CMP dst, src (dst가 기준)  
비교를 한 결과물은 Flag Register 저장  
- JMP [label] 시리즈  
JMP : 무조건 jump  
JE : JumpEquals 같으면 jump  
JNE : JumpNotEquls 다르면 jump  
JG : JumpGreater 크면 jump  
JGE : JumpGreaterEquals 크거나 같으면 jump  
JL, JLE  
  
ex) 두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램
```
    mov rax, 10
    mov rbx, 10
    cmp rax, rbx
        
    je LABEL_EQUAL
    ; je에 의해 점프를 안했다면, 같지 않다는 의미
    mov rcx, 0
    jmp LABEL_EQUAL_END
   
LABEL_EQUAL:
    mov rcx, 1
    
LABEL_EQUAL_END:
    PRINT_HEX 1, rcx
    NEWLINE
```

## 반복문 (while for)
> 22.06.27
- 의미  
특정 조건을 만족할때까지 반복해서 실행  
- 문법  
ex) Hello World를 10번 출력해야 한다면?  
```
    mov ecx, 10
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx; sub ecx, 1과 동일    
    cmp ecx, 0
    jne LABEL_LOOP
```
ex) 1에서 100까지의 합을 구하는 프로그램
```
    mov eax, 100 ; 최종 목적지
    xor ebx, ebx ; mov ebx, 0 ebx : 결과물
    xor ecx, ecx

LABEL_SUM:
    inc ecx ; add ecx, 1과 동일
    add ebx, ecx
    cmp ecx, eax
    jne LABEL_SUM    
    
    PRINT_DEC 4, ebx
    NEWLINE
```
- loop 구문 사용  
loop [라벨]  
ecx에 반복 횟수  
loop 할때마다 ecx 1감소 0이면 빠져나감 아니면 라벨로 이동  
ex)  
```
    mov ecx, 100
    xor ebx, ebx
LABEL_LOOP_SUM:
    add ebx, ecx
    loop LABEL_LOOP_SUM
    
    PRINT_DEC 4, ebx
    NEWLINE
```

## 배열과 주소
> 22.06.28
- 의미
동일한 타입의 데이터 묶음  
배열을 구성하는 각 값을 배열 요소(element)라고 함  
배열의 위치를 가리키는 숫자를 인덱스(index)라고 함  
- 문법  
ex)  
```
a db 0x01, 0x02, 0x03, 0x04, 0x05 ; 5 * 1 = 5바이트
b times 5 dw 1 ; 5 * 2 = 10바이트

; a배열의 모든 데이터 출력하기
    xor ecx, ecx
LABEL_PRINT_A:
    PRINT_HEX 1, [a+ecx]
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne LABEL_PRINT_A

; b배열의 모든 데이터 출력
    xor ecx, ecx
LABEL_PRINT_B:
    PRINT_HEX 2, [b+ecx*2]
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne LABEL_PRINT_B
```

## 함수 기초
> 22.06.28
- 의미  
함수 (프로시저 procedure 서브루틴 subroutine)  
ex)  
```
    call PRINT_MSG

PRINT_MSG:
    PRINT_STRING msg
    NEWLINE
    ret
```
ex)
```
    ; 두 값중 더 큰 값을 반환하는 max
    ; 근데 두 값을 어떻게 넘겨받지? 반환 어떻게?
    ; eax와 ebx 입력값을 ecx에 반환

    mov eax, 10
    mov ebx, 15
    call MAX
    PRINT_DEC 4, ecx
    NEWLINE

MAX:
    cmp eax, ebx
    jg L1
    mov ecx, ebx
    jmp L2
L1:
    mov ecx, eax
L2:
    ret
```

그런데 인자가 10개라면 어떻게 할까?  
eax, ebx에 이미 중요한 값이 있으면 어떻게 할까?  
[!] .data .bss 사용하면?  
인자를 도대체 몇개를 할당해야 하지?  

-> 다른 메모리 구조가 필요하다  
-> 꿈이 유효한 동안에는 그 꿈을 유지시켜야 함(유효 범위의 개념이 있다)  
-> 꿈이 끝나면 그 꿈을 부셔버려도 됨(정리의 개념이 있다)  
-> 꿈에서도 또 꿈을 꿀 수 있다는 것을 고려해야 함(유동적으로 유효 범위가 확장 가능)  
  
-> [!] 스택(stack)이라는 메모리 영역을 사용  
-> 함수가 사용하는 일종의 메모장  
-> 매개 변수 전달  
-> 돌아갈 주소 관리  

## 스택 메모리
> 22.06.28
- 스택 메모리, 스택 프레임  
레지스터는 다양한 용도로 사용  
a b c d - 범용 레지스터  
포인터 레지스터 (포인터 = 위치를 가리키는~)  
ip (Instruction Pointer) : 다음 수행 명령어의 위치  
sp (Stack Pointer) : 현재 스택 top 위치 (일종의 cursor)  
bp (Base Pointer) : 스택 상대주소 계산용  
ex)  
```
    push rax
    push rbx
    push 5
    push 2
    call MAX
    PRINT_DEC 8, rax
    NEWLINE
    add rsp, 16
    pop rbx
    pop rax
    
    xor rax, rax
    ret
    
MAX:
    push rbp
    mov rbp, rsp
    
    mov rax, [rbp + 16]
    mov rbx, [rbp + 24]
    cmp rax, rbx
    jg L1
    mov rax, rbx
L1:    
    pop rbp
    ret  
```