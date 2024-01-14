# rev-basic-0 (14)

## 문제

이 문제는 사용자에게 문자열 입력을 받아 정해진 방법으로 입력값을 검증하여 correct 또는 wrong을 출력하는 프로그램이 주어집니다.

해당 바이너리를 분석하여 correct를 출력하는 입력값을 찾으세요!

획득한 입력값은 DH{} 포맷에 넣어서 인증해주세요.

예시) 입력 값이 Apple_Banana일 경우 flag는 DH{Apple_Banana}

https://dreamhack.io/wargame/challenges/14

## 풀이

1. 해당 실행 파일을 실행해보면 "Input : "에서 값을 입력하고 correct 또는 wrong가 출력됨을 알 수 있다.

![image](https://github.com/GwangIl-Park/dreamhack-playground/assets/40749130/fb0b7252-9ec7-4b7e-b97e-a542567d6dd8)

2. correct 또는 wrong이 출력되는 값을 찾아야하므로 correct 값이 저장된 부분을 찾는다. (defined string)

![image](https://github.com/GwangIl-Park/dreamhack-playground/assets/40749130/840ff67b-20b5-4112-86bd-278523afca4b)

3. 해당 문자열이 참조되는 부분을 찾는다 (show reference to address)

```
void FUN_140001100(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined7 extraout_var;
  longlong lVar2;
  char *pcVar3;
  undefined auStack_138 [32];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_140003008 ^ (ulonglong)auStack_138;
  pcVar3 = local_118;
  for (lVar2 = 0x100; lVar2 != 0; lVar2 = lVar2 + -1) {
    *pcVar3 = '\0';
    pcVar3 = pcVar3 + 1;
  }
  FUN_140001190("Input : ",param_2,param_3,param_4);
  FUN_1400011f0("%256s",local_118,param_3,param_4);
  bVar1 = FUN_140001000(local_118);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    puts("Wrong");
  }
  else {
    puts("Correct");
  }
  __security_check_cookie(local_18 ^ (ulonglong)auStack_138);
  return;
}
```

FUN_140001190 함수는 "Input :" 을 출력하는 printf함수이고 
FUN_1400011f0 함수는 값을 입력받는 scanf함수임을 알 수 있다.

4. 그 아래의 FUN_140001000 함수를 따라가 보면, 어떤 데이터와 입력받은 string을 비교해서 true인지 확인하는 함수가 있다.

```
bool FUN_140001000(char *param_1)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,"###");
  return iVar1 == 0;
}
```

FLAG는 DH{###}