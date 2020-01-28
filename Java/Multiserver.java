/*import java.io.*;
import java.net.*;
import java.util.*;


public class Multiserver
{	
	ServerSocket server = null;
    Socket client = null;
    String stringaRicevuta = null;
    String stringaModificata = null;
    BufferedReader inDalClient;
    DataOutputStream outVersoClient;

	public Socket attendi()
    {
        int porta = 6789;

        try
        {
            System.out.println("SERVER partito in esecuzione ...");
            //creo un server sulla porta 6789
            server = new ServerSocket(porta);
          
            //rimane in attesa di un client
            client = server.accept();
          
            //chiudo il server per inibire altri client
            server.close();
           
            //associo due oggetti al socket del client per effettuare la scrittura e la lettura
            inDalClient = new BufferedReader(new InputStreamReader(client.getInputStream()));
            outVersoClient = new DataOutputStream(client.getOutputStream());
        } 
	
	public static void main (String args[])
	{
		
	}
}
*/
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;


public class Multiserver implements Runnable 
{
   Socket csocket;
   public static int c;
   Multiserver(Socket csocket) 
   {
      this.csocket = csocket;
   }
   
   public static void main(String args[]) throws Exception
   { 
      ServerSocket ssock = new ServerSocket(1234);
      System.out.println("In ascolto");
      
      while (true) 
      {
         Socket sock = ssock.accept();
         c++;
         System.out.println("Connesso il "+c+"° client\n Informazioni client "+sock);
         new Thread(new Multiserver(sock)).start();
      }
   }
   public void run() 
   {
      try 
      {
         PrintStream pstream = new PrintStream(csocket.getOutputStream());
        
            pstream.println(" Benvenuto nel Multiserver OwO\n WIP");
         
         pstream.close();
         csocket.close();
      }
      catch (IOException e)
      {
         System.out.println(e);
      }
   }
}
