#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void matrix_multiply(int A[3][3], int B[3][3], int C[3][3])
{
    int i, j, k;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            C[i][j] = 0;
            for (k = 0; k < 3; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[3][3];

    pid_t pid = fork();

    if(pid < 0)                       //Fork failed
    {                       
        perror("fork");                  
        return 1;
    } 

    else if(pid == 0)                 //Child process
    {
        matrix_multiply(A, B, C);
        printf("Child Process Result:\n");

        //Print result matrix C
        printf("Resultant Matrix C:\n");
    	for (int i = 0; i < 3; ++i)
        {
           for (int j = 0; j < 3; ++j)
           {
            	printf("C[%d][%d] : %d ", i, j, C[i][j]);
            	printf("\n");
            }
            printf("\n");
            printf("\n");
        } 
        
    } 

    else                                //Parent process
    {
        wait(NULL);                    // Wait for the child process to finish
        printf("Parent Process Result:\n");
        // Print result matrix C
        printf("Matrix Multiplication Completed\n"); 
    }

    return 0;
}
