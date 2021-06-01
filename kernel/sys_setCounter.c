// SPDX-License-Identifier: GPL-2.0
/**
 * Syscall that simply returns the long input argument counter
 */
#include <linux/syscalls.h>
#include <vdso/sys_setCounter.h>

long _vcounter
__attribute__((section(".vvar__vcounter"), aligned(16))) __visible;

SYSCALL_DEFINE1(setCounter, long, counter)
{
	_vcounter = counter;
	return _vcounter;
}