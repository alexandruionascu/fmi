package Chat.Client;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.SocketException;

/**
 * Created by faraonul on 5/22/17.
 */
public class SendThread implements Runnable{
    private final MainChatClient main;
    private ObjectOutputStream output;
    private String message;
    private final Socket connection;

    public SendThread(Socket connection, final MainChatClient main){
        this.connection = connection;
        this.main = main;

        main.textField.addActionListener(new ActionListener() {
                                              @Override
                                              public void actionPerformed(ActionEvent event) {
                                                  message = event.getActionCommand();
                                                  sendData(message);
                                                  main.textField.setText("");
                                              }
                                          }
        );
    }

    private void sendData(String message) {
        try {
            output.writeObject("Client: " + message);
            output.flush();
            main.showMessage("Client: " + message);
        }
        catch (IOException ioException){
            main.showMessage("Error sending message");
        }

    }

    public void showMessage(String message) {
        main.textArea.append(message);
    }

    public void run() {
        try {
            output = new ObjectOutputStream(connection.getOutputStream());
            output.flush();
        } catch (SocketException ex) {
        } catch (IOException ioException) {
            ioException.printStackTrace();
        } catch (NullPointerException ex) {
        }
    }

}