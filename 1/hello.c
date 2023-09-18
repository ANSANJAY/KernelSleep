#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");


static int __init test_hello_init(void)
{
    pr_info("starting 1 minute sleep\n");
    msleep(60*1000L);
    pr_info("Ending 1 minute sleep\n");
    return -1;
}

static void __exit test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);
