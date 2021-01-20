# DEVLOG

---

### Tues 1/19/21

- Added full username and password login support for the chat.
- An example of how to use the system in current form is visible in the image user_pass.png
- Contributor(s): Sasha Wald

---

### Tues 1/20/21

- Added the initial chat feature: chat supports up to 10 clients which connect by running client.o (server.o should simultaneously be running)
- Messages sent from clients are for now displayed in the main server. Will continue to work on having messages from other senders relayed back to clients
- Username/Password bug fixes: Added protection against nonexistent usernames, added chat exiting when incorrect password is entered.
- Should add protection against duplicate usernames + encryption for the namepass.txt file in the future, but it's probably okay if we don't get to it
- Found a bug where the server prints one empty message when a client joins. Not sure how to fix this yet!
- Contributor(s): Sasha Wald
