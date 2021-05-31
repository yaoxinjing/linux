// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright 2006 Andi Kleen, SUSE Labs.
 *
 * Fast user context implementation of getcpu()
 */

#include <linux/kernel.h>

#include <linux/time.h>

extern long vvar__vcounter__attribute__((visibility("hidden")));

notrace long __vdso_getcounter(long counter)
{

	return counter + vvar__vcounter;
}

long getcounter(long counter)
	__attribute__((weak, alias("__vdso_getcounter")));
