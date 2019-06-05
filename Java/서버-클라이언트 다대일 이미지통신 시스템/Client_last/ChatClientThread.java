package Client;

public class ChatClientThread implements Runnable{
	String serverIP;
	Client client;
	String nickName;
	public ChatClientThread(String serverIP, Client client, String nickName) {
		this.serverIP = serverIP;
		this.client = client;
		this.nickName = nickName;
	}
	public void run() {
		ChatClient CC = new ChatClient(serverIP, client, nickName);
		while(true) {
			if (!client.getLive()) {
				try {
					CC.c_socket.close();
				} catch (Exception e) {}
				System.out.println("");
				CC.dispose();
				break;
			}
			//System.out.println("client exit?");
			try {
				Thread.sleep(10);
			} catch (Exception e) {}
		}
	}
}
