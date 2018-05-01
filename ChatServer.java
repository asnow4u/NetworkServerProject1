import java.io.*;
import java.net.*;

public class ChatServer{
  public static void main(String[] args){

    ServerSocket server;
    int port = 4444;
    String sentence;
    String upperSentence;

    //Attmpt to find port and connect with clients
    try{
        server = new ServerSocket(port);
        System.out.println("Waiting for connection...");
        Socket socket = server.accept();
        System.out.println("\nConnected To Client");
        BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter output = new PrintWriter(socket.getOutputStream(), true);

        while(true){
            try {
              
            //Read sentence from client
            sentence = input.readLine();
            System.out.println("\nReading Input...");
            System.out.println("Sending Reply...");

            //Return uppercased sentence
            upperSentence = sentence.toUpperCase() + "\n";
            output.println(upperSentence);
            output.flush();

          } catch(EOFException eo) {
          System.out.println("Connection with server ended");
          }
        }

    } catch(IOException io){
        System.out.println("Couldn't find port " + port);
        System.exit(1);
    }
  }
}
