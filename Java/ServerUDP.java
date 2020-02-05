import java.io.*;
import java.net.*;

public class ServerUDP
{
	public static void main(String args[]) throws Exception
	{
		DatagramSocket serverSocket=new DatagramSocket(2345);
		boolean attivo=true;
		byte[] bufferIN=new byte[1024];
		byte[] bufferOUT=new byte[1024];
		
		System.out.println("*-Avvio server-*");
		
		while(attivo)
		{
			DatagramPacket receivePacket=new DatagramPacket(bufferIN,bufferIN.length);
			serverSocket.receive(receivePacket);
			
			String ricevuto= new String(receivePacket.getData());
			int numCaratteri=receivePacket.getLength();
			System.out.println("Ricevuta la stringa: "+ricevuto);
			InetAddress IPClient=receivePacket.getAddress();
			int portaClient=receivePacket.getPort();
			
			String daSpedire=ricevuto.toUpperCase();
			bufferOUT=daSpedire.getBytes();
			
			DatagramPacket sendPacket=new DatagramPacket(bufferOUT, bufferOUT.length,IPClient,portaClient);
			serverSocket.send(sendPacket);
			
			//cotnrollo termine esecuzione del server
			if(ricevuto.equals("fine"))
			{
				System.out.println("*-Chiusura server-*");
				attivo=false;
			}
		}
		//chiusura server
		serverSocket.close();
	}
}
