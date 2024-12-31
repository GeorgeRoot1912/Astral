#ifndef ASTRAL_OS_H_
#define ASTRAL_OS_H_ 1
/*w - Win32
W - Win64
m - Mac OS
f - FreeBSD
l - Linux
n - NetBSD
o - OpenBSD
s - Solaris
a - Android
i - IOS
u - Unix(UnixLike)
e - unknown.*/
char getOS(){
    #ifdef _WIN32
    return 'w';
    #endif 
    #ifdef _WIN64
    return 'W';
    #endif
    #ifdef __APPLE__
    return 'm';
    #endif
    #ifdef __linux
    return 'l';
    #endif
    #ifdef _FREEBSD_
    return 'f';
    #endif
    #ifdef __NETBSD__
    return 'n';
    #endif
    #ifdef __OPENBSD__
    return 'o';
    #endif
    #ifdef __sun
    return 's';
    #endif
    #ifdef __ANDROID__
    return 'a'
    #endif
    #ifdef __IOS__
    return 'i'
    #endif
    #ifdef unix
    return 'u';
    #endif
    return 'e';
}

#endif