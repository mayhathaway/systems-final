#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(){
  //0) recieve client message info, with username
  mkfifo("u_names",0644);
  mkfifo("numtemp",0644);
  int i = 0;
  while(1){
    int fd1 = open("u_names",O_RDONLY);
    //supports up to 10 users at once. you can easily change this by adjusting array 'usernames'
    char usernames[10][128];

    int temppipe = open("numtemp", O_WRONLY);
    char num[8];
    sprintf(num, "%d", i);
    write(temppipe, num, sizeof(num));
    close(temppipe);

    read(fd1,usernames[i],sizeof(usernames[i]));
    printf("\n");
    printf("User %d has joined the chat: %s\n",i,usernames[i]);
    close(fd1);

    i++;
    //1) send message + username info to all other clients
    int f = fork();
    if (f == 0){
      while(1){
        sprintf(num, "%d", i - 1);
        char cts[128] = "cts";
        strcat(cts, num);
        char message[256];
        int fd2 = open(cts,O_RDWR);
        read(fd2,message,sizeof(message));
        close(fd2);
        printf("%s\n",message);

        // int j = 0;
        // while (usernames[j] && j < 10) {
        //   if (j != i - 1) {
        //     char stcpipe[32] = "stc";
        //     sprintf(num, "%d", j);
        //     strcat(stcpipe, num);
        //     int toclient = open(stcpipe, O_RDWR);
        //     write(toclient, message, sizeof(message));
        //     close(toclient);
        //     j++;
        //   }
        // }
      }
    }
  }
}
