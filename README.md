# Chat Server in C
#### by May Hathaway, Sasha Wald, and Lei Lin (Period 10)

## A Short Description of Our Project
We've created a server/client system which allows multiple clients to connect and chat with one another. The chat-room supports some additional features, including reusable username/password logins, signal handling of user exits, a stored record of chat sessions between users, and simple games (namely, tic tac toe) run via a shell program.
## How-to
### Setting up the chat
To use this chat server, you will need to open multiple terminals. You should start with two!
Type the command 'make' in each terminal.

In one terminal, run the command './server.o'
- This will boot up the main server for the chat. You should only run it once while users are logged in.

In another terminal, run the command './client.o'
- This will allow you to create a new user or log in to the chat with an existing user. If you would like another user to log in simultaneously, open a new terminal and run the command './client.o' again.
- To create a new user, enter 'n' for the first question and follow the provided prompts. An example of this process is available under the image 'user_pass.png'

![alt text](https://github.com/mayhathaway/systems-final/blob/main/user_pass.png)

---
### Tic-tac-toe
- To start a tictactoe game type "ttt start" in a client
- To end the game type "ttt end" in a client
---
### Exit commands
- When you're finished using a client, type 'exit' to leave the chat. The  server will continue to run.
- Use ctrl-c to exit the chat. The exit will be recorded.
---
### Accessing Chatlogs
- Each time the server.o program is restarted, a new timestamped entry is added to the file chatlogmain.txt
- The chatlogs store user entrances/exits and messages sent to the chat. To access this information, you can do 'cat chatlogmain.txt' or access the file directly

## Additional Notes/Bugs
- Record of server exits can be found in server.out
- Avoid creating duplicate usernames
- There are some formatting errors currently: the server sends two "thank you for chatting" exit messages
- After completing a game of tic tac toe, there is a bug where the user is no longer able to chat. They should exit and rejoin the server.
