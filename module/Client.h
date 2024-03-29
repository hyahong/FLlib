#ifndef _F_CLIENT_H_
# define _F_CLIENT_H_

# include <locale>
# include <codecvt>
# include <iostream>
# include <string.h>
# include <sys/socket.h>
# include <unistd.h>
# include <stdio.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <errno.h>
# include "protocol.h"

class Client
{
public:
	Client();
	~Client();

	bool Init ();
	bool Connect (const char * host, int port);

	int Signal ();
	int Read (char ** buf);
	void Write (const char * buf, unsigned int length);

private:
	int socketFd;
	struct sockaddr_in address;

	fd_set readFds;
	fd_set writeFds;
};

#endif
