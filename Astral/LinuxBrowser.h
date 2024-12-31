#ifndef ASTRAL_BROWSER_LINUX_H_
#define ASTRAL_BROWSER_LINUX_H_ 1
#include <stdlib.h>
#include <string.h>
char* BrowserCommand = "None";
#define MAX_URL 256
#define SetBrowser(__Browser_Command) BrowserCommand = __Browser_Command
char* GetBrowser(){
    if(system("google-chrome --version") == 0){
        return "google-chrome";
    };   
    if(system("firefox --version") == 0){
        return "firefox";
    };      
    if(system("safari --version") == 0){
        return "safari";
    }
    if(system("microsoft-edge --version") == 0){
        return "microsoft-edge";
    }    
    if(system("opera --version") == 0){
        return "opera";
    }
    if(system("yandex-browser --version") == 0){
        return "yandex-browser ";
    }     
    if(system("waterfox --version") == 0){
        return "waterfox";
    };  
    if(system("brave-browser --version") == 0){
        return "brave-browser";
    };      
    if(system("chromium --version") == 0){
        return "chromium";
    };     
    if(system("vivaldi --version") == 0){
        return "vivaldi";
    };      
    if(system("tor --version") == 0){
        return "tor";
    };       
    return "None";
}
#define Init_Browser SetBrowser(GetBrowser())
char NewTab(const char* url){
    if (strcmp(BrowserCommand, "None") == 0){
        return -1;
    }
    char opener[MAX_URL];
    strcpy(opener,BrowserCommand);
    strcat(opener, " --new-tab ");
    strcat(opener, url);
    system(opener);
    return 0;
}
char NewDef(){
    if(strcmp(BrowserCommand,"None") == 0){
        return -1;
    }
    system(BrowserCommand);
    return 0;
}
char NewWindow(const char* url){
    char opener[MAX_URL];
    // None browser
    if (strcmp(BrowserCommand, "None") == 0){
        return -1;
    }
    // Safari
    else if(strcmp(BrowserCommand,"safari") == 0){
        strcpy(opener, "open -a Safari ");
        strcat(opener,url);
        system(opener);
        return 0;        
    }
    // other
    strcpy(opener,BrowserCommand);
    strcat(opener, " --new-window ");
    strcat(opener, url);
    system(opener);
    return 0;
}

char NewPrivate(const char* url){
    if (strcmp(BrowserCommand,"None") == 0){
        return -1;
    }
    char opener[MAX_URL];
    if (strcmp(BrowserCommand,"google-chrome") == 0){
        strcpy(opener, "google-chrome --incognito ");
        strcat(opener,url);
        system(opener);
        return 0;          
    }
    if (strcmp(BrowserCommand,"msedge") == 0){
        strcpy(opener, "msedge -private ");
        strcat(opener,url);
        system(opener);
        return 0;          
    }
    if (strcmp(BrowserCommand,"safari") == 0){
        strcpy(opener, "open -a Safari --private ");
        strcat(opener,url);
        system(opener);
        return 0;          
    }    
    if (strcmp(BrowserCommand,"opera") == 0){
        strcpy(opener, "opera --private ");
        strcat(opener,url);
        system(opener);
        return 0;          
    }        
    strcpy(opener,BrowserCommand);
    strcat(opener, " --private-window ");
    strcat(opener, url);
    system(opener);
    return 0;
}

#endif