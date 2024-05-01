#include <stdio.h>
#include <sys/types.h>
#include <sys/sysctl.h>

int main() {
  #ifdef _WIN64
  printf("Hola mundo desde windows\n");
  #endif

  #ifdef __linux__
  printf("Hola mundo desde linux\n");
  #endif

  #ifdef __APPLE__
  printf("Hola mundo desde macOS\n");

  char osRelease[256];
  size_t osReleaseSize = sizeof(osRelease);
  const char *sysctl_name01 = "kern.osrelease";
  if (sysctlbyname(sysctl_name01, &osRelease, &osReleaseSize, NULL, 0) == -1) {
	  perror("sysctlbyname");
	  return 1;
  }
  printf("Release %s\n", osRelease);
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
