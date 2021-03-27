typedef char OS;
#define windows (OS) 1
#define mac (OS) 2

OS getOS() {
    #ifdef _WIN32
        return windows;
    #elif __APPLE__
        return mac;
    #else
        return 0;
        printf("YOUR OS IS NOT SUPPORTED\n")
    #endif
}

char *defaultExecutable(OS os) {
    char *name = "a";

    char *result = malloc(50);
    *result = 0;
    if(os == windows) {
        strcat(result, name);
        strcat(result, ".exe");
    }
    
    if(os == mac) {
        strcat(result, "./");
        strcat(result, name);
        strcat(result, ".out");
    }

    return result;
}

char *executable(OS os, char *name) {
    char *result = malloc(50);
    *result = 0;
    if(os == windows) {
        strcat(result, name);
        strcat(result, ".exe");
    }
    
    if(os == mac) {
        strcat(result, "./");
        strcat(result, name);
    }

    return result;
}

char *executableFile(OS os, char *name) {
    char *result = malloc(50);
    *result = 0;
    if(os == windows) {
        strcat(result, name);
        strcat(result, ".exe");
    }
    
    if(os == mac) {
        strcat(result, name);
    }

    return result;
}

char *rm(OS os) {
    return (os == windows) ? "del" : "rm";
}

char *defaultCompiler(OS os) {
    return (os == windows) ? "gcc" : "clang";
}