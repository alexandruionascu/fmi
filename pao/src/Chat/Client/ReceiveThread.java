package Chat.Client;

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
    private final MainChatClient main;
    private String message;
    private ObjectInputStream input;
    private final Socket client;


    public ReceiveThread(Socket client, MainChatClient main) {
        this.client = client;
        this.main = main;
    }

    public void showMessage(String message) {
        main.textArea.append(message);
    }

    @Override
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
                main.showMessage("Client Disconnected");
            }

        } while (!message.equals("Server >>> CLOSED"));

        try {
            input.close();
            input.close();
        }
        catch (IOException ioException) {
            ioException.printStackTrace();
        }

        main.showMessage("Connection ended");
        System.exit(0);
    }
}
