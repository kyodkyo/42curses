# Minishell

쉘만큼이나 아름다운 그것

요약:이번 프로젝트의 목표는 간단한 쉘을 만드는 것입니다.맞아요, 당신만의 작은 bash이요.프로세스나 파일 디스크립터에 대해 아주 많이 배우게 될 겁니다.

# Introduction

쉘은 IT의 태초부터 함께했습니다.

그 당시, 모든 개발자들은 `1과 0으로만 이루어진 스위치로 컴퓨터와 통신하는 것은 굉장히 성가시다`는 점에 동의했어요.

`영어와 비슷한 언어로 작성된 명령어의 줄을 이용해 컴퓨터와 소통하는` 프로그램을 만들겠다는 아이디어를 떠올린 것도 당연한 수순이었죠.

감사하게도 `Minishell`과 함께라면, `Windows`가 존재하지 않았을 시절 사람들이 겪었던 문제를 마주해볼 수 있을 겁니다.

# Mandatory part

|  |  |
| --- | --- |
| 프로그램 이름 | minishell |
| 제출할 파일 | Makefile, *.h, *.c |
| Makefile | all, clean, fclean, re |
| 인자 |  |
| 사용가능한 외부 함수 | readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, gextcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs |
| Libft 사용여부 | Yes |
| 설명 | 쉘을 만드세요 |

당신의 쉘은:

- 새로운 명령어를 입력할 수 있는 `프롬프트`를 보여줘야 합니다.
- 작업 `히스토리`를 갖고 있어야 합니다.
- (PATH 변수나 상대, 절대 경로를 활용하여) 올바른 실행 파일을 찾아 실행할 수 있어야 합니다.
- `전역변수`는 한 개 초과를 사용할 수 없으며, 왜 전역변수를 사용했는지 깊게 생각해 보고 그 이유를 설명할 수 있어야 합니다.
- 닫히지 않은 따옴표나 특정되지 않은 특수문자 (\나 ; 등...) 을 해석하지 않아야 합니다.
- ' (단일 따옴표) 안에 있는 메타문자를 해석하지 않아야 합니다.
- " (이중 따옴표) 안에 있는 $ (달러 기호)를 제외한 메타문자를 해석하지 않아야 합니다.
- 다음의 리다이렉션을 구현해야 합니다:
    - `<`는 입력을 리다이렉션 하여야 합니다
    - `>`는 출력을 리다이렉션 하여야 합니다
    - `<<`에 구분 기호를 지정한 다음, 현재 소스에서 구분자를 포함한 줄을 만나기 전까지 입력값을 읽어들입니다. 기록을 업데이트할 필요는 없습니다!
    - `>>`는 출력을 추가 모드로 리다이렉션합니다.
- `파이프`( `|` 문자)를 구현해야 합니다. 각 파이프라인마다 명령어의 출력값은 파이프로 연결되어 다음 명령어의 입력값으로 들어가야 합니다.
- `환경변수` (`$` 다음에 문자열이 오는 형식) 은 그들의 값으로 확장되어야 합니다.
- `$?`는 가장 최근에 실행한 포그라운드 파이프라인의 종료 상태를 확장하여야 합니다
- `ctrl-C`, `ctrl-D` 그리고 `ctrl-\` 는 bash와 동일하게 동작하여야 합니다.
- 상호작용이 가능할 때:
    - `ctrl-C`는 새로운 줄에 새로운 프롬프트를 출력합니다
    - `ctrl-D`는 쉘을 종료합니다.
    - `ctrl-\`은 아무런 동작도 하지 않습니다.
- 다음의 `내장 기능들`을 실행할 수 있어야 합니다:
    - `n` 옵션을 사용할 수 있는 `echo`
    - 오직 상대 또는 절대경로만 사용하는 `cd`
    - 옵션이 없는 `pwd`
    - 옵션이 없는 `export`
    - 옵션이 없는 `unset`
    - 옵션이나 인자값이 없는 `env`
    - 옵션이 없는 `exit`

`readline()` 함수는 메모리 누수를 일으킬 수 있습니다. 이를 고칠 필요는 없습니다. 하지만 `당신이 직접 작성한 코드는 메모리 누수를 일으킬 수 있다는 것을 의미합니다.`

> 💡여러분은 과제의 설명에만 국한되도록 설계해야 합니다. 요구하지 않은 것들을 만드실 필요는 없습니다.
> 
> 
> 의문점이 생긴다면 [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/)를 참고하세요.

