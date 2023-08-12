#include "./headers.h"

int load_text(char* txt);

char *strcasestr(const char *haystack, const char *needle)
//strcasestr이 라이브러리에 제공되지 않아 정의
//haystack: find 문자열이 포함되어 있는 지를 검사하는 대상 문자열
//needle: str 문자열에서 찾고자 하는 문자열
{
	int size = strlen(needle);

	while (*haystack)
	{
		if (strncasecmp(haystack, needle, size) == 0)
		{
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

char content[100000][100];
char content_i[10000][100];
int line = 0;

FILE *fp;

void my_grep(char* (*argv)[])
{
	int i, j, x = 0;
	int noption = 0;
	int voption = 0;
	int ioption = 0;
	char op;
	extern int optind;

    int arc = 0; 

    while ((*argv)[arc] != NULL){
	    arc++;
    }   
	int size = 256;
    char curDir[256];
    getcwd(curDir, size); //현재 디렉토리 위치
    optind = 1;
    
	while ((op = getopt(arc, (*argv), "nvi")) != -1)	//각 옵션들 확인 및 결정
	{
		switch (op)
		{
		case 'n':
			noption = 1;
			break;
		case 'i':
			ioption = 1;
			break;
		case 'v':
			voption = 1;
			break;
		case '?': //잘못된 옵션인 경우 오류 출력하고 함수 빠져나온다.
			return;
		default:
			printf("Error: please try again\n");
			return;
		}
	}

	if (arc < 3)
	{
		printf("Error: more arguments are needed\n");
		return;
	}
	else if ((noption || ioption || voption) == 0) //옵션이 없는 경우
	{
		if (load_text((*argv)[optind + 1]) == -1) //텍스트 파일을 배열에 저장
		{
			return;
		}

		for (i = 0; i < line; i++)
		{
			if (strstr(content[i], (*argv)[optind])) //strstr은 문자열에서 찾고자 하는 문자열의 포인터를 반환
				printf("%s", content[i]);
		}
	}
	else if (arc < 4)
	{
		printf("Error: more arguments are needed\n");
		return;
	}
	else if (ioption) //-i 옵션: 대소문자를 구분하지 않고 문자열을 찾는다.
	{
		if (load_text((*argv)[optind + 1]) == -1) //텍스트 파일을 배열에 저장
		{
			return;
		}

		for (i = 0; i < line; i++)
		{
			if (strcasestr(content[i], (*argv)[optind]))
				printf("%s", content[i]);
		}
	}
	else if (voption) //-v 옵션: 입력한 문자열을 포함하지 않는 내용만 출력
	{
		if (load_text((*argv)[optind + 1]) == -1) //텍스트 파일을 배열에 저장
		{
			return;
		}

		for (i = 0; i < line; i++)
		{
			if (!strstr(content[i], (*argv)[optind]))
				printf("%s", content[i]);
		}
	}
	else if (noption) //-n 옵션: 줄 번호를 함께 출력
	{
		if (load_text((*argv)[optind + 1]) == -1) //텍스트 파일을 배열에 저장
		{
			return;
		}

		for (i = 0; i < line; i++)
		{
			if (strstr(content[i], (*argv)[optind]))
				printf("%d: %s", i + 1, content[i]);
		}
	}
	else
		printf("Error: check the arguments again\n");
	line = 0;
}

int load_text(char* txt)
//텍스트 파일을 읽어오는 함수
//txt: 텍스트 파일의 이름
{
	if ((fp = fopen(txt, "r")) == NULL)
	{
		perror("Error: ");
		return -1;
	}

	while (!feof(fp))
	{
		fgets(content[line], 100, fp);
		line++;
	}
	fclose(fp);
	return 0;
}

