#include "./headers.h"

void man(char *(*argv)[], int argc)
{
    printf("-------------------------------------------------------------\n");
    if (argc == 1)
    {
        printf("* Manual *\n");
        printf("- 원하는 명령어의 사용법을 출력한다.\n");
        printf("\t ex)man cd\n");
    }
    else
    {
        if (strcmp((*argv)[1], "cd") == 0)
        {
            printf("* cd (Change Directory)\n");
            printf("- 작업중인 디렉토리의 위치를 변경할 때 사용한다.\n");
            printf("option : none\n");
        }
        else if (strcmp((*argv)[1], "mkdir") == 0)
        {
            printf("* mkdir (Make Directory)\n");
            printf("- 새로운 디렉토리를 생성한다.\n");
            printf("option : \n");
            printf("-p : 만들 디렉토리의 상위 디렉토리까지 한꺼번에 생성한다. \n");
            printf("\t + 여러개의 디렉토리를 한번에 생성할 수 있다.\n");
            printf("\t ex) mkdir temp1 temp2 temp3 \n\t ex) mkdir -p temp1/temp2 file1/file2/file3\n");
        }
        else if (strcmp((*argv)[1], "grep") == 0)
        {
            printf("* grep(Global Regex Print)\n");
            printf("- 파일에서 원하는 패턴을 찾아서 출력한다.\n");
            printf("option : \n");
            printf("-n : 파일 내에서 해당 패턴이 있는 줄의 번호를 같이 출력한다.\n");
            printf("-v : 해당 패턴을 지니고 있지 않는 줄들을 출력한다.\n");
            printf("-i : 대소문자 구분을 하지 않고 패턴이 존재하면 출려한다.\n");
        }
        else if (strcmp((*argv)[1], "ps") == 0)
        {
            printf("* ps\n");
            printf("- 현재 구동 중인 프로세스들을 출력한다.\n");
            printf("option : \n");
            printf("-a : 다른 사용자들의 프로세스 및 stat 컬럼 추가\n");
            printf("-u : 다른 터미널 프로세스 출력 및 기타 다른 컬럼 추가\n");
            printf("-x : 터미널이 존재하지 않는 프로세스 출력\n");
        }
        else if (strcmp((*argv)[1], "pwd") == 0)
        {
            printf("* pwd (Pring Working Directory)\n");
            printf("- 현재 작업중인 디렉토리의 위치를 알려준다.\n");
            printf("option : none\n");
        }
        else if (strcmp((*argv)[1], "chown") == 0)
        {
            printf("* chown(Change Owner)\n");
            printf("- 해당 파일의 소유권을 변경한다.\n");
            printf("\n\tex)chown username fileName\n");
            printf("option : \n");
            printf("-R : 디렉토리의 모든 하위 요소들의 owner와 group을 바꿔준다.\n");
        }
        else if (strcmp((*argv)[1], "chmod") == 0)
        {
            printf("* chmod(Change Mode)\n");
            printf("- 해당 파일의 mode를 변경한다.\n");
            printf("\tex)chmod 400 target(target의 mode를 400으로 변경한다.)\n");
            printf("option : \n");
            printf("-R : 디렉토리의 모든 하위 요소들의 mode를 바꿔준다.\n");
        }
        else if (strcmp((*argv)[1], "rmdir") == 0)
        {
            printf("* rmdir(Remove Directory)\n");
            printf("- 디렉토리를 삭제한다.\n");
            printf("option : \n");
            printf("-p : 삭제할 디렉토리의 상위 디렉토리까지 한꺼번에 삭제한다. \n");
            printf("\t + 여러개의 디렉토리를 한번에 삭제할 수 있다.\n");
            printf("\t ex) rmdir dir1 dir2 (동시에 디렉토리 삭제) \n\t ex) rmdir -p dir1/dir2/dir3(상위 디렉토리까지 삭제)\n");
        }
        else if (strcmp((*argv)[1], "mv") == 0)
        {
            printf("* mv (Move)\n");
            printf("- 파일을 이동한다.\n");
            printf("\t현재 파일을 다른 이름으로 이동(이름 바꾸기)\n");
            printf("\t\tex) cp sourceFile newFile\n");
            printf("\t현재 파일을 다른 디렉토리로 이동\n");
            printf("\t\tex) cp sourceFile direcory\n");
            printf("\t현재 파일을 다른 디렉토리에 다른 이름으로 이동\n");
            printf("\t\tex) cp sourceFile directory/newFile\n");
        }
        else if (strcmp((*argv)[1], "cp") == 0)
        {
            printf("* cp (Copy)\n");
            printf("- 파일을 복사한다.\n");
            printf("\t현재 파일을 다른 이름으로 복사\n");
            printf("\t\tex) cp sourceFile newFile\n");
            printf("\t현재 파일을 다른 디렉토리로 복사\n");
            printf("\t\tex) cp sourceFile direcory\n");
            printf("\t현재 파일을 다른 디렉토리에 다른 이름으로 복사\n");
            printf("\t\tex) cp sourceFile directory/newFile\n");
        }

        else if (strcmp((*argv)[1], "ls") == 0)
        {
            printf("* ls (List)\n");
            printf("- 디렉토리 내부의 파일과 하위 디렉토리 목록을 출력한다.\n");
            printf("option : \n");
            printf("\t-a(all) : 숨김 속성을 가진 파일까지 모두 표시\n");
            printf("\t-l(long) : 파일이나 디렉토리의 세부정보 표시\n");
            printf("\t-al(all long) : 숨김 속성을 가진 파일 포함 모든 세부정보 표시\n");
        }
        else if (strcmp((*argv)[1], "cat") == 0)
        {
            printf("* cat\n");
            printf("- 작은 파일의 내용을 터미널 창으로 보여준다.\n");
            printf("- 작은 내용의 파일을 생성한다.\n");
            printf("option : \n");
            printf("\t-n : 출력에 번호를 덧붙인다.\n");
            printf("\t> \'fileanme\' : 해당 파일명의 파일을 생성한다. ctrl+D 버튼을 통해 파일 종료\n");
        }
        else if (strcmp((*argv)[1], "find") == 0)
        {
            printf("* find\n");
            printf("- 파일이나 디렉토리 검색\n");
            printf("option : \n");
            printf("\t-name : 주어진 패턴과 일치하는 파일/디렉토리 검색\n");
            printf("\t-type [d/f] : 파일 종류가 같은 파일 탐색\n");
        }
        else if (strcmp((*argv)[1], "man") == 0)
        {
            printf("* man\n");
            printf("- 리눅스의 온라인 매뉴얼 페이지를 출력한다.\n");
        }
        else
        {
            printf("no existing command\n");
        }
    }
    printf("-------------------------------------------------------------\n");
}