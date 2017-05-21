package com.company.Shared;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * Created by faraonul on 5/21/17.
 */

public interface IClient extends Remote {
    public void update(int opc)throws RemoteException;
    public String[] getMessages(String roomID)throws RemoteException;
    public void sendMessage(String message, String roomID)throws RemoteException;
    public String getNickName()throws RemoteException;
    public void update(String roomID, int option)throws RemoteException;
}

