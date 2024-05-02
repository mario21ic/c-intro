#include <stdio.h>
#include <sys/types.h>
#include <sys/sysctl.h>

int printSysctlStrValue(const char *label, const char *sysctl_name) {
  char getStr[256];
  size_t getStrSize = sizeof(getStr);

  if (sysctlbyname(sysctl_name, &getStr, &getStrSize, NULL, 0) == -1) {
    perror("sysctlbyname");
    return 1;
  }

  // printf("%s %s\n", sysctl_name, getStr);
  printf("%s: %s\n", label, getStr);
  return 0;
}


int getSysctlStr(const char *sysctl_name, char *output) {
  size_t outputSize = sizeof(output);
  if (sysctlbyname(sysctl_name, output, &outputSize, NULL, 0) == -1) {
    perror("sysctlbyname");
    return 1;
  }

  return 0;
}


int getSysctlInt(const char *sysctl_name) {
  int value;
  size_t valueSize = sizeof(value);

  if (sysctlbyname(sysctl_name, &value, &valueSize, NULL, 0) == -1) {
    perror("sysctlbyname");
    return 1;
  }

  return value;
}

uint64_t getMem(int *error) {
  uint64_t mem;
  size_t memSize = sizeof(mem);

  if (sysctlbyname("hw.memsize", &mem, &memSize, NULL, 0) == -1) {
    perror("sysctlbyname");
    *error = 1;
    return 0;
  }

  *error = 0;
  return mem / 1024.0 / 1024.0 / 1024.0;
}

int main() {
  #ifdef _WIN64
  printf("Hola mundo desde windows\n");
  #endif


  #ifdef __linux__
  printf("Hola mundo desde linux\n");
  #endif


  #ifdef __APPLE__

  printf("Hola mundo desde macOS\n");

  // char osRelease[256];
  // size_t osReleaseSize = sizeof(osRelease);
  // const char *sysctl_name01 = "kern.osrelease";
  // if (sysctlbyname(sysctl_name01, &osRelease, &osReleaseSize, NULL, 0) == -1) {
  //   perror("sysctlbyname");
  //   return 1;
  // }
  // printf("Release %s\n", osRelease);

  char osType[256];
  if (getSysctlStr("kern.ostype", osType) != 0) {
    printf("Error getting osrelease\n");
    return 1;
  }
  printf("OS: %s\n", osType);
  
  printSysctlStrValue("Release", "kern.osrelease");
  printSysctlStrValue("Version", "kern.osversion");
  
  int osrevision = getSysctlInt("kern.osrevision");
  printf("Revision: %d\n", osrevision);
  
  printSysctlStrValue("Hostname", "kern.hostname");
  
  int ncpu = getSysctlInt("hw.ncpu");
  printf("CPUs: %d\n", ncpu);

  int error;
  uint64_t myMem = getMem(&error);
  if (error) {
    printf("Error obteniendo la información de la memoria\n");
    return 1;
  }
  printf("Total Physical Memory: %lluGB\n", myMem);

  #endif


  #ifdef __unix__
  printf("Hola mundo desde UNIX\n");

  char hostname[256];
  size_t hostnameSize = sizeof(hostname);
  const char *sysctl_name = "kern.hostname";
  if (sysctlbyname(sysctl_name, &hostname, &hostnameSize, NULL, 0) == -1) {
	  perror("sysctlbyname");
	  return 1;
  }
  printf("Hostname %s\n", hostname);

  char osType[256];
  size_t osTypeSize = sizeof(osType);
  const char *sysctl_name0 = "kern.ostype";
  if (sysctlbyname(sysctl_name0, &osType, &osTypeSize, NULL, 0) == -1) {
	  perror("sysctlbyname");
	  return 1;
  }
  printf("OS %s\n", osType);

  char osVersion[256];
  size_t osVersionSize = sizeof(osVersion);
  const char *sysctl_name1 = "kern.osrelease";
  if (sysctlbyname(sysctl_name1, &osVersion, &osVersionSize, NULL, 0) == -1) {
	  perror("sysctlbyname");
	  return 1;
  }
  printf("Release %s\n", osVersion);

  int ncpu;
  size_t ncpuSize = sizeof(ncpu);
  const char *sysctl_name2 = "hw.ncpu";
  if (sysctlbyname(sysctl_name2, &ncpu, &ncpuSize, NULL, 0) == -1) {
	  perror("sysctlbyname");
	  return 1;
  }
  printf("Number of CPUs %d\n", ncpu);

  char arch[256];
  size_t archSize = sizeof(arch);
  const char *sysctl_name3 = "hw.machine_arch";
  if (sysctlbyname(sysctl_name3, &arch, &archSize, NULL, 0) == -1) {
	  perror("sysctlbyname");
	  return 1;
  }
  printf("Processor Arch %s\n", arch);

  unsigned long realmem;
  size_t realmemSize = sizeof(realmem);
  const char *sysctl_name4 = "hw.realmem";
  if (sysctlbyname(sysctl_name4, &realmem, &realmemSize, NULL, 0) == -1) {
	  perror("sysctlbyname");
	  return 1;
  }
  double gigabytes = realmem / 1024.0 / 1024.0 / 1024.0;
  printf("Total Real Memory: %.2f GB\n", gigabytes);

  unsigned long physmem;
  size_t physmemSize = sizeof(physmem);
  const char *sysctl_name5 = "hw.physmem";
  if (sysctlbyname(sysctl_name5, &physmem, &physmemSize, NULL, 0) == -1) {
	  perror("sysctlbyname");
	  return 1;
  }
  double physgigabytes = physmem / 1024.0 / 1024.0 / 1024.0;
  printf("Total Physical Memry: %.2f GB\n", physgigabytes);

  #endif


  return 0;
}
