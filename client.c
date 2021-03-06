#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

static void signal_handler(int sign){
    if (sign == SIGINT){
        int i = open("signal.out", O_APPEND | O_WRONLY | O_CREAT, 0644);
        char exit_message[] = "Program exited due to SIGINT\n";
        write(i, exit_message, strlen(exit_message));
        printf("\nThank you for chatting\n");
        close(i);
        exit(0);
    }
}

int main(){
    //NOTE: planning to add duplicate username prevention and some simple encryption to the username/password file if there's time. - sasha (if we don't get to it... it would be a good future addition so let that be noted!)

    //0) ask if user has name. if no, create name/password and add to file. if yes, proceed. if name is in login info file and password is correct, log in.
    char buffer[256];
    char finaluser[256];
    int ttt = 0;

    //asking for existing login
    printf("Do you have an existing login? [y/n]: ");
    fgets(buffer,2,stdin);
    //create new login
    if(strcmp(buffer,"n")==0){
        printf("Enter the username you want (this will be reusable): ");
        char username[256];
        scanf("%s",username);
        strcat(username,"\r\n");
        printf("Enter the FOUR-NUMBER password you want (this will also be reusable): ");
        char password[256];
        scanf("%s",password);
        strcat(password,"\r\n");
        int fd = open("namepass.txt",O_WRONLY | O_CREAT | O_APPEND,0666);
        write(fd,username,strlen(username));
        write(fd,password,strlen(password));
        close(fd);
        strcpy(finaluser,username);
        printf("A new login has been created! Please restart to chat.\n");
        exit(0);
    }
    //user indicated they already have a login
    else if(strcmp(buffer,"y")==0){
        printf("Enter the existing username: ");
        char username[256];
        scanf("%s",username);
        int fd = open("namepass.txt",O_RDONLY);
        char tempbuff[256];
        read(fd,tempbuff,256);
        int namelen = strlen(username);
        if(strstr(tempbuff,username) == NULL){
            printf("Username not found. Please try again.\n");
            exit(0);
        }
        //acquiring password from file
        char temppass[5];
        for(int i = 2; i < 6; i++){
           temppass[i-2]=(strstr(tempbuff,username)+namelen)[i];
        }
        //checking password
        printf("Enter the FOUR-NUMBER password associated with your username: ");
        char enteredpass[5];
        scanf("%s",enteredpass);
        if(strcmp(enteredpass,temppass)==0){
            printf("Correct password entered! You may now type to the chat.\n");
        }
        else{
            printf("Incorrect password entered. Please launch chat again.\n");
            exit(0);
        }
        strcpy(finaluser,username);
    }
    else{
        printf("please pick yes or no.\n");
        exit(0);
    }
    //1) send client username to server pipe - then create pipe with username!
    int fd1 = open("u_names",O_WRONLY);
    write(fd1,finaluser,sizeof(finaluser));
    close(fd1);

    int temppipe = open("numtemp", O_RDONLY);
    char num[8];
    read(temppipe, num, sizeof(num));
    close(temppipe);

    char textbuffer[256];
    char cts[32] = "cts";
    strcat(cts, num);
    mkfifo(cts,0644);
    char stc[32] = "stc";
    strcat(stc, num);
    mkfifo(stc, 0644);

    if (fork() == 0) {
      while(1) {
        char buffer2[256];
        int toclient = open(stc, O_RDWR);
        printf("[stc %s]\n",stc );
        read(toclient, buffer2, sizeof(buffer2));
        printf("%s\n",buffer2);
        close(toclient);
      }
    } else {
      while(1) {
          //message is contained in textbuffer
        signal(SIGINT,signal_handler);
          int check = 1;
          read(STDIN_FILENO, textbuffer, sizeof(textbuffer) - 1);
            if(strncmp("exit",textbuffer,2) == 0){
                printf("Thank you for chatting\n");
                char exitmessg[256]="exited";
                int fd2 = open(cts,O_WRONLY);
                write(fd2,exitmessg,sizeof(exitmessg));
                close(fd2);
                exit(0);
            }
          char tttcheck[256];
          char ttthelp2[16] = "ttt end";
          strcpy(tttcheck, textbuffer);
          if (strstr(tttcheck, ttthelp2)) {
            ttt = 0;
            check = 0;
          }
          if (ttt) {
            int tttpipe = open("ctg", O_WRONLY);
            write(tttpipe, textbuffer, sizeof(textbuffer));
          } else {
            char finmessg[256];
            char t1[4] = "[";
            char t2[4] = "]";
            char colon[12]=": ";
            strcpy(finmessg,finaluser);
            strcat(finmessg, t1);
            strcat(finmessg, num);
            strcat(finmessg, t2);
            strcat(finmessg,colon);
            strcat(finmessg,textbuffer);
            //strcat(finmessg,textbuffer);
            int fd2 = open(cts,O_WRONLY);
            write(fd2,finmessg,sizeof(finmessg));
            close(fd2);
          }
          if (check){
            char ttthelp[16] = "ttt ";
            strcpy(tttcheck, textbuffer);
            if (strstr(tttcheck, ttthelp)) {
              mkfifo("ctg", 0644);
              ttt = 1;
            }
          }
          check = 1;
      }
    }


    //2) recieve messages from server which are printed to terminal (accompanied by username that sent message)
    // not sure if we should do the above! lmk -sasha
}
