# Project Proposal
#### by May Hathaway, Sasha Wald, and Lei Lin


### Project Description:
We will be working on a server/client system which allows multiple clients to connect and chat with one another. The chat-room will support additional features, including username/password logins , a stored record of chat sessions between users, and simple multiplayer games (namely, tic tac toe & hangman) which store a record of high-scores.

### User Interface Description:
To connect to the chat, a client process can be ran which will prompt the user to enter an existing login or create a new one. After that, the user can communicate in the chat via the command line, where other messages will also be printed. Commands will be created which enable the user to find old chat sessions or interact with a game.

### Technical Design:
- #### Use of topics covered in class
  - Named pipes will be used to send information between chatters and the server
  - Use pipes to create private messages
  - We will work with files in order to create chat records and store high scores, and potentially to track game progress
  - Games can be run on a child process
  - Signals (ctrl-c) from users will be processed in order to close chatlogs and remove unfinished games
  - Memory allocation will be used when creating structs that hold username/password information
- #### Breakdown of work
  - May Hathaway: User signal handling, chatlogs
  - Lei Lin: Games, private messaging
  - Sasha Wald: Creation of chat functionality + username & password system
- #### Timeline
  - 1/14: Completion of basic system which allows clients to chat with each other
  - 1/17: Completion of username and password system as well as chat logs
  - 1/20: Completion of games + high-score/game progress record
  - 1/23: Misc: Bug fixing, handling user quits & private messages
  - (Insert due date here): Project complete
