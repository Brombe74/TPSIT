import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

public class chat implements Runnable
{
	public static void main(String[] args) throws IOException 
	{     
		ServerSocket serverSocket = null;
		
		try
		{
			serverSocket = new ServerSocket(2345);
		}
		
		catch (IOException e)
		{
			System.err.println("Errore durante la connessione");
			System.exit(-1);
		}

		while (true) 
		{
			new MultiServerThread(serverSocket.accept()).start();
		}
		
		serverSocket.close();
	}	
}

