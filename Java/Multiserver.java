import java.io.*;
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

