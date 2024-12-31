#ifndef ASTRAL_PATH_H_
#define ASTRAL_PATH_H_ 1
// Astral by GeorgeRoot1912 GNU OPEN SOURCE! FIND IN GITHUB: https://github.com/GeorgeRoot1912/Astral.git
// GNU OPEN SORCE PROJECT. READ LICENSE.md
#include <string.h>
#include <stdlib.h>
// Path separator (You can delete this.)
#ifdef __unix
#define PathSep '/'
#endif
#ifdef __linux
#define PathSep '/'
#endif
#ifdef __APPLE
#define PathSep '/'
#endif
#ifdef __FREEBSD
#define PathSep '/'
#endif
#ifdef _WIN32
#define PathSep '\\'
#endif
#ifdef _WIN64
#define PathSep '\\'
#endif
/*Return path to file/dir without name file/dir.*/
char* Pathget(const char* path){
    unsigned int count_first_symbol_file = 0;
    long unsigned int slen = strlen(path);
    for(unsigned int i=0; i<slen; i++){
        if (path[i] == PathSep){
            count_first_symbol_file = i;
        }
    } 
    count_first_symbol_file++;
    char* filename = (char*) malloc(count_first_symbol_file-1);
    unsigned char n = 0;
    for(register unsigned int i=0; i<count_first_symbol_file-1; i++){
        filename[n] = path[i];
        n++;
    }
    return filename;
}
unsigned char Pathdeep(const char* path){
    unsigned int count_first_symbol_file = 0;
    long unsigned int slen = strlen(path);
    for(unsigned int i=0; i<slen; i++){
        if (path[i] == PathSep){
            count_first_symbol_file++;
        }
    } 
    if(path[0] == '.' && path[1] == '.'){
        count_first_symbol_file++;
        if(path[2] == '.'){count_first_symbol_file++; if(path[3] == '.'){count_first_symbol_file++;}}
    }
    return count_first_symbol_file;
}
/*Return root directory in path.*/
char* PathgetRoot(const char* path){
    unsigned int count_first_symbol_file = 0;
    long unsigned int slen = strlen(path);
    for(unsigned int i=0; i<slen; i++){
        if (path[i] == PathSep){
            count_first_symbol_file = i;
            break;
        }
    } 
    count_first_symbol_file++;
    char* filename = (char*) malloc(count_first_symbol_file-1);
    unsigned char n = 0;
    for(register unsigned int i=0; i<count_first_symbol_file-1; i++){
        filename[n] = path[i];
        n++;
    }
    return filename;
}
/* Return file extention(.exe or .txt and other) in path.
 Return char*(string). If the file does not have an extension,
 it returns an error value.
 You can use DIRgetName() to solve the problem.*/
char* PathgetExtension(const char* path){
    unsigned int count_first_symbol_file = 0;
    long unsigned int len = strlen(path);
    for(register unsigned int i=0; i<len; i++){
        if (path[i] == '.'){
            count_first_symbol_file = i;
        }
    } 
    count_first_symbol_file++;
    char* filename = (char*) malloc(len - count_first_symbol_file);
    unsigned char n = 0;
    for(register unsigned int i=count_first_symbol_file; i<len; i++){
        filename[n] = path[i];
        n++;
    }
    return filename;
}
/* If path absolute return -1, else return 0. */
char PathisReleative(const char* path){
    if(path[0] == '.'){return 0;}
    return -1;
}
/* If path absolute return 0, else return -1. */
char PathisAbsolute(const char* path){
    if(path[0] == '.'){return -1;}
    return 0;
}
/* Return file name in path. Return pointer char* in heap
USE WITH free(). */
char* PathgetName(const char* path){
    unsigned int count_first_symbol_file = 0;
    long unsigned int slen = strlen(path);
    for(unsigned int i=0; i<slen; i++){
        if (path[i] == PathSep){
            count_first_symbol_file = i;
        }
    } 
    count_first_symbol_file++;
    char* filename = (char*) malloc(slen - count_first_symbol_file);
    unsigned char n = 0;
    for(register unsigned int i=count_first_symbol_file; i<slen; i++){
        filename[n] = path[i];
        n++;
    }
    return filename;
}
/* Return file name without extention.
USE WITH free().*/
char* PathgetNamewe(const char* path){
    unsigned int count_first_symbol_file = 0;
    long unsigned int slen = strlen(path);
    unsigned int end = 0;
    for(unsigned int i=0; i<slen; i++){
        if (path[i] == PathSep){
            count_first_symbol_file = i;
        }
        if (path[i] == '.'){
            end = i;
        }
    } 
    count_first_symbol_file++;
    char* filename = (char*) malloc(end - count_first_symbol_file);
    unsigned char n = 0;
    for(register unsigned int i=count_first_symbol_file; i<end; i++){
        filename[n] = path[i];
        n++;
    }
    return filename;
}
/* Join path1 and path2. Merge path. RETURN POINTER
CHAR* IN HEAP(MALLOC()). USE free().*/
char* Pathjoin(const char* path1, const char* path2){
    unsigned short int len1 = strlen(path1);
    unsigned short int len2 = strlen(path2);
    char* newpath = (char*) malloc(len1 + len2 + 2);
    strcpy(newpath, path1);
    if(path1[len1-1] != PathSep){
        char* sep = malloc(1);
        sep[0] = PathSep;
        strcat(newpath, sep);
        free(sep); // 1 byte
    }
    strcat(newpath, path2);
    return newpath;
}
/* Do path secure for use in shell. USE WITH free()!*/
char* Pathesc(const char* path){
    unsigned int j = 0;
    unsigned int len = strlen(path);
    char* result = (char*) malloc(len*2+2);
    char c;
    for(unsigned int i=0; i < len; i++){
        c = path[i];
        if (c == '\\' || c == '\'' || c == '*' || c == '?' || c == '[' || c == ']' || c == '|' || c == '<' || c == '>' || c == ';' || c == '"' || c == ' '){
            result[j++] = '\\';
        }
        result[j++] = c;
    }
    return result;
}




#endif