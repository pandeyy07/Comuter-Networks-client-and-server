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

void main()
{
  long success;
  string commence;
  string temp;
  char message[200];
  int sockfd;

  struct sockaddr_in addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  addr.sin_port = htons(8080);
  addr.sin_family = AF_INET;

  cout << "\n\tConnect(y/n)";
  cin >> commence;

  if(commence == "n"){
    cout << "\n\tQuiting";
  }
  else if (commence == "y"){
    connect(sockfd,(struct sockaddr*)&addr, sizeof(addr));
    success = recv(sockfd, message, sizeof(message), 0);
    temp = message;

    cout << "\n\tMessage from Server: " << temp << endl;
  }
  else{
    cout << "\n\tError with message";
  }
  cout << "\n\n\t";
  return EXIT_SUCCESS;
}
