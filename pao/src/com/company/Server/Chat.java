package com.company.Server;

import com.company.Shared.IClient;
import com.company.Shared.Message;

import java.rmi.RemoteException;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by faraonul on 5/21/17.
 */

public abstract class Chat {
    protected List<Message> messages;
    protected List<IClient> users;
    protected String roomID;

    public void addMessage(Message message) throws RemoteException {
        messages.add(message);
        notify(3);
    }

    public LinkedList<Message> getMessages() {
        return getMessages();
    }

    public void addUser(IClient newUser) throws RemoteException {
        if(!users.contains(newUser)) {
            users.add(newUser);
            notify(1);
        }
    }

    public void notify(int option) throws RemoteException {
        for(IClient user : users)
            user.update(option);
    }

    public synchronized void removeUser(IClient user) throws RemoteException {
        if(users.contains(user)) {
            users.remove(user);
            notify(1);
        }
    }

    public String getRoomID() {
        return roomID;
    }

    public List<IClient> getUsers() {
        return users;
    }
}
