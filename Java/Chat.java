import java.io.*;
import java.net.*;
import java.util.*;

public class Chat
{
	private static int porta= 2345;
	public static void main (String args[]) throws Exception
	{
		
		ServerChat server = new ServerChat(porta);
		server.run();
		
		
		clientObjct client = new clientObjct();
		//BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		//InetAddress IPserver=InetAddress.getByName("172.30.4.255");
		
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
				InetAddress IPClient=receivePacket.getAddress();
				int portaClient=receivePacket.getPort();
			
				String daSpedire=ricevuto.toUpperCase();
				bufferOUT=daSpedire.getBytes();
			
				DatagramPacket sendPacket=new DatagramPacket(bufferOUT, bufferOUT.length,IPClient,portaClient);
				serverSocket.send(sendPacket);
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

class clientObjct implements Runnable
{
	private int id;
	private int timeout;
	private String msg;
	private int porta;
	
	public clientObjct()
	{
		this.id=0;
		this.msg=new String("");
		this.porta=8080;
		this.timeout=30;
	}
	
	public clientObjct(int id,int porta)
	{
		this.id=id;
		this.porta=porta;
		this.msg=new String(" ");
		this.timeout=30;
	}
	public void run()
	{
		
	}
}

