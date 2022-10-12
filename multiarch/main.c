#include <unistd.h>
#include <stdio.h>
#include <sys/utsname.h>

#define BUFSIZE 128

#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif
#endif

const char *get_platform_name() {
    return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
}

int main() {
    const char msg[] = "Hello World!\n";
    write(0, msg, sizeof(msg));
    
    struct utsname name;
    uname(&name);
    printf("Binary: %s\n", name.machine);

    char *cmd = "arch";    
    char buf[BUFSIZE];
    FILE *fp;
    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return -1;
    }
    while (fgets(buf, BUFSIZE, fp) != NULL) {
        printf("ARCH: %s", buf);
    }
    if (pclose(fp)) {
        printf("Command not found or exited with error status\n");
        return -1;
    }
    
    printf("OS: %s\n", get_platform_name());

    return 0;
}
