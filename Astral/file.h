#ifndef ASTRAL_FileWork_H_
#define ASTRAL_FileWork_H_ 1
// Astral by GeorgeRoot1912 GNU OPEN SOURCE! FIND IN GITHUB: https://github.com/GeorgeRoot1912/Astral.git
// GNU OPEN SORCE PROJECT. READ LICENSE.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define FILErename(path,new_name) rename(path,new_name)
#define FILEremove(path) remove(path)
#define FILEgetSize(path) FILElen(path)
/* Write text in file. First argument - path to file, second argument - text.*/
int FILEwrite(const char *filepath, const char *text)
{
    FILE *fptr;
    fptr = fopen(filepath, "w");
    fwrite(text, 1, strlen(text), fptr);
    return fclose(fptr);
}
/* Add text in file. First argument - path to file, second argument - text.*/
int FILEadd(const char *filepath, const char *text)
{
    if(open(filepath,1) == -1){ return -1;}
    FILE *fptr;
    fptr = fopen(filepath, "a");
    fwrite(text, 1, strlen(text), fptr);
    return fclose(fptr);
}
/* Create file. If file exist - return -1. First argument - path to file*/
int FILEcreat(const char* path){
    if (open(path,1) != -1){
        return -1;
    }    
    FILE *fptr;
    fptr = fopen(path, "w");
    return fclose(fptr); 
}
/* Clear all data in file. First argument - path to file*/
int FILEclear(const char* path){
    if (open(path,1) == -1){
        return -1;
    }    
    FILE *fptr;
    fptr = fopen(path, "w");
    fputc(0,fptr);
    return fclose(fptr);   
}
/* Print all in file. First argument - path to file.*/
int FILEprint(const char* path)
{
    if (open(path,0) == -1){
        return -1;
    }
    FILE *fptr;
    fptr = fopen(path, "r");
    while (1)
    {
        int a = getc(fptr);
        if (a == EOF)
        {
            break;
        }
        putchar(a);
    }
    return fclose(fptr);
}
/*
Check length file. First argument - path to file. Return unsigned long.*/
unsigned long FILElen(const char* path)
{
    if (open(path,0) == -1){
        return 0;
    }   
    long len = 0;
    FILE *fptr;
    fptr = fopen(path, "r");
    while (getc(fptr) != EOF)
    {
        len++;
    }
    fclose(fptr);
    return len;
}
/*
 Reads N count symbols and returns a pointer to a memory address on the heap.
 USE WITH free(); This function allocates memory through the malloc() method.
 First argument - path to file, second argument - count symbols for read.
*/
char* FILEread(const char* path, unsigned long int len){
    char* str = (char*) malloc(len);
    if (open(path,0) == -1){
        return "/NOTFIND/";
    }
    FILE *fptr;
    fptr = fopen(path, "r");
    unsigned long int n = 0;
    while (n < len)
    {
        int a = getc(fptr);
        if (a == EOF)
        {
            break;
        }
        str[n] = a;
        n++;
    }
    fclose(fptr);
    return str;
}
/*Automatically reads the number of characters in a file and returns a pointer to a memory address on the heap.
 USE WITH free(); This function allocates memory through the malloc() method.
  First argument - path to file.*/
char* FILEautoRead(const char* path){
    char* str = (char*) malloc(FILElen(path));
    if (open(path,0) == -1){
        return "/NOTFIND/";
    }
    FILE *fptr;
    fptr = fopen(path, "r");
    unsigned long int n = 0;
    while (1)
    {
        int a = getc(fptr);
        if (a == EOF)
        {
            break;
        }
        str[n] = a;
        n++;
    }
    fclose(fptr);
    return str;
}
#endif
