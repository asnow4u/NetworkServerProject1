import java.io.*;
import java.net.*;
import java.util.Scanner;

public class ChatServer{
  public static void main(String[] args){

    //Server class vars
    ServerSocket server;
    int port = 4444;
    String sentence;
    String reply;
    Scanner scan = new Scanner(System.in);

    //Attmpt to find port and connect with clients
    try{
        port = Integer.parseInt(args[0]);
        server = new ServerSocket(port);
        System.out.println("Waiting for connection...");
        Socket socket = server.accept();
        System.out.println("\nConnected To Client\n");
        BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter output = new PrintWriter(socket.getOutputStream(), true);


        while(true){
            try {

            //Read sentence from client
            sentence = input.readLine();
            if (sentence == null){
                throw new EOFException();
            }

            System.out.println(sentence);

            //Reply to client
            System.out.printf("Server> ");
            reply = scan.nextLine();

            //Check for quit command
            if (reply == "quit"){ //"\q" is an illegal escape character and cannot be used
              throw new EOFException();
            } else {
              output.println(reply);
              output.flush();
            }
          } catch(EOFException eo) {
          System.out.println("Connection with client ended");
          return;
          }
        }

    } catch(IOException io){
        System.out.println("Couldn't find port " + port);
        System.exit(1);
    }
  }
}
