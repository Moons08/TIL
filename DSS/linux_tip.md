### mail
`grep CRON /var/log/syslog` crontab 실행 명령 리스트
`sudo apt-get install postfix` 메일 만들기
`cat /var/mail/ubuntu` mail 읽기
`sudo apt install mailutils` mail check util

*in mail*
`d 1-4` 1번부터 4번까지 지우기
`quit` 지운 상태를 유지하고 나가기
`summary` 현재 상태 체크

#### Timezone  설정
```
vi .bash_profile
TZ = 'Asia/Seoul'
export TZ
```
#### alias
```
vi .bashrc
alias ssh=ssh -i /home/mk/documents/AWS/testkey.pem
```

#### python path 설정
```
/home/ubuntu/.pyenv/shims/python3.6
/home/ubuntu/.pyenv/versions/3.6.4/bin
```

```
.bash_profile # 세션에 로그인할 때 실행
.bashrc # 터미널 열 때마다 실행
```
#### 지난 명령어 사용
```
history
!(숫자)
```
