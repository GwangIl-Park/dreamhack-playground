# session_basic (409)

## 문제

쿠키와 세션으로 인증 상태를 관리하는 간단한 로그인 서비스입니다.
admin 계정으로 로그인에 성공하면 플래그를 획득할 수 있습니다.

플래그 형식은 DH{…} 입니다.

https://dreamhack.io/wargame/challenges/409

## 풀이

정말 basic 문제인 듯...

서버쪽 코드(app.py)를 보면 home 경로에서 session_storage[session_id]가 admin인 경우, DH값을 얻을 수 있다.

```
@app.route('/')
def index():
    session_id = request.cookies.get('sessionid', None)
    try:
        # get username from session_storage
        username = session_storage[session_id]
    except KeyError:
        return render_template('index.html')

    return render_template('index.html', text=f'Hello {username}, {"flag is " + FLAG if username == "admin" else "you are not admin"}')
```

그리고 해당 값은 main함수에서 넣어준다.

```
if __name__ == '__main__':
    import os
    # create admin sessionid and save it to our storage
    # and also you cannot reveal admin's sesseionid by brute forcing!!! haha
    session_storage[os.urandom(32).hex()] = 'admin'
    print(session_storage)
    app.run(host='0.0.0.0', port=8000)
```

그런데 /admin path를 확인해보면 session_storage의 정보를 보여준다.

```
@app.route('/admin')
def admin():
    # developer's note: review below commented code and uncomment it (TODO)

    #session_id = request.cookies.get('sessionid', None)
    #username = session_storage[session_id]
    #if username != 'admin':
    #    return render_template('index.html')

    return session_storage
```

따라서 admin path로 접속해보면..

![image](https://github.com/GwangIl-Park/dreamhack-playground/assets/40749130/b75d7e55-cfb8-40aa-8ea3-f9371ea721ce)

admin의 session_id를 얻을 수 있다.

이제 chrome 개발자 도구를 통해 session_id를 강제로 넣어준다.

![image](https://github.com/GwangIl-Park/dreamhack-playground/assets/40749130/31ca6941-d7cd-493b-8ce9-3bd5c92dd4d8)

이후, home경로로 이동해보면 DH값을 얻을 수 있다.

![image](https://github.com/GwangIl-Park/dreamhack-playground/assets/40749130/1c380a61-af15-4a17-97eb-13ca88108a6a)