# **Forks in C**

This project's goal is developing on Forks (Multiprocesses). It opens some files as Child and Mother Processes and fills in a different way.

## There are some pictures about this project.
>![](./Img/1.bmp)![](./Img/2.bmp)

## Fork (Multiprocess)

```c
#include <unsitd.h>

pid_t fork(void);
```
The function above is used to create new(child) processes in a process. It does not take a parameter. It returns the "pid" number of the process which has just created.
Because it is used by the main process the return value could be assigned to the main processes variables. Main process and child process has the same variables but in different places in the memory. So it can be seen as same variable in name, but actualy they are completely different in memory. When that value is assigned to a variable in main process, the main process takes the child's pid and child process takes "0". Example:
```c
int main(void) {

  int pid = fork();
  
  if (pid == 0) {
    //child process
  }
  else {
    //main process
    wait(NULL);
  }
  return(0);
}
```
In this example child process enter in the first condition, while the main process waits in the second contion. When child process is done, the main process will also exit from condition. These things are the simple features of Multiprocessers.
