#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

static void signal_handler(int sign){
    if (sign == SIGINT){
        int i = open("signal.out", O_APPEND | O_WRONLY | O_CREAT, 0644);
        char exit_message[] = "Program exited due to SIGINT\n";
        write(i, exit_message, strlen(exit_message));
        printf("\nThank you for chatting.\n");
        close(i);
        exit(0);
    }
}

int main(){
  int fd = open("chatlogmain.txt",O_WRONLY | O_CREAT | O_APPEND,0666);
  char newsession[256]="\nA new session of chat was started\r\n";
  time_t t;
  time(&t);
  write(fd,newsession,strlen(newsession));
  sprintf(newsession,"Time: %s\n",ctime(&t));
  write(fd,newsession,strlen(newsession));

  //0) recieve client message info, with username
  mkfifo("u_names",0644);
  mkfifo("numtemp",0644);
  int i = 0;
  int ttt = 0;

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
    char joinmessage[256];
    sprintf(joinmessage,"User %d has joined the chat: %s\n",i,usernames[i]);
    write(fd,joinmessage,strlen(joinmessage));
    close(fd1);

    i++;
    //1) send message + username info to all other clients
    int f = fork();
    if (f == 0){
      while(1){
        signal(SIGINT, signal_handler);
        sprintf(num, "%d", i - 1);
        char cts[128] = "cts";
        strcat(cts, num);
        char message[256];
        char tttcheck[256];
        char ttthelp[16] = "ttt start";
        strcpy(tttcheck, message);
        if (strstr(tttcheck, ttthelp)) {
            char *args[] = {"./game.o" ,NULL};
            execvp(args[0], args);
        }
        int fd2 = open(cts,O_RDWR);
        read(fd2,message,sizeof(message));
        close(fd2);
        if(strncmp("exited",message,8)==0){
            printf("%s has exited.\n",usernames[i-1]);
            char filemessage[256];
            sprintf(filemessage,"%s has exited.\r\n",usernames[i-1]);
            write(fd,filemessage,strlen(filemessage));
        }
        else{
          //little bugfix for an error after client exiting
            char * sep = strtok(message,"\n");
            char filemessage[256];
            strcpy(filemessage,message);
            strcat(filemessage,"\r\n");
            write(fd,filemessage,strlen(filemessage));
            printf("%s\n",message);
        }

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
