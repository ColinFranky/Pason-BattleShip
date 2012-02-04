/***********************************
 * Implementation of Network.h
 ***********************************/
 
 #include "Network.h"
 #include <iostream>
 
 Network::Network()
 {
	//Initialization of server
	memset(&server,0,sizeof(server));
	server.sin_family = AF_INET;
	//PORT 6130 from Header
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	//obtaining server host ip.
	host = gethostbyname("pason1.enel.ucalgary.ca");
	
	if( host == NULL)
	{
		fprintf(stderr,"could not find host: pason1.enel.ucalgary.ca");
		exit(1);
	}
	//Setting host.
	bcopy(host->h_addr, &server.sin_addr, host->h_length);
 }
 
 void Network::connectServer()
 {
	if( (serverSockfd = socket(PF_INET, SOCK_STREAM,0) ) == -1 )
	{
		fprintf(stderr,"Failed to create client socket socket");
		exit(1);
	}	

	
	if( connect(serverSockfd, (struct sockaddr *)&server, sizeof(struct sockaddr_in)) == -1)
	{
		fprintf(stderr,"failed to connect to server");
		exit(1);
	}
	
}


char * Network::receiveMessage()
{
	bytes = recv(serverSockfd, messageBack, MAX_MESSAGE_LENGTH, 0);
	if(bytes > 0)
	{
		messageBack[bytes] = '\0';
		return messageBack();
	}
	return NULL;
}

void Network::sendMessage(char* messageToSend)
{
	send(serverSockfd,messageToSend,strlen(messageToSend),0);
}

char* Network::getMessageBack()
{
	return messageBack;
}