#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

// ls_aggr_div = ['SBGB.MOEX', 'RUSB.MOEX', 'VTBX.MOEX', 'VCIT.US', 'VCLT.US', 'VOO.US', 'VB.US', 'PGJ.US', 'VGK.US', 'INDY.US', 'GLDM.US', 'VNQ.US', 'VNQI.US']
// weights_aggr_div = [   .03,         .03,         .35,       .02,       .03,      .06,     .10,      .13,      .04,       .03,       .12,      .03,

/*
** Module Init function
*/
static int __init hello_init(void)
{
    printk(KERN_INFO "Welcome to EmbeTronicX\n");
    printk(KERN_INFO "This is the Simple Module\n");
    printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
    return 0;
}
/*
** Module Exit function
*/
static void __exit hello_exit(void)
{
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EmbeTronicX <embetronicx@gmail.com>");
MODULE_DESCRIPTION("A simple hello world driver");
MODULE_VERSION("2:1.0");