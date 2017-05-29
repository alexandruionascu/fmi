package com.company.Client;

/**
 * Created by faraonul on 5/21/17.
 */

import com.company.RMI.ClientRMI;
import com.company.Shared.IClient;
import com.company.Shared.IServer;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class Client extends ClientRMI {
    static String number = null;
    private IClient client;
    private final ChatGUI chatClient;
    protected ClientRoom room;

    public Client(String number, IServer server) throws RemoteException {
        super(number, server);
        chatClient = new ChatGUI(server, this);
        chatClient.setVisible(true);
        room = null;
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            IServer server = (IServer) Naming.lookup("rmi://localhost//Chat");
            while(number == null)
                number = JOptionPane.showInputDialog(null, null, "Ingresa tu nick", JOptionPane.PLAIN_MESSAGE);
            IClient client = new Client(number, server);
            server.addUser(null, client);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public void update(int option) throws RemoteException {
        if(option == 1 || option == 2) {
            chatClient.getConectados().setText("Connected \n");
            String[] users = server.getUsers(null);
            if(users != null)
                for(String u : users)
                    chatClient.getConectados().append(u+"\n");
        }else{
            if(option == 3) {
                chatClient.getComun().setText("");
                String[] messages = server.getMessages(null);
                if(messages != null)
                    for(String m : messages)
                        chatClient.getComun().append(m+"\n");
            }
        }
    }

    @Override
    public void update(String roomID, int option) throws RemoteException {
        if(room == null)
            room = new ClientRoom(nickname, server, roomID);
        room.run();
        room.update(2);
        room.update(3);
        room.update(4);
    }
}
