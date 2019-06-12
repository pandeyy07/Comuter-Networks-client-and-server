#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include <string>
#include <thread>
#include <iostream>

using namespace std;

int main()
{

struct sockaddr_in ADDR;

long message;
int sockfd;
int socklsn;
socklen_t clientAddrSize = sizeof(ADDR);

sockfd = socket(AF_INET, SOCK_STREAM, 0);

ADDR.sin_addr.s_addr = inet_addr("127.0.0.1");
ADDR.sin_port = htons(8080);
ADDR.sin_family = AF_INET;

socklsn = socket(AF_INET, SOCK_STREAM, 0);
bind(socklsn, (struct sockaddr*)&ADDR, sizeof(ADDR));
listen(socklsn, SOMAXCONN);

for(;;){
    cout << "\n\tSERVER: Waiting for incoming connection...";
    if (sockfd = accept(socklsn, (struct sockaddr*)&ADDR, &clientAddrSize)){
        cout << "\n\tConnection found" <<endl;
	message = send(sockfd, "Connection between server and Client accomplished", ,0 );
        }
    }
}
