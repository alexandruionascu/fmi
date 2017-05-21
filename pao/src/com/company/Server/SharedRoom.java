package com.company.Server;
import java.util.ArrayList;

/**
 * Created by faraonul on 5/21/17.
 */
public class SharedRoom extends Chat{

    public SharedRoom() {
        roomID = null;
        messages = new ArrayList<>();
        users = new ArrayList<>();
    }
}
