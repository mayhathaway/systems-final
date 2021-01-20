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
    int i = 0;
    while(1){
        int fd1 = open("u_names",O_RDONLY);
        //supports up to 10 users at once. you can easily change this by adjusting array 'usernames'
        char usernames[10][256];
        
        read(fd1,usernames[i],sizeof(usernames[i]));
        printf("\n");
        i++;
        printf("User %d has joined the chat: %s\n",i,usernames[i-1]);
        close(fd1);

        //1) send message + username info to all other clients
        int f = fork();
        if (f == 0){
            while(1){
                int fd2 = open(usernames[i-1],O_RDONLY);
                char message[256];
                read(fd2,message,sizeof(message));
                close(fd2);
                printf("%s\n",message);
            }
        }
    }
}
