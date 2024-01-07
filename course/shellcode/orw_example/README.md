# orw (open-read-write)

https://mixolydian-closet-a12.notion.site/orw-3a7cb15d4d934c7bbf2c60fd17b8b3b4?pvs=4

### 실행

- 테스트용 파일 생성
```c
echo 'flag{this_is_open_read_write_shellcode!}' > /tmp/flag
```

- 컴파일 및 실행
```c
$ gcc -o orw orw.c -masm=intel
$ ./orw
flag{this_is_open_read_write_shellcode!}
```
