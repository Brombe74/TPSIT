import java.io.*;
import java.net.*;
import java.util.*;

public class ClientStr
{
    String nomeServer = "172.30.4.11";
    int portaServer = 6789;
    Socket miosocket;
    BufferedReader tastiera;
    String stringaUtente;
    String stringaRicevutaDalServer;
    DataOutputStream outVersoServer;
    BufferedReader inDalServer;

    public Socket connetti()
    {

        System.out.println("CLIENT partito in esecuzione ...");
        try 
        {
			//per l'input da tastiera
			tastiera=new BufferedReader(new InputStreamReader(System.in));
			
			//creo un socket
			miosocket=new Socket(nomeServer,portaServer);
			
			//associo 2 oggetti al socket per effettuare la scrittura e la lettura
			outVersoServer=new DataOutputStream(miosocket.getOutputStream());
			inDalServer=new BufferedReader(new InputStreamReader(miosocket.getInputStream())); 
        }
        catch (UnknownHostException ue)
        {
            System.err.println("Host sconosciuto");
        }
        
        catch (Exception e)
        {
            e.printStackTrace();
            System.exit(1);
        }

        return miosocket;
    }

    public void comunica() 
    {
		Runtime.getRuntime().addShutdownHook(new Thread() 
		{
            @Override
            public void run()
            {
				//chiudo la connessione
				System.out.println("\nGestione del CTRL+C...");
				System.out.println("CLIENT: termina elaborazione e chiude connessione");
				try
				{
					miosocket.close();
				}
				catch(Exception e)
				{
					e.printStackTrace();
					return;
				}
            }
        });
        try
        {
			while(true)
			{
				System.out.println("... Inserisci la stringa da trasmettere al server"+'\n');
				stringaUtente = tastiera.readLine();
            
				//la spedisco al server
				System.out.println("... Invio la stringa al server e attendo ...");
				outVersoServer.writeBytes(stringaUtente+'\n');
            
				//leggo la risposta dal server
				stringaRicevutaDalServer = inDalServer.readLine();
				System.out.println("... Risposta dal server "+'\n'+stringaRicevutaDalServer);
            }
        }
        
        catch(Exception e) 
        {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String args[]) 
    {
        ClientStr cliente = new ClientStr();


			cliente.connetti();
			cliente.comunica();
		
    }
}
