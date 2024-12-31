#ifndef ASTRAL_BONUS_FIDIRS_H_
#define ASTRAL_BONUS_FIDIRS_H_ 1
// Astral by GeorgeRoot1912 GNU OPEN SOURCE! FIND IN GITHUB: https://github.com/GeorgeRoot1912/Astral.git
// GNU OPEN SORCE PROJECT. READ LICENSE.md
#include "dir.h"
#include "file.h"
#include <stdlib.h>
/* Return -23 if path not found; return -1 if dir not empty else return 0.*/
char DIRempty(const char* path){
    DIR *dir;
    dir = opendir(path);
    if (!dir)
    {
        return -23;
    };
    while (readdir(dir) != NULL)
    {
        return -1;
    };
    closedir(dir);
    return 0;
}
/* If file not found return -1, else return 0. */
char FILEexist(const char* path){
    if(open(path,0) != -1){return 0;}
    return -1;
}
/* If file not found or directory return -1, else return 0. */
char FILEis(const char* path){
    if(DIRexist(path) == -1){return 0;}
    return -1;
}
/* If file empty return 0; if file not found return -4; if file not empty return -1.*/
char FILEisEmpty(const char* path){
    if (open(path,1) == -1){return -4;}
    FILE *ptr;
    ptr = fopen(path, "r");
    if (strcmp("", FILEautoRead(path)) == 0){
        return 0;
    }
    return -1;
    fclose(ptr);
}
/*If path not found return -4; if dir not empty return -1; else 0.*/
char DIRisEmpty(const char* path){
    int len = DIRlen(path);
    if (len == -1){return -4;}
    if (len == 0){return 0;}
    return -1;
}
/* Copy data in from_path to to_path.*/
int FILEcopy(const char* from_path, const char* to_path){
    if (open(from_path, 1) == -1){return -1;}
    unsigned int a = FILElen(from_path);
    char* data = FILEread(from_path, a);
    FILE* ptr;
    ptr = fopen(to_path, "w");
    fwrite(data,a,1,ptr);
    return fclose(ptr);
}
/* Move data in from_path to to_path. DELETE FROM_PATH.*/
int FILEmove(const char* from_path, const char* to_path){
    if (open(from_path, 1) == -1){return -1;}
    unsigned int a = FILElen(from_path);
    char* data = FILEread(from_path, a);
    remove(from_path);
    FILE* ptr;
    ptr = fopen(to_path, "w");
    fwrite(data,a,1,ptr);
    return fclose(ptr);
}
/* Remove ONLY directory.*/
char DIRrem(const char* path){
    
    if(DIRexist(path) == -1){
        return -1;
    } remove(path); return 0;
}
/* If the directory is empty, it deletes it. If not found, returns -2; if directory not empty return -1.*/
char DIRerem(const char* path){
    DIR *dir;
    dir = opendir(path);
    struct dirent *entry;
    if (!dir)
    {
        return -2;
    };
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
            return -1;
        }
        
    };
    remove(path); return 0;
}
/* Create directory. */
char DIRmake(const char* path){
    if (open(path, 1) == -1){return -1;}
    char string[sizeof(path)+7];
    memcpy(string,"mkdir ",6);
    strcat(string, path); 
    system(string);   
    return 0;
}

/* Find in derectory. If searchable dir not found - return -2; if not found - return -1; else 0- ~65000. (You can shange)*/
short int DIRfind(const char* path, const char* findName){
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);   
    if(!dir){
        return -2;
    }
    short int n = 0;
    while ((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0){
            if(strcmp(entry->d_name,findName) == 0){
                closedir(dir);
                return n;
            };
            n++;
        }
    }    
    closedir(dir);
    return -1;
}

#endif