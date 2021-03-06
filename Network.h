#ifndef NETWORK_H

#define NETWORK_H

/***********************************
 * Manages all network connections,
 * reconnects, data sending and data
 * retrieval.
 ***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <netdb.h>
#include <string.h>
#include <errno.h> 

#define MAX_MESSAGE_LENGTH 10000

class Network
{
public:
    Network( const char* serv, const int port );
    void  sendMessage(char*);
    char* receiveMessage();
    
private:
	void  connectServer();
	char* getMessageBack();
	int serverSockfd;
	struct sockaddr_in server;
	struct hostent *host;
	char messageBack[MAX_MESSAGE_LENGTH];
	int bytes;	
};

#endif
