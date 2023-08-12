#include "./headers.h"

void recursive(char *name, char *target)
{
    DIR *dir;
    struct dirent *entry;
    char *ptr;

    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            strcpy(path, name);
            strcat(path, "/");
            strcat(path, entry->d_name);

            if(target == NULL){
                printf("%s\n", path);
            }
            recursive(path, target);
        } else if(target == NULL){
            printf("%s/%s\n", name, entry->d_name);
        }
        else { // -name 옵션과 함께 출력할 파일명 결정
            ptr = NULL;
            ptr = strstr(entry->d_name, target);     // target 문자열 검색, 포인터 반환
            if (ptr != NULL){
                printf("%s/%s\n", name, entry->d_name);
            }
        }
    }
    closedir(dir);
}

void recursive2(char *name, char *mode)
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            strcpy(path, name);
            strcat(path, "/");
            
            strcat(path, entry->d_name);
            if (strcmp(mode, "d") == 0){
                printf("%s\n", path);
            }
            
            recursive2(path, mode);
        }
        else if(strcmp(mode, "f") == 0){
            printf("%s/%s\n", name, entry->d_name);
        }
    }
    closedir(dir);
}

void _find(char* (*argv)[])
{
    DIR *dir;
    struct dirent *entry;

    if ((*argv)[2] == NULL){ // ex) find temp / find test.txt
        // 디렉토리인지 파일인지 먼저 알아야한다.
        if (!(dir = opendir(".")))
            return;

        while ((entry = readdir(dir)) != NULL) {
            if(strcmp(entry->d_name, (*argv)[1]) == 0){
                if (entry->d_type == DT_DIR) {
                    recursive((*argv)[1], NULL);
                } else {
                    printf("%s\n", entry->d_name);
                }
                closedir(dir);
                return;
            }
        }
        printf("error : not exist\n");
        closedir(dir);
    }
    else if(strcmp((*argv)[2], "-name") == 0){ // ex) find <path> -name <keyword>
        recursive((*argv)[1], (*argv)[3]);
    }
    else if(strcmp((*argv)[2], "-type") == 0){ // ex) find <path> -type <keyword>
        recursive2((*argv)[1], (*argv)[3]);
    }
}
