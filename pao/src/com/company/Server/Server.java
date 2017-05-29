package com.company.Server;

import com.company.RMI.ServerRMI;
import com.company.Shared.IServer;

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

/**
 * Created by faraonul on 5/21/17.
 */

public class Server {
    public Server() {
        try {
            IServer serverInterface = new ServerRMI();
            LocateRegistry.createRegistry(11111);
            Naming.rebind("rmi://localhost//Chat", serverInterface);
            System.out.println("Listening...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        new Server();
    }
}
