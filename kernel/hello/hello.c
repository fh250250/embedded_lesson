#include <linux/init.h>
#include <linux/module.h>


static int hello_init(void){
	printk("hello, kernel!\n");
	return 0;
}

static void hello_exit(void){
	printk("goodbye, kernel!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("alex <duanpengyuan@qq.com>");
MODULE_DESCRIPTION("Hello Module, U konw.");
