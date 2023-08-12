#include "headerFile/headers.h"

// 디렉토리 관련 함수 헤더
#include "headerFile/mkdir.h"
#include "headerFile/ls.h"
#include "headerFile/cat.h"
#include "headerFile/find.h"
#include "headerFile/chmod.h"
#include "headerFile/grep.h"
#include "headerFile/chown.h"
#include "headerFile/rmdir.h"
#include "headerFile/ps.h"
#include "headerFile/man.h"
#include "headerFile/cp.h"


#define MAX_ARGC 10 // 최대 가질 수 있는 옵션 9개, 명령어 제외
#define EXIT "exit"


//char* (*argv)[] 10개의 배열포인터를 가지고 있는 배열포인터
//명령어 문자열 분리를 해주는 함수
//메인문의 argv[0]에 명령어가 저장 다음 배열부턴 옵션이 문자열로 저장
int cmd_split(char* command_line, char* (*argv)[])
{
    int i = 0;
    char *temp;

    temp = strtok(command_line, " ");
    while(temp != NULL)
    {
        (*argv)[i] = temp;
        temp = strtok(NULL, " ");
        i++;
    }
    return i;
}

void init_argv(char* (*argv)[])
{
    for(int i=0; i<MAX_ARGC; i++)
    {
        (*argv)[i] = NULL;
    }
}

int main()
{   
    int i, argc;
    char buf[1024];
    char command[1024];
    char *argv[MAX_ARGC] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,}; // 크기가 10인 포인터배열
    char *temp;
    pid_t pid;
    int status;

    printf("\nOS team 3 >>>>\n");
    printf("starting os...\n\n");
    do{
        char *username = getlogin();
        struct passwd* userinfo = getpwnam(username);

        getcwd(buf, 1024); // buf 현재 순회중인 경로가 buf에 저장
        printf("%s@%s:~$ ", userinfo->pw_name,buf);
        rewind(stdin);
        scanf("%[^\n]s", command);
        getchar();

        argc = cmd_split(command, &argv);

        // argv[0] = 명령어가 문자열 형태로 저장, 다음 인수부턴 옵션이 문자열로 저장
        if(strcmp(argv[0], "cd") == 0) // 절대 경로 또는 상대 경로를 통해 디렉토리 변경
        { 
            chdir(argv[1]);
        }
        else if (strcmp(argv[0], "pwd") == 0) // 현재 디렉토리 경로 출력
        {    
            printf("%s\n", buf);
        } 
        else if (strcmp(argv[0], "ls") == 0) // 현재 디렉토리 내의 파일 출력
        {
            ls(&argv);
        }
        else if (strcmp(argv[0], "find") == 0)
        {
            _find(&argv);
        }
        else if (strcmp(argv[0], "clear") == 0)
        {
            write(1, "\033[1;1H\033[2J", 10);
        }
        else if (strcmp(argv[0], "chmod") == 0)
        {
            my_chmod(&argv);
        }
        else if (strcmp(argv[0], "grep") == 0)
        {
            my_grep(&argv);
        }
        else if (strcmp(argv[0], "chown") == 0)
        {
            my_chown(&argv, argc);
        }
        else if (strcmp(argv[0], "ps") == 0)
        {
            my_ps(&argv, argc);
        }
        else if (!strcmp(argv[0], "mkdir")) // 디렉토리 생성
        {
            if (argc > 2) {
                if (!strcmp(argv[1], "-m"))//접근권한을 본인이 설정할 수 있는 옵션
                {
                    Omkdir(argv[1], argv[3], argv[2]);
                }
                else if (!strcmp(argv[1], "-p"))//상위디렉토리도함께 생성.
                {
                    Omkdir(argv[1], argv[2], "755");
                }
                else
                    Mmkdir(argc, argv);
            }
            else{
                Omkdir("", argv[1], "755");
            }
                
        }
        else if (strcmp(argv[0], "mv") == 0) //copy 명령어 실행 후 원본파일 제거
        {
            cp(&argv);
            unlink(argv[1]); 
        }
        else if (strcmp(argv[0], "cp") == 0) // 파일 복사(디렉토리 x)
        {
            cp(&argv);
        }
        else if (!strcmp(argv[0], "rmdir"))
        {
            RMDIR(argc, argv);
        }
        else if (strcmp(argv[0], "cat") == 0)
        {
            if (argc == 2)
                Cat(argc, "", argv[1]);
            if (argc == 3)
                Cat(argc, argv[1], argv[2]);
        }
        else if (strcmp(argv[0], "man") == 0)
        {
            man(&argv, argc);
        }
        else if (strcmp(argv[0], EXIT) == 0)
        {
            break;
        }
        else {
            printf("error: not valid command\n\n");
        }

        init_argv(&argv);
        // ----------- exit => 종료 ---------------------
    }while(strcmp(command, EXIT)!=0);
    printf("GoodBye!\n");

    return 0;
}
