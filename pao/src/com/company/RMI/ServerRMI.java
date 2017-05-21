package com.company.RMI;

import com.company.Server.Chat;
import com.company.Server.PrivateRoom;
import com.company.Server.SharedRoom;
import com.company.Shared.IClient;
import com.company.Shared.IServer;
import com.company.Shared.Message;
import com.sun.org.apache.xml.internal.security.keys.keyresolver.implementations.PrivateKeyResolver;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by faraonul on 5/21/17.
 */

public class ServerRMI extends UnicastRemoteObject implements IServer {
    protected Chat sharedChat;
    protected List<PrivateRoom> privateRooms;

    public ServerRMI() throws RemoteException {
        super();
        sharedChat = new SharedRoom();
        privateRooms = new LinkedList<>();
    }

    protected Chat getRoom(String roomID) throws RemoteException {
        if (roomID == null) {
            return sharedChat;
        } else {
            int i = 0;
            while(i < privateRooms.size() && privateRooms.get(i).getRoomID().compareTo(roomID) != 0) {
                i++;
            }

            if( i< privateRooms.size()) {
                return privateRooms.get(i);
            } else {
                return null;
            }
        }
    }

    @Override
    public String[] getMessages(String roomID) throws RemoteException {
        Chat room = getRoom(roomID);
        if (room != null) {
            List<Message> messages = room.getMessages();
            if (messages != null && messages.size() >= 1) {
                int length = messages.size();
                int i = 0;
                String[] text = new String[length];
                for(Message message : messages) {
                    text[i] = message.getText();
                    i++;
                }
                return text;
            }
        }
        return null;
    }

    @Override
    public void sendMessage(String message, String roomID) throws RemoteException {
        Chat room = getRoom(roomID);
        if (room != null) {
            room.addMessage(new Message(message));
        }
    }

    @Override
    public void addUser(String roomID, IClient user) throws RemoteException {
        Chat room = getRoom(roomID);
        if (room != null) {
            room.addUser(user);
        }
    }

    @Override
    public void removeUser(String roomID, IClient user) throws RemoteException {
        Chat room = getRoom(roomID);
        if(room != null) {
            if(roomID == null) {
                if(privateRooms.size() > 0) {
                    for(PrivateRoom privateRoom : privateRooms) {
                        if(privateRoom.getUsers().contains(user)) {
                            privateRoom.removeUser(user);
                            privateRoom.notify(privateRoom.getRoomID(), 2);
                        }
                    }
                }
            }
            room.removeUser(user);
        }
    }

    @Override
    public String[] getUsers(String roomID) throws RemoteException {
        Chat room = getRoom(roomID);
        if (room != null) {
            List<IClient> users = room.getUsers();
            if (users != null && users.size() >= 1) {
                int length = users.size();
                int i = 0;
                String[] names = new String[length];
                for(IClient aux : users) {
                    names[i] = aux.getNickName();
                    i++;
                }
                return names;
            }
        }
        return null;
    }

    @Override
    public boolean createNewRoom(String roomID) throws RemoteException {
        Chat room = getRoom(roomID);
        if(room == null) {
            privateRooms.add(new PrivateRoom(roomID));
            return true;
        }
        return false;
    }

    @Override
    public boolean removeRoom(String roomID) throws RemoteException {
        if(roomID != null) {
            PrivateRoom room = (PrivateRoom) getRoom(roomID);
            if (room != null) {
                privateRooms.remove(room);
                return true;
            }
        }
        return false;
    }

    @Override
    public void addUserToRoom(String roomID, String user, int option) throws RemoteException {
        IClient client = getUser(roomID);
        if(client != null) {
            PrivateRoom privateRoom = (PrivateRoom) getRoom(roomID);
            if(privateRoom.getRoomID() != null)
                privateRoom.addUserToRoom(client, option);
        }
    }

    protected IClient getUser(String user) throws RemoteException {
        List<IClient> users = sharedChat.getUsers();
        int i = 0;
        int length = users.size();
        while (i < length && users.get(i).getNickName().compareTo(user) !=0) {
            i++;
        }
        if (i < length) {
            return users.get(i);
        } else {
            return null;
        }
    }

    @Override
    public void sendPrivateMessage(String message, String roomID) throws RemoteException {
        PrivateRoom privateRoom = (PrivateRoom) getRoom(roomID);
        if(privateRoom != null) {
            privateRoom.addMessage(new Message(message));
            privateRoom.notify(roomID, 3);
        }
    }
}