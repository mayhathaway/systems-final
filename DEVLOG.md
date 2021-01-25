# DEVLOG

---

### Monday 1/19/21

- Added full username and password login support for the chat.
- An example of how to use the system in current form is visible in the image user_pass.png
- Contributor(s): Sasha Wald

---

### Tuesday 1/20/21

- Added the initial chat feature: chat supports up to 10 clients which connect by running client.o (server.o should simultaneously be running)
- Messages sent from clients are for now displayed in the main server. Will continue to work on having messages from other senders relayed back to clients
- Username/Password bug fixes: Added protection against nonexistent usernames, added chat exiting when incorrect password is entered.
- Should add protection against duplicate usernames + encryption for the namepass.txt file in the future, but it's probably okay if we don't get to it
- Fixed a bug where the server prints one empty message when a client joins.
- Found a bug where newly created logins provide a weird format on the first usage. Temporarily fixed by forcing relog when a new login is created.
- Contributor(s): Sasha Wald

---

### Saturday 1/23/21
- Added multiword functionality to the chat
- Spent 12+ hours trying to get clients to communicate with each other
- Updated names of pipes
- Introduced new pipes for 2 way communication
- Contributor(s): Lei Lin

---

### Saturday 1/23/21
- Added tic tac toe through game.c
- Continued trying to add private messaging but was still unsuccessful
- Contributor(s): Lei Lin

---

### Sunday 1/24/21
- Added signal handling for user exits and exit messages to server.o
- Fixed a bug with old messages being tacked onto new ones after other clients exited
- Found bug where tic tac toe prevents chatting after the game is finished - not sure how to fix this since exec only returns when a program breaks..?
- Contributor(s): Sasha Wald

---

### Sunday 1/24/21
- Added signal handling for client.c so that it exits with Ctrl+C
- Added signal handling for server
- Found a bug: after Ctrl+C, it printed "Thank you for chatting", "may: may: may: may: may: may: may: may: may:"", and then "Thank you for chatting", will figure out why that is.
- Contributor(s): May Hathaway

---

### Sunday 1/24/21
- Fixed the "may: may: may: may:" bug
- Attempted fix for multiple "thank you" server messages - was able to remove one of them
- Minor aesthetic changes
- Contributor(s): Sasha Wald
