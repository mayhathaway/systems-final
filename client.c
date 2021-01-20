#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(){
    //NOTE: planning to add some simply encryption to the username/password file if there's time. - sasha (if we don't get to it... it would be a good future addition so let that be noted!)
    //plan for client:
    //0) ask if user has name. if no, create name/password and add to file. if yes, proceed
    char buffer[256];
    
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
        //acquiring password from file
        char temppass[5];
        for(int i = 2; i < 6; i++){
           temppass[i-2]=(strstr(tempbuff,username)+namelen)[i];
        }
        printf("Enter the FOUR-NUMBER password associated with your username: ");
        char enteredpass[5];
        scanf("%s",enteredpass);
        if(strcmp(enteredpass,temppass)==0){
            printf("Correct password entered! Welcome to the chat.\n");
        }
        else{
            printf("Incorrect password entered. Please launch chat again.");
            exit(0);
        }
    }
    else{
        printf("please pick yes or no.\n");
    }
    //we can add duplicate username protection, but we don't have to
    //0.5) if name is in login info file and password is correct, log in. 
    //1) create named pipe for sending messages to server
    //1.5) messages should be sent with username info
    //2) recieve messages from server which are printed to terminal (accompanied by username that sent message)
}
