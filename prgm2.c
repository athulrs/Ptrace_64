#include <sys/ptrace.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int pid, status;
    if((pid = fork()) == 0) 
    {
        execl("/home/C1", "C1", 0);
        printf("exec failed...\n");
    }
    else 
    {
        sleep(1);
        kill(pid,SIGINT);
        wait(&status);
        if(WIFSTOPPED(status))
            printf("child has stopped...\n");
        sleep(3);
        ptrace(PTRACE_CONT, pid, 0, 0);
        wait(&status); 
    }
}