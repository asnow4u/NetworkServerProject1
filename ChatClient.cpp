#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

int main(){
  char message[500];
  int port = 4444;
  int client;
  int sresult;
  int fromServer;
  string sentence;

  //Initialize socket
  int network_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);

  //Connect with server
  int connection = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

  if (connection == -1){
    cout << "error during connection\n" << endl;
  } else {
    cout << "Connected";

    //Get user input and send to server
    do{
      cout << "\n\nPlease Enter A Sentence: ";
      //sentence = "";
      getline(cin, sentence);

      if (sentence.size() > 0){
        send(network_socket, sentence.c_str(), sentence.size(), 0);
        send(network_socket, "\n", 1, 0);
        cout << "\nSending To Server...\n\n";

        //Display sentece recieved from server
        fromServer = recv(network_socket, &message, sizeof(message), 0);
        if (fromServer > 0){
          cout << "Recieved Back From Server: " << string(message, 0, fromServer) << endl;
        }
      }

    } while(sentence.size() > 0);

  }
  return 0;
}
