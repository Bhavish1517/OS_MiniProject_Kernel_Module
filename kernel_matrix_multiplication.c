//kernal module code
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int matrix_multiply_init(void) {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[3][3];
    int i, j, k;

    printk(KERN_INFO "Performing 3x3 matrix multiplication...\n");

    //Performing matrix multiplication
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j)
        {
            C[i][j] = 0;
            for(k = 0; k < 3; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    //Logging the result
    printk(KERN_INFO "Resultant Matrix C:\n");
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            printk(KERN_INFO " C[%d][%d] : %d", i, j, C[i][j]);
        }
        printk(KERN_INFO "\n");
    }

    return 0;
}

static void matrix_multiply_exit(void)
{
    printk(KERN_INFO "Exiting matrix_multiply module\n");
}

module_init(matrix_multiply_init);
module_exit(matrix_multiply_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Kernel module for performing 3x3 matrix multiplication");
