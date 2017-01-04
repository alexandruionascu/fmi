// Basic pipe example illustrating a pipe between two processes.
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  pid_t pid1, pid2;
  int pipefd[2];
  // The two commands we'll execute.  In this simple example, we will pipe
  // the output of `ls` into `wc`, and count the number of lines present.
  char *argv1[] = {"ls", "-l", "-h", NULL};
  char *argv2[] = {"wc", "-l", NULL};
  // Create a pipe.
  pipe(pipefd);
  // Create our first process.
  pid1 = fork();
  if (pid1 == 0) {
    // Hook stdout up to the write end of the pipe and close the read end of
    // the pipe which is no longer needed by this process.
    dup2(pipefd[1], STDOUT_FILENO);
    // Exec `ls -l -h`.  If the exec fails, notify the user and exit.  Note
    // that the execvp variant first searches the $PATH before calling execve.
    if (execvp(argv1[0], argv1) == -1) {
      perror("exec");
      exit(EXIT_FAILURE);
    }
  } else {
    close(pipefd[0]);
    waitpid(pid1);

    char readbuffer[1024];
    int nbytes = read(pipefd[0], readbuffer, sizeof(readbuffer));
    printf("Received string: %s", readbuffer);
  }

  /*
  // Create our second process.
  pid2 = fork();
  if (pid2 == 0) {
    // Hook stdin up to the read end of the pipe and close the write end of
    // the pipe which is no longer needed by this process.
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[1]);
    // Similarly, exec `wc -l`.
    execvp(argv2[0], argv2);
    perror("exec");
    return 1;
  }
  // Close both ends of the pipe.  The respective read/write ends of the pipe
  // persist in the two processes created above (and happen to be tying stdout
  // of the first processes to stdin of the second).
  close(pipefd[0]);
  close(pipefd[1]);
  // Wait for everything to finish and exit.*/
  // /waitpid(pid1);
  //  waitpid(pid2);
  return 0;
}
