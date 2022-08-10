#include <linux/init.h>
#include <linux/module.h>

static int number = 0;
static char *word = "0000";

MODULE_LICENSE("GPL");

MODULE_AUTHOR("rob");
MODULE_DESCRIPTION("lab module");

module_param(number, int, 0);
MODULE_PARM_DESC(number, "A integer number");

module_param(word, charp, 0000);
MODULE_PARM_DESC(word, "A string");

int my_init_module(void) {
  printk("Init lab module number: %d, word: %s\n",
                                              number, word);
  return 0;
}

void my_cleanup_module(void) { printk("Cleanup lab module\n"); }

module_init(my_init_module);
module_exit(my_cleanup_module);

