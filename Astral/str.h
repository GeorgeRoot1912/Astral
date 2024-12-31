#ifndef ASTRAL_STRINGS_H_
#define ASTRAL_STRINGS_H_ 1
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Astral by GeorgeRoot1912 GNU OPEN SOURCE! FIND IN GITHUB: https://github.com/GeorgeRoot1912/Astral.git
// GNU OPEN SORCE PROJECT. READ LICENSE.md
typedef char* str;
/* Return pointer to merged string. USE WITH free()! */
char* strmerge(const char* str1, const char* str2){
    char* res = (char*) malloc(strlen(str1) + strlen(str2));
    strcpy(res, str1); strcat(res, str2); 
    return res;
}
/* Replace char_from to char_to. Return char*. USE WITH free().*/
char* streplace(const char* str, char from, char to){
    register unsigned int len = strlen(str);
    char* res = (char*) malloc(len);
    strcpy(res, str);
    for(unsigned int i = 0; i < len; i++){
        if(str[i] == from){res[i] = to;}
    }
    return res;
}
/* Return upper string. USE WITH free()!*/
char* strupper(char* str){
    int len = strlen(str);
    char* res = (char*) malloc(len);
    memcpy(res, str, len);
    for(len; len > -2; len--){
        res[len] = toupper(res[len]);
    }
    return res;
}
/* Return downer string. USE WITH free()!*/
char* strdowner(char* str){
    int len = strlen(str);
    if(len == 0){ return "";}
    char* res = (char*) malloc(len);
    memcpy(res, str, len);
    for(len; len > -2; len--){
        res[len] = tolower(res[len]);
    }
    return res;
}
#endif