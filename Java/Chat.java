import java.io.*;
import java.net.*;
import java.util.*;

public class Chat
{
	private static int porta= 2345;
	public static void main (String args[]) throws Exception
	{
		
		Runnable server = new ServerChat(porta);
		new Thread(server).start();
		
		
		Runnable client = new ClientChat("172.30.4.255",porta);
		new Thread(client).start();
		
	}
}

class ServerChat implements Runnable
{
	private int Max=16;
	private ArrayList lista;
	private DatagramSocket serverSocket;
	
	public void ServerChat(int max, ArrayList list)
	{
		this.Max=max;
		this.lista=new ArrayList(list);
	}
	
	public ServerChat(int porta)
	{
		try
		{
			this.serverSocket=new DatagramSocket(porta);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
	public void run()
	{
		byte[] bufferIN=new byte[1024];
		byte[] bufferOUT=new byte[1024];
		boolean attivo=true;
		String ricevuto=new String("");
		
		System.out.println("**Avvio Chat**");
		while(attivo)
		{
			try
			{
				DatagramPacket receivePacket=new DatagramPacket(bufferIN,bufferIN.length);
				serverSocket.receive(receivePacket);
			
				ricevuto= new String(receivePacket.getData());
				int numCaratteri=receivePacket.getLength();
				System.out.println("Ricevuta la stringa: "+ricevuto);
				ricevuto="";
				InetAddress IPClient=receivePacket.getAddress();
				int portaClient=receivePacket.getPort();
			
		/*		String daSpedire=ricevuto.toUpperCase();
				bufferOUT=daSpedire.getBytes();
			
				DatagramPacket sendPacket=new DatagramPacket(bufferOUT, bufferOUT.length,IPClient,portaClient);
				serverSocket.send(sendPacket);
		*/
			}
			catch(Exception e)
			{
				System.out.println(e);
			}
			
			
			//cotnrollo termine esecuzione del server
			if(ricevuto.equals("fine"))
			{
				System.out.println("*-Chiusura server-*");
				attivo=false;
			}
		}
	}
	
}

class ClientChat implements Runnable
{
	private int porta;
	private InetAddress IPserver;
	
	public ClientChat(String IP,int portaserver)
	{
		try
		{
			IPserver=InetAddress.getByName(IP);
			this.porta=portaserver;
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
	public void run()
	{
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		byte[] bufferIN=new byte[1024];
		byte[] bufferOUT=new byte[1024];
		String idinit=new String("<id value=12> <msg> ");
		String idfine=new String(" </msg> </id>");
		String iddef=new String(" ");
		DatagramSocket clientSocket=null;
		boolean attivo=true;
		
		try
		{
			clientSocket= new DatagramSocket();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		while(attivo)
		{
			
			System.out.println("Inserisci il tuo messaggio");
		
			try
			{
				iddef= input.readLine();
			}
			catch(Exception e)
			{
				System.out.println(e);
			}
		
			idinit=idinit.concat(iddef);
			idinit=idinit.concat(idfine);
		
			bufferOUT=idinit.getBytes();
		
			DatagramPacket sendPacket=new DatagramPacket(bufferOUT,bufferOUT.length,this.IPserver,this.porta);
			
		
			try
			{
				clientSocket.send(sendPacket);
			}
			catch(Exception e)
			{
				System.out.println(e);
			}
			bufferOUT=null;
			bufferIN=null;
			iddef=" ";
		}
		clientSocket.close();
		
	}
}
	


class clientObjct
{
	private int id;
	private int timeout;
	private int porta;
	
	public clientObjct()
	{
		this.id=0;
		this.porta=8080;
		this.timeout=30;
	}
	
	public clientObjct(int id,int porta)
	{
		this.id=id;
		this.porta=porta;
		this.timeout=30;
	}
	public void run()
	{
		
	}
}

