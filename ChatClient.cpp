#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

int main(int argc, char *argv[]){ //Hostname, port number

  //Client class vars
  char message[500];
  string hostname;
  int port;
  int client;
  int sresult;
  int fromServer;
  string sentence;

  //Check for arguments
  if (argc != 3){
    cout << "Arguments Needed: Hostname, Port Number";
    cout << argc;
    exit(1);
  }

  //Initialize socket
  hostname = argv[1];
  port = atoi(argv[2]);
  int network_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);

  //Connect with server
  int connection = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

  if (connection == -1){
    cout << "error during connection" << endl;
  } else {
    cout << "\nConnected\n";

    //Get user input and send to server
    do{
      //User input
      cout << hostname + "> ";
      getline(cin, sentence);

      //Check for quit command
      if (sentence == "quit"){ //"\q" is an illegal escape character and cannot be used
        return 0;
      } else {
        sentence = hostname + "> " + sentence;
      }

      //Send to server
      if (sentence.size() > 0){
        send(network_socket, sentence.c_str(), sentence.size(), 0);
        send(network_socket, "\n", 1, 0);

        //Display sentence recieved from server
        fromServer = recv(network_socket, &message, sizeof(message), 0);
        if (fromServer > 0){
          cout << "Server> " << string(message, 0, fromServer);
        }
      }
    } while(sentence.size() > 0);

  }
  return 0;
}
