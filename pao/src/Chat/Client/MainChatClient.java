package Chat.Client;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Created by faraonul on 5/22/17.
 */
public class MainChatClient extends JFrame{
    public JTextField textField;
    public JTextArea textArea;
    private static ServerSocket server;
    private static Socket client;
    private static String host = "127.0.0.1";

    public static MainChatClient main;

    public MainChatClient() {
        super("Client");

        textField = new JTextField();
        textField.setEditable(false);
        add(textField, BorderLayout.SOUTH);


        textArea = new JTextArea();
        textArea.setEditable(false);
        add(new JScrollPane(textArea), BorderLayout.CENTER);
        textArea.setBackground(Color.WHITE);
        textArea.setForeground(Color.BLACK);
        textArea.setForeground(Color.BLACK);

        JMenu menu = new JMenu("Menu");
        JMenuItem exit = new JMenuItem("Exit");
        menu.add(exit);

        JMenuBar bar = new JMenuBar();
        setJMenuBar(bar);
        bar.add(menu);

        exit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        setSize(500, 500);
        setVisible(true);
    }

    public void showMessage(String message) {
        textArea.append(message + "\n");
    }
    public void enableText(boolean editable) {
        textField.setEditable(editable);
    }


    public static void main(String[] args) {
        MainChatClient main = new MainChatClient();
        main.setLocationRelativeTo(null);
        main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ExecutorService executor = Executors.newCachedThreadPool();

        try {
            main.showMessage("Opening Server ...");
            client = new Socket(InetAddress.getByName(host), 11111);
            main.showMessage("Connected:" + client.getInetAddress().getHostName());

            main.enableText(true);

            executor.execute(new ReceiveThread(client, main));
            executor.execute(new SendThread(client, main));

        } catch (IOException ex) {
            Logger.getLogger(MainChatClient.class.getName()).log(Level.SEVERE, null, ex);
        }
        finally {

        }
        executor.shutdown();
    }
}