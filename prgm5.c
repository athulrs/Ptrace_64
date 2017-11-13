#include <sys/ptrace.h>
#include <signal.h>
#include <linux/user.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int i = 0, status = 0, pid ,data=0;
    struct user_regs_struct uregs;
    if ((pid=fork())==0) 
    {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execl("/home/C4", "C4", 0);
        printf("execl error...\n");
    } 
    else 
    {
        wait(&status);
        ptrace(PTRACE_CONT, pid, 0, 0);
        sleep(1);
        kill(pid, SIGINT);
        wait(&status); 
        data = ptrace(PTRACE_PEEKDATA, pid, addr, 0);
        printf("data = %d\n", data);
        data = 245;
        ptrace(PTRACE_POKEDATA, pid, addr, data);
        ptrace(PTRACE_CONT, pid, 0, 0); 
        wait(&status);
    }
}
