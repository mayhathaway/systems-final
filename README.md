# Chat Server in C
#### by May Hathaway, Sasha Wald, and Lei Lin (Period 10)

## A Short Description of Our Project
We've created a server/client system which allows multiple clients to connect and chat with one another. The chat-room supports some additional features, including reusable username/password logins, signal handling of user exits, a stored record of chat sessions between users, and simple games (namely, tic tac toe) run via a shell program.
## How-to
---
### Setting up the chat
To use this chat server, you will need to open multiple terminals. You should start with two!
Type the command 'make' in each terminal.

In one terminal, run the command './server.o'
- This will boot up the main server for the chat. You should only run it once while users are logged in.

In another terminal, run the command './client.o'
- This will allow you to create a new user or log in to the chat with an existing user. If you would like another user to log in simultaneously, open a new terminal and run the command './client.o' again.
- To create a new user, enter 'n' for the first question and follow the provided prompts. An example of this process is available under the image 'user_pass.png'
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
