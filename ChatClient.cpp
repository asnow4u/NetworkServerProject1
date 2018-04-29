#include <iostream>
#include <string.h>
#include <stdlib.h>
//#include <sys/types.h> //for linux
//#include <sys/socket.h> //for linux
//#include <netinet/ln.h>
#include <Winsock2.h> //for windows

using namespace std;

int main(){
  char message[500];
  int port = 4444;

  int client;

  //initialize socket
  socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET; // comes from netinet header
  server_address.sin_port = htons(port);
  //server_address.sin_addr.s_addr =

  int connection = connect(socket, (struct sockaddr *) &server_address, sizeof(server_address));

  if (connection == -1){
    cout << "error during connection" << endl;
  }

  recv(socket, &message, sizeof(message), 0); //recieve data from server

  close(socket);

  return 0;


}
