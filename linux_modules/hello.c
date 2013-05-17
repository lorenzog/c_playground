/*
 * my first kernel module :)
 * lorenzo, 2006 11 29
 */
#define __KERNEL__
#define MODULE
#include <linux/kernel.h>
#include <linux/module.h>

int init_module() {
	// kernel printf to console
	printk(KERN_INFO "Hello, world!\n"); 
	return 0;
}

void cleanup_module() {
	printk("Goodbye, Lenin!\n");

	return;
}
