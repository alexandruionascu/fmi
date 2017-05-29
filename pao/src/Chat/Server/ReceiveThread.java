package Chat.Server;

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;
import java.net.SocketException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Created by faraonul on 5/22/17.
 */

public class ReceiveThread implements Runnable {
    private final  MainChatServer main;
    private String message;
    private ObjectInputStream input;
    private Socket client;

    public ReceiveThread(Socket client, MainChatServer main){
        this.client = client;
        this.main = main;
    }

    public void showMessage(String message) {
        main.textArea.append(message);
    }

    public void run() {
        try {
            input = new ObjectInputStream(client.getInputStream());
        } catch (IOException ex) {
            Logger.getLogger(ReceiveThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        do {
            try {
                message = (String) input.readObject();
                main.showMessage(message);
            }
            catch (SocketException ex) {

            }
            catch (EOFException eofException) {
                main.showMessage("Connection closed");
                break;
            }
            catch (IOException ex) {
                Logger.getLogger(ReceiveThread.class.getName()).log(Level.SEVERE, null, ex);
            } catch (ClassNotFoundException classNotFoundException) {
                main.showMessage("Client disconnected");
            }
        } while (!message.equals("Server >>> DISCONNECTED"));

        try {
            input.close();
            client.close();
        }
        catch (IOException ioException) {
            ioException.printStackTrace();
        }

        main.showMessage("End of connection");
        System.exit(0);
    }
}