import java.io.*;
import java.net.*;
//pag158
public class ClientUDP
{
	public static void main(String args[]) throws Exception
	{
		int portaServer=2345;
		InetAddress IPserver=InetAddress.getByName("172.30.4.11");
		
		byte[] bufferOUT=new byte[1024];
		byte[] bufferIN= new byte[1024];
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		
		//creazione socket
		DatagramSocket clientSocket= new DatagramSocket();
		System.out.println("Inserisci messaggio da inviare al Server");
		//preparazione del messaggio da spedire
		String daSpedire= input.readLine();
		bufferOUT=daSpedire.getBytes();
		
		DatagramPacket sendPacket=new DatagramPacket(bufferOUT,bufferOUT.length,IPserver,portaServer);
		clientSocket.send(sendPacket);
		
		DatagramPacket receivePacket=new DatagramPacket(bufferIN,bufferIN.length);
		clientSocket.receive(receivePacket);
		String ricevuto=new String(receivePacket.getData());
		
		int numCaratteri=receivePacket.getLength();
		ricevuto=ricevuto.substring(0,numCaratteri);
		System.out.println("Messaggio dal Server: "+ricevuto);
		
		clientSocket.close();
	}
}
