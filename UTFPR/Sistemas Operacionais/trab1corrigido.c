/* Determina o status de exit de um processo filho - TEM ERRO - FALTA ACERTAR!! */
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
   pid_t pid,childpid;
   int status;

   pid = fork();
   if (pid == 0)
   {
     printf("processo B\n" );
     childpid = wait(&status);
     pid = fork();
     if (pid == 0)
     {
       printf("Processo C\n");
        exit(5); /* child1 finishes normally */
     }
     else if (pid > 0)
     {
      childpid = wait(&status);
      if (childpid == -1)
          perror("Failed to wait for child");
      else if (WIFEXITED(status))
          printf("exit status = %d - processo C, pid = %d , ppid = %d\n", WEXITSTATUS(status), getpid(), getppid());
     }
      exit(3); /* child1 finishes normally */
     }
     else if (pid > 0)
     {
      childpid = wait(&status);
      if (childpid == -1)
          perror("Failed to wait for child");
      else if (WIFEXITED(status))
          printf("exit status = %d - processo B, pid = %d , ppid = %d\n", WEXITSTATUS(status), getpid(), getppid());


          pid = fork();
          if (pid == 0){
            printf("Processo D\n" );
             exit(1); /* child1 finishes normally */

          }
          else if (pid > 0){
           childpid = wait(&status);
           if (childpid == -1)
               perror("Failed to wait for child");
           else if (WIFEXITED(status))
               printf("exit status = %d - processo D, pid = %d , ppid = %d\n", WEXITSTATUS(status), getpid(), getppid());
          }

          pid = fork();
          if (pid == 0)
          {
            printf("processo E\n" );
            childpid = wait(&status);
            pid = fork();
            if (pid == 0)
            {
              printf("Processo F\n" );
              pid = fork();
              if (pid == 0)
              {
                printf("Processo G\n" );
                 exit(2); /* child1 finishes normally */
              }
              else if (pid > 0)
              {
               childpid = wait(&status);
               if (childpid == -1)
                   perror("Failed to wait for child");
               else if (WIFEXITED(status))
                   printf("exit status = %d - processo G, pid = %d , ppid = %d\n", WEXITSTATUS(status), getpid(), getppid());
              }
               exit(7); /* child1 finishes normally */
            }
            else if (pid > 0)
            {
             childpid = wait(&status);
             if (childpid == -1)
                 perror("Failed to wait for child");
             else if (WIFEXITED(status))
                 printf("exit status = %d - processo F, pid = %d , ppid = %d\n", WEXITSTATUS(status), getpid(), getppid());
            }
             exit(8); /* child1 finishes normally */
            }
            else if (pid > 0)
            {
             childpid = wait(&status);
             if (childpid == -1)
                 perror("Failed to wait for child");
             else if (WIFEXITED(status))
                 printf("exit status = %d - processo E, pid = %d , ppid = %d\n", WEXITSTATUS(status), getpid(), getppid());
     }
}

   return 0;
}
