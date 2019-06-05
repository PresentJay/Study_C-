package Server;



public class FileSendThread implements Runnable {
	FileClientInfo fci;
	String fileName;
	
	public FileSendThread(FileClientInfo fci, String fileName) {
		this.fci = fci;
		this.fileName = fileName;
	}
	
	public void run() {
		fci.sendFile(fileName);
	}
}
