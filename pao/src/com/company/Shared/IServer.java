package com.company.Shared;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * Created by faraonul on 5/21/17.
 */

public interface IServer extends Remote {
    public String[] getMessages(String roomID) throws RemoteException;
    public void sendMessage(String message, String roomID) throws RemoteException;
    public void addUser(String roomID, IClient user) throws RemoteException;
    public void removeUser(String roomID, IClient user) throws RemoteException;
    public String[] getUser(String roomID) throws RemoteException;
    public boolean createNewRoom(String roomID) throws RemoteException;
    public boolean removeRoom(String roomID) throws RemoteException;
    public void addUserToRoom(String roomID, String user, int opc) throws RemoteException;
    public void sendPrivateMessage(String message, String roomID)throws RemoteException;
}
