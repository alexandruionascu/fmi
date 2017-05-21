package com.company.RMI;

import com.company.Shared.IClient;
import com.company.Shared.IServer;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

/**
 * Created by faraonul on 5/21/17.
 */

public abstract class ClientRMI extends UnicastRemoteObject implements IClient {
    protected final IServer server;
    protected String nickname;

    public ClientRMI(String nickname, IServer server) throws RemoteException {
        super();
        this.server = server;
        this.nickname = nickname;
    }

    @Override
    public String[] getMessages(String roomID) throws RemoteException {
        return server.getMessages(roomID);
    }

    @Override
    public void sendMessage(String message, String roomID) throws RemoteException {
        server.sendMessage(nickname+" >> " + message, roomID);
    }

    @Override
    public String getNickName() throws RemoteException {
        return nickname;
    }

    @Override
    public abstract void update(int option) throws RemoteException;

    @Override
    public abstract void update(String roomID, int option) throws RemoteException;
}

