//Import libraries
import java.io.*;
import java.net.*;

public class ChatServer{
  public static void main(String[] args){

    ServerSocket server;
    int port = 4444;
    Socket socket;
    String sentence;
    ObjectInputStream input;
    ObjectOutputStream output;

    try{
        server = new ServerSocket(port);
        while(true){
          try{
            socket = server.accept();
            output = new ObjectOutputStream(socket.getOutputStream());
            output.flush();
            input = new ObjectInputStream(socket.getInputStream());

          //message();

          } catch(EOFException eo) {
          System.out.println("Connection with server ended");
          } finally{
            //output.close();
            //input.close();
            //socket.close();
          }
        }

    } catch(IOException io){
        System.out.println("Couldn't find port " + port);
        System.exit(1);
    }
  }

  private static void message(){

  }

}
