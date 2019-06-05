package Client;

public class MirroringClientThread implements Runnable {
	String serverIP;
	Client client;
	
	public MirroringClientThread(String serverIP, Client client) {
		this.serverIP = serverIP;
		this.client = client;
	}
	
	public void run() {
		MirroringClient MC = new MirroringClient(serverIP, client);
		while (true) {
			if (!client.getLive()) {
				try {
					MC.c_socket.close();
				} catch (Exception e) {}
				MC.dispose();
				break;
			}
			//System.out.println("client exit?");
			try {
				Thread.sleep(10);
			} catch (Exception e) {}
		}
	}
}
