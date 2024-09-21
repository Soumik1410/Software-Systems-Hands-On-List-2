/*
============================================================================
Name : 19.c
Author : Soumik Pal
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int result = mknod("fifoq19d", S_IFIFO|S_IRWXU, 0);
	if(result == -1)
	{
		perror("Error during mknod call");
		exit(0);
	}
	result = mkfifo("fifoq19e", S_IRWXU);
	if(result == -1)
	{
		perror("Error during mkfifo call");
		exit(0);
	}
}
/*
===========================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ mknod fifoq19a p
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ls -l fifoq19a
prw-rw-r-- 1 soumik soumik 0 Sep 19 02:11 fifoq19a
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ mkfifo fifoq19b
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ls -l fifoq19b
prw-rw-r-- 1 soumik soumik 0 Sep 19 02:12 fifoq19b

*/

//soumik@soumik-VirtualBox:~/SS_HandsOnList2$ strace -rt mknod fifoq19cmknod p
//02:13:52 (+     0.000000) execve("/usr/bin/mknod", ["mknod", "fifoq19cmknod", "p"], 0x7ffd7cc18858 /* 48 vars */) = 0
/*02:13:52 (+     0.000745) brk(NULL)     = 0x587ad2a6a000
02:13:52 (+     0.000106) mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7386e61df000
02:13:52 (+     0.000052) access("/etc/ld.so.preload", R_OK) = -1 ENOENT (No such file or directory)
02:13:52 (+     0.000134) openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
02:13:52 (+     0.000045) fstat(3, {st_mode=S_IFREG|0644, st_size=55975, ...}) = 0
02:13:52 (+     0.000050) mmap(NULL, 55975, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7386e61d1000
02:13:52 (+     0.000039) close(3)      = 0
02:13:52 (+     0.000037) openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
02:13:52 (+     0.000038) read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
02:13:52 (+     0.000035) fstat(3, {st_mode=S_IFREG|0644, st_size=174472, ...}) = 0
02:13:52 (+     0.000033) mmap(NULL, 181960, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7386e61a4000
02:13:52 (+     0.000036) mmap(0x7386e61aa000, 118784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7386e61aa000
02:13:52 (+     0.000048) mmap(0x7386e61c7000, 24576, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x23000) = 0x7386e61c7000
02:13:52 (+     0.000039) mmap(0x7386e61cd000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7386e61cd000
02:13:52 (+     0.000203) mmap(0x7386e61cf000, 5832, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7386e61cf000
02:13:52 (+     0.000085) close(3)      = 0
02:13:52 (+     0.000057) openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
02:13:52 (+     0.000064) read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
02:13:52 (+     0.000054) pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
02:13:52 (+     0.000053) fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
02:13:52 (+     0.000054) pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
02:13:52 (+     0.000052) mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7386e5e00000
02:13:52 (+     0.000072) mmap(0x7386e5e28000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7386e5e28000
02:13:52 (+     0.000069) mmap(0x7386e5fb0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7386e5fb0000
02:13:52 (+     0.000046) mmap(0x7386e5fff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7386e5fff000
02:13:52 (+     0.000058) mmap(0x7386e6005000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7386e6005000
02:13:52 (+     0.000065) close(3)      = 0
02:13:52 (+     0.000047) openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
02:13:52 (+     0.000130) read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
02:13:52 (+     0.000052) fstat(3, {st_mode=S_IFREG|0644, st_size=625344, ...}) = 0
02:13:52 (+     0.000041) mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7386e610a000
02:13:52 (+     0.000044) mmap(0x7386e610c000, 450560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7386e610c000
02:13:52 (+     0.000050) mmap(0x7386e617a000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x70000) = 0x7386e617a000
02:13:52 (+     0.000040) mmap(0x7386e61a2000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7386e61a2000
02:13:52 (+     0.000054) close(3)      = 0
02:13:52 (+     0.000050) mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7386e6107000
02:13:52 (+     0.000043) arch_prctl(ARCH_SET_FS, 0x7386e6107800) = 0
02:13:52 (+     0.000032) set_tid_address(0x7386e6107ad0) = 3856
02:13:52 (+     0.000030) set_robust_list(0x7386e6107ae0, 24) = 0
02:13:52 (+     0.000031) rseq(0x7386e6108120, 0x20, 0, 0x53053053) = 0
02:13:52 (+     0.000173) mprotect(0x7386e5fff000, 16384, PROT_READ) = 0
02:13:52 (+     0.000064) mprotect(0x7386e61a2000, 4096, PROT_READ) = 0
02:13:52 (+     0.000109) mprotect(0x7386e61cd000, 4096, PROT_READ) = 0
02:13:52 (+     0.000075) mprotect(0x587ad1a3d000, 4096, PROT_READ) = 0
02:13:52 (+     0.000049) mprotect(0x7386e6217000, 8192, PROT_READ) = 0
02:13:52 (+     0.000085) prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
02:13:52 (+     0.000055) munmap(0x7386e61d1000, 55975) = 0
02:13:52 (+     0.000087) statfs("/sys/fs/selinux", 0x7ffcc070fb90) = -1 ENOENT (No such file or directory)
02:13:52 (+     0.000057) statfs("/selinux", 0x7ffcc070fb90) = -1 ENOENT (No such file or directory)
02:13:52 (+     0.000045) getrandom("\x0d\xdf\xca\x87\x02\x3e\x3f\x0d", 8, GRND_NONBLOCK) = 8
02:13:52 (+     0.000041) brk(NULL)     = 0x587ad2a6a000
02:13:52 (+     0.000033) brk(0x587ad2a8b000) = 0x587ad2a8b000
02:13:52 (+     0.000047) openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
02:13:52 (+     0.000054) fstat(3, {st_mode=S_IFREG|0444, st_size=0, ...}) = 0
02:13:52 (+     0.000030) read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 393
02:13:52 (+     0.000066) read(3, "", 1024) = 0
02:13:52 (+     0.000031) close(3)      = 0
02:13:52 (+     0.000033) access("/etc/selinux/config", F_OK) = -1 ENOENT (No such file or directory)
02:13:52 (+     0.000091) openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
02:13:52 (+     0.000058) fstat(3, {st_mode=S_IFREG|0644, st_size=5719296, ...}) = 0
02:13:52 (+     0.000037) mmap(NULL, 5719296, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7386e5800000
02:13:52 (+     0.000076) close(3)      = 0
02:13:52 (+     0.000281) mknodat(AT_FDCWD, "fifoq19cmknod", S_IFIFO|0666) = 0
02:13:52 (+     0.000344) close(1)      = 0
02:13:52 (+     0.000058) close(2)      = 0
02:13:52 (+     0.000092) exit_group(0) = ?
02:13:52 (+     0.000502) +++ exited with 0 +++


*/

//soumik@soumik-VirtualBox:~/SS_HandsOnList2$ strace -rt mkfifo fifoq19cmkfifo
//02:16:47 (+     0.000000) execve("/usr/bin/mkfifo", ["mkfifo", "fifoq19cmkfifo"], 0x7ffee72113f0 /* 48 vars */) = 0
/*02:16:47 (+     0.000687) brk(NULL)     = 0x63edf1413000
02:16:47 (+     0.000163) mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7d36f6e0d000
02:16:47 (+     0.000120) access("/etc/ld.so.preload", R_OK) = -1 ENOENT (No such file or directory)
02:16:47 (+     0.000169) openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
02:16:47 (+     0.000081) fstat(3, {st_mode=S_IFREG|0644, st_size=55975, ...}) = 0
02:16:47 (+     0.000264) mmap(NULL, 55975, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7d36f6dff000
02:16:47 (+     0.000122) close(3)      = 0
02:16:47 (+     0.000101) openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
02:16:47 (+     0.000080) read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
02:16:47 (+     0.000065) fstat(3, {st_mode=S_IFREG|0644, st_size=174472, ...}) = 0
02:16:47 (+     0.000060) mmap(NULL, 181960, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7d36f6dd2000
02:16:47 (+     0.000068) mmap(0x7d36f6dd8000, 118784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7d36f6dd8000
02:16:47 (+     0.000085) mmap(0x7d36f6df5000, 24576, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x23000) = 0x7d36f6df5000
02:16:47 (+     0.000069) mmap(0x7d36f6dfb000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7d36f6dfb000
02:16:47 (+     0.000080) mmap(0x7d36f6dfd000, 5832, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7d36f6dfd000
02:16:47 (+     0.000155) close(3)      = 0
02:16:47 (+     0.000081) openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
02:16:47 (+     0.000087) read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
02:16:47 (+     0.000055) pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
02:16:47 (+     0.000052) fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
02:16:47 (+     0.000055) pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
02:16:47 (+     0.000050) mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7d36f6a00000
02:16:47 (+     0.000065) mmap(0x7d36f6a28000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7d36f6a28000
02:16:47 (+     0.000062) mmap(0x7d36f6bb0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7d36f6bb0000
02:16:47 (+     0.000058) mmap(0x7d36f6bff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7d36f6bff000
02:16:47 (+     0.000069) mmap(0x7d36f6c05000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7d36f6c05000
02:16:47 (+     0.000074) close(3)      = 0
02:16:47 (+     0.000057) openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
02:16:47 (+     0.000061) read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
02:16:47 (+     0.000119) fstat(3, {st_mode=S_IFREG|0644, st_size=625344, ...}) = 0
02:16:47 (+     0.000195) mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7d36f6d38000
02:16:47 (+     0.000072) mmap(0x7d36f6d3a000, 450560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7d36f6d3a000
02:16:47 (+     0.000094) mmap(0x7d36f6da8000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x70000) = 0x7d36f6da8000
02:16:47 (+     0.000059) mmap(0x7d36f6dd0000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7d36f6dd0000
02:16:47 (+     0.000070) close(3)      = 0
02:16:47 (+     0.000057) mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7d36f6d35000
02:16:47 (+     0.000050) arch_prctl(ARCH_SET_FS, 0x7d36f6d35800) = 0
02:16:47 (+     0.000045) set_tid_address(0x7d36f6d35ad0) = 3916
02:16:47 (+     0.000043) set_robust_list(0x7d36f6d35ae0, 24) = 0
02:16:47 (+     0.000043) rseq(0x7d36f6d36120, 0x20, 0, 0x53053053) = 0
02:16:47 (+     0.000112) mprotect(0x7d36f6bff000, 16384, PROT_READ) = 0
02:16:47 (+     0.000061) mprotect(0x7d36f6dd0000, 4096, PROT_READ) = 0
02:16:47 (+     0.000106) mprotect(0x7d36f6dfb000, 4096, PROT_READ) = 0
02:16:47 (+     0.000070) mprotect(0x63edf1215000, 4096, PROT_READ) = 0
02:16:47 (+     0.000058) mprotect(0x7d36f6e45000, 8192, PROT_READ) = 0
02:16:47 (+     0.000073) prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
02:16:47 (+     0.000064) munmap(0x7d36f6dff000, 55975) = 0
02:16:47 (+     0.000080) statfs("/sys/fs/selinux", 0x7ffd54238c20) = -1 ENOENT (No such file or directory)
02:16:47 (+     0.000069) statfs("/selinux", 0x7ffd54238c20) = -1 ENOENT (No such file or directory)
02:16:47 (+     0.000059) getrandom("\xc7\x9a\x0b\x15\x4a\xc3\x75\x20", 8, GRND_NONBLOCK) = 8
02:16:47 (+     0.000055) brk(NULL)     = 0x63edf1413000
02:16:47 (+     0.000048) brk(0x63edf1434000) = 0x63edf1434000
02:16:47 (+     0.000059) openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
02:16:47 (+     0.000067) fstat(3, {st_mode=S_IFREG|0444, st_size=0, ...}) = 0
02:16:47 (+     0.000055) read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 393
02:16:47 (+     0.000086) read(3, "", 1024) = 0
02:16:47 (+     0.000210) close(3)      = 0
02:16:47 (+     0.000110) access("/etc/selinux/config", F_OK) = -1 ENOENT (No such file or directory)
02:16:47 (+     0.000527) openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
02:16:47 (+     0.000688) fstat(3, {st_mode=S_IFREG|0644, st_size=5719296, ...}) = 0
02:16:47 (+     0.000127) mmap(NULL, 5719296, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7d36f6400000
02:16:47 (+     0.000390) close(3)      = 0
02:16:47 (+     0.000217) mknodat(AT_FDCWD, "fifoq19cmkfifo", S_IFIFO|0666) = 0
02:16:47 (+     0.000232) close(1)      = 0
02:16:47 (+     0.000060) close(2)      = 0
02:16:47 (+     0.000112) exit_group(0) = ?
02:16:47 (+     0.000444) +++ exited with 0 +++


soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 19.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ls -l fifoq19d fifoq19e 
prwx------ 1 soumik soumik 0 Sep 19 02:21 fifoq19d
prwx------ 1 soumik soumik 0 Sep 19 02:21 fifoq19e

==========================================================================
*/
