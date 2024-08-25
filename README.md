# OS_MiniProject_Kernel_Module
### Performs Matrix Multiplication
This project demonstrates the development of a kernel module for performing **Matrix Multiplication** within the Linux kernel space. 
The kernel module performs a 3x3 matrix multiplication operation and logs the result.

Additionally, this project includes a user-space program that performs matrix multiplication using processes to illustrate the interaction between user-space and kernel-space code.
The goal is to showcase interaction between user-space and kernel-space code.

## User-Space Code
The user-space code is a C program that multiplies two 3x3 matrices using child and parent processes. The child process performs the matrix multiplication, and the parent process waits for the child to complete and then reports the completion.

### Features
- Matrix multiplication performed in a child process.
- Results printed to the console.

  ## Kernel Module Code
  The kernel module code performs the same matrix multiplication as the user-space program but runs in kernel space. The results are logged using 'printk()' .

### Features
- Matrix multiplication performed in kernel space.
- Results logged to the kernel log.

## Requirements
- A Linux-based system or virtual machine with kernel headers installed.
- Tools such as gcc, make, and kernel headers for compiling the kernel module.
- Kernel Headers can be installed using the follwing command on Ubuntu :
   ```bash
   sudo apt-get install build-essential linux-headers-$(uname -r)

## SetUp
- Download or Clone the repository by using :
  ```bash
  git clone https://github.com/Bhavish1715/OS_MiniProject_Kernel_Module.git
- Next navigate to the project directory
  ```bash
  cd OS_MiniProject_Kernel_Module

### User-Space
For the User-Space code :
- First compile it : 
  ```bash
  gcc -o user_mat_mul user_mat_mul.c
- Then execute using : 
  ```bash
  ./user_mat_mul

For the Kernel Module : 
- STEP 1: Compile the kernel module code using : 
  ```bash
  make

- STEP 2: Load the kernel module using :
  ```bash
  sudo insmod kernel_matrix_multiplication.ko       #here kernel_matrix_multiply is the name of the c file containing kernel code

- STEP 3: Verify the module is loaded :
  ```bash
  lsmod | grep kernel_matrix_multiplication

- STEP 4: Check kernel logs for output :
  ```bash
  dmesg | tail   #Output will be visible as log messages

- STEP 5: Remove/ the Kernel Module :
  ```bash
  sudo rmmod matrix_multiplication 
