# rev-basic-0 (15)

## 문제

이 문제는 사용자에게 문자열 입력을 받아 정해진 방법으로 입력값을 검증하여 correct 또는 wrong을 출력하는 프로그램이 주어집니다.

해당 바이너리를 분석하여 correct를 출력하는 입력값을 찾으세요!

획득한 입력값은 DH{} 포맷에 넣어서 인증해주세요.

예시) 입력 값이 Apple_Banana일 경우 flag는 DH{Apple_Banana}

https://dreamhack.io/wargame/challenges/15

## 풀이

rev-basic-0와 거의 유사하니 생략하겠다..

https://github.com/GwangIl-Park/dreamhack-playground/tree/main/wargame/rev-basic-0

<details>
<summary>마지막 비교 함수</summary>
<div markdown="1">

```

undefined8 FUN_140001000(char *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 'C') {
    if (param_1[1] == 'o') {
      if (param_1[2] == 'm') {
        if (param_1[3] == 'p') {
          if (param_1[4] == 'a') {
            if (param_1[5] == 'r') {
              if (param_1[6] == '3') {
                if (param_1[7] == '_') {
                  if (param_1[8] == 't') {
                    if (param_1[9] == 'h') {
                      if (param_1[10] == 'e') {
                        if (param_1[0xb] == '_') {
                          if (param_1[0xc] == 'c') {
                            if (param_1[0xd] == 'h') {
                              if (param_1[0xe] == '4') {
                                if (param_1[0xf] == 'r') {
                                  if (param_1[0x10] == 'a') {
                                    if (param_1[0x11] == 'c') {
                                      if (param_1[0x12] == 't') {
                                        if (param_1[0x13] == '3') {
                                          if (param_1[0x14] == 'r') {
                                            if (param_1[0x15] == '\0') {
                                              uVar1 = 1;
                                            }
                                            else {
                                              uVar1 = 0;
                                            }
                                          }
                                          else {
                                            uVar1 = 0;
                                          }
                                        }
                                        else {
                                          uVar1 = 0;
                                        }
                                      }
                                      else {
                                        uVar1 = 0;
                                      }
                                    }
                                    else {
                                      uVar1 = 0;
                                    }
                                  }
                                  else {
                                    uVar1 = 0;
                                  }
                                }
                                else {
                                  uVar1 = 0;
                                }
                              }
                              else {
                                uVar1 = 0;
                              }
                            }
                            else {
                              uVar1 = 0;
                            }
                          }
                          else {
                            uVar1 = 0;
                          }
                        }
                        else {
                          uVar1 = 0;
                        }
                      }
                      else {
                        uVar1 = 0;
                      }
                    }
                    else {
                      uVar1 = 0;
                    }
                  }
                  else {
                    uVar1 = 0;
                  }
                }
                else {
                  uVar1 = 0;
                }
              }
              else {
                uVar1 = 0;
              }
            }
            else {
              uVar1 = 0;
            }
          }
          else {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


```

</div>
</details>