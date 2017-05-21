package com.company.Server;

import com.company.Shared.IClient;
import java.rmi.RemoteException;
import java.util.ArrayList;

/**
 * Created by faraonul on 5/21/17.
 */
public class PrivateRoom extends Chat {

    public PrivateRoom(String roomID) {
        this.roomID = roomID;
        messages = new ArrayList<>();
        users = new ArrayList<>();
    }

    public void addUserToRoom(IClient client, int option) throws RemoteException {
        if (users.size() < 3) {
            if (!users.contains(client)) {
                users.add(client);
                notify(roomID, option);
            }
        }
    }

    public void notify(String roomID, int option) throws RemoteException {
        for (IClient client : users) {
            client.update(roomID, option);
        }
    }
}