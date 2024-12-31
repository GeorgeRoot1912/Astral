#ifndef ASTRALS_DIRS_H_
#define ASTRALS_DIRS_H_ 1
// Astral by GeorgeRoot1912 GNU OPEN SOURCE! FIND IN GITHUB: https://github.com/GeorgeRoot1912/Astral.git
// GNU OPEN SORCE PROJECT. READ LICENSE.md
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
// recursive create, remove, getsize, 
/*If path not found return -1 else 0. */
char DIRexist(const char* path){
    DIR *dir;
    dir = opendir(path);
    if (!dir)
    {
        return -1;
    };
    closedir(dir);
    return 0;
}
/* Return count files in directory. If searchable dir not found return -2.*/
int DIRlen(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if (!dir)
    {
        return -1;
    };
    int len = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            len++;
        }
    };
    closedir(dir);
    return len;
}
/* RETURN POINTER ON ARRAY NAME FILES AND DIRS(STRINGS) FROM HEAP.
 USE WITH FREE(). THIS FUNCTION USE MALLOC().*/
char** DIRget(const char* path){
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if (!dir){
        char* a = "/NOTFIND/"; 
        char** b = &a;
        return b;
    }
    char** dirlist = (char**) malloc(DIRlen(path));
    unsigned int en = 0;
    while ((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0){
        dirlist[en] = entry->d_name;
        en++;
        }
    }
    closedir(dir);
    return dirlist;
}
char** DIRdget(const char* path){
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if (!dir){
        char* a = "/NOTFIND/"; 
        char** b = &a;
        return b;
    }
    char** dirlist = (char**) malloc(DIRlen(path));
    unsigned int en = 0;
    char* rev = (char*) malloc(strlen(path) + 58); strcpy(rev, path);
    while ((entry = readdir(dir)) != NULL){
        strcat(rev, entry->d_name);
        if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0 && DIRexist(rev) == 0){
        dirlist[en] = entry->d_name;
        en++;
        rev = "";
        }
    }
    free(rev);
    closedir(dir);
    return dirlist;
}

#endif