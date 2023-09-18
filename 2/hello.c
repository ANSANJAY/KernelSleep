#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");


static int __init test_hello_init(void)
{
    unsigned long retval;
    pr_info("starting 30 second sleep\n");
    retval = msleep_interruptible(30*1000L);
    pr_info("Ending 30 second sleep:%lu\n", retval);
    return -1;
}

static void __exit test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);
