# Project Proposal
#### by May Hathaway, Sasha Wald, and Lei Lin


### Project Description: (DRAFT)
We will be working on a server/client system which allows multiple clients to connect and chat with one another. The chat-room will support additional features, including username/password logins (I'm not sure if we're doing this but thought I'd add it for now b/c it seems like a good idea - sasha), a stored record of chat sessions between users, and simple multiplayer games (tic tac toe & hangman could be good options - sasha) which store a record of high-scores.

### User Interface Description:
To connect to the chat, a client process can be ran which will prompt the user to enter an existing login or create a new one. After that, the user can communicate in the chat via the command line, where other messages will also be printed. Commands will be created which enable the user to find old chat sessions or interact with a game.

### Technical Design:
- #### Use of topics covered in class
  - Named pipes will be used to send information between chatters and the server
  - Use pipes to create private messages
  - We will work with files in order to create chat records (we could also use files for high scores? but I didn't add that just in case - sasha)
  - Games can be run on a child process
  - Files could be used to track progress for games (Allow games to be saved and continued?)
  - Signals (ctrl-c) from users will be processed in order to close chatlogs and remove unfinished games
  - Memory allocation will be used when creating structs that hold username/password information
- #### Breakdown of work
  - May Hathaway: 
  - Lei Lin: 
  - Sasha Wald: 
- #### Use of data structures and/or algorithms
- #### Timeline
  - 1/14: 
  - 1/17: 
  - 1/20: 
  - 1/23: 
  - (Insert due date here): Project complete
