/* 
 ********************************************************************************

 Name         : 2.c
 Author       : Pankaj Deopa
 Description  :  Write a simple program to execute in an infinite loop at the background. 
                Go to /proc directory and identify all the process related information in 
		the corresponding proc directory.
 Date         : 26 Aug, 2025

 ******************************************************************************
*/

#include <stdio.h>
#include <unistd.h>

int main() {

	printf("Process Running: %d\n", getpid());
	
	for (;;);
	
	return 0;

}

/*	
 ********************OUTPUT**************************		  
  piradians@3piradians:~/Documents/system_programming/solutions$ cc 2.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
  Process Running: 9315

  piradians@3piradians:~$ cd /proc/9315
  piradians@3piradians:/proc/9315$ cat status
  Name:	a.out
  Umask:	0002
  State:	R (running)
  Tgid:	9315
  Ngid:	0
  Pid:	9315
  PPid:	9198
  TracerPid:	0
  Uid:	1000	1000	1000	1000
  Gid:	1000	1000	1000	1000
  FDSize:	256
  Groups:	4 24 27 30 46 101 1000
  NStgid:	9315
  NSpid:	9315
  NSpgid:	9315
  NSsid:	9198
  Kthread:	0
  VmPeak:	    2252 kB
  VmSize:	    2252 kB
  VmLck:	       0 kB
  VmPin:	       0 kB
  VmHWM:	    1280 kB
  VmRSS:	    1280 kB
  RssAnon:	       0 kB
  RssFile:	    1280 kB
  RssShmem:	       0 kB
  VmData:	     208 kB
  VmStk:	     132 kB
  VmExe:	       4 kB
  VmLib:	    1800 kB
  VmPTE:	      44 kB
  VmSwap:	       0 kB
  HugetlbPages:	       0 kB
  CoreDumping:	0
  THP_enabled:	1
  untag_mask:	0xffffffffffffff
  Threads:	1
  SigQ:	0/7356
  SigPnd:	0000000000000000
  ShdPnd:	0000000000000000
  SigBlk:	0000000000000000
  SigIgn:	0000000000000000
  SigCgt:	0000000000000000
  CapInh:	0000000000000000
  CapPrm:	0000000000000000
  CapEff:	0000000000000000
  CapBnd:	000001ffffffffff
  CapAmb:	0000000000000000
  NoNewPrivs:	0
  Seccomp:	0
  Seccomp_filters:	0
  Speculation_Store_Bypass:	thread vulnerable
  SpeculationIndirectBranch:	unknown
  Cpus_allowed:	f
  Cpus_allowed_list:	0-3
  Mems_allowed:	00000000,00000001
  Mems_allowed_list:	0
  voluntary_ctxt_switches:	0
  nonvoluntary_ctxt_switches:	1689

 * */
