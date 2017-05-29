package com.company.Client;

import com.company.RMI.ClientRMI;
import com.company.Shared.IServer;

import javax.swing.*;
import java.rmi.RemoteException;

/**
 * Created by faraonul on 5/21/17.
 */
public class ClientRoom extends ClientRMI {

    private final RoomInterface chatClient;
    private final String roomID;

    public ClientRoom(String nick, IServer server, String roomID) throws RemoteException {
        super(nick, server);
        this.roomID = roomID;
        chatClient = new RoomInterface(server, this, roomID);
    }

    public void run() {chatClient.setVisible(true);}

    @Override
    public void update(int options) throws RemoteException {
        if(chatClient != null) {
            if(options == 1 || options == 2) {
                chatClient.getConectados().setText("");
                String[] users = server.getUsers(chatClient.getRoomID());
                if(users != null)
                    for(String u : users)
                        chatClient.getConectados().append(u+"\n");
            }else {
                if(options == 3){
                    chatClient.getRoom().setText("");
                    String[] mensajes = server.getMessages(chatClient.getRoomID());
                    if(mensajes != null)
                        for(String m : mensajes)
                            chatClient.getRoom().append(m + "\n");
                }else{
                    if(options == 4){
                        String [] users = server.getUsers(null);
                        chatClient.getList().setModel(new DefaultComboBoxModel(users));
                    }
                }
            }
        }
    }

    @Override
    public void update(String roomID, int option) throws RemoteException {
        if(option == 0 || option == 1) {
            ClientRoom room = new ClientRoom(nickname, server, roomID);
            room.run();
            update(1);
            update(3);
        }
        else{
            if (option == 2) {
                update(4);
            } else {
                if (option == 3){
                    update(3);
                }
            }
        }
    }
}