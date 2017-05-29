package Chat.Server;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Created by faraonul on 5/22/17.
 */

public class MainChatServer extends JFrame {
    public JTextField textField;
    public JTextArea textArea;
    private static ServerSocket server;
    private static Socket connection;
    private static String host = "127.0.0.1";

    public static MainChatServer main;

    public MainChatServer() {
        super("Server");

        textField = new JTextField();
        textField.setEditable(false);
        add(textField, BorderLayout.SOUTH);

        textArea = new JTextArea();
        textArea.setEditable(false);
        add(new JScrollPane(textArea), BorderLayout.CENTER);
        textArea.setBackground(Color.WHITE);
        textArea.setForeground(Color.BLACK);
        textField.setForeground(Color.BLACK);

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
        MainChatServer main = new MainChatServer();
        main.setLocationRelativeTo(null);
        main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ExecutorService executor = Executors.newCachedThreadPool();

        try {
            server = new ServerSocket(11111, 100);
            main.showMessage("Waiting for clients...");

            while (true){
                try {
                    connection = server.accept();
                    main.showMessage("Connected : " + connection.getInetAddress().getHostName());
                    main.enableText(true);
                    executor.execute(new ReceiveThread(connection, main));
                    executor.execute(new SendThread(connection, main));
                } catch (IOException ex) {
                    Logger.getLogger(MainChatServer.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        } catch (IOException ex) {
            Logger.getLogger(MainChatServer.class.getName()).log(Level.SEVERE, null, ex);
        }
        finally {
        }
        executor.shutdown();
    }
}