package com.company;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.AsynchronousSocketChannel;
import java.nio.channels.CompletionHandler;
import java.util.concurrent.Future;
import java.util.function.Function;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Client {

    private AsynchronousSocketChannel socketChannel;

    public void SayHi() {
        System.out.println("hey");
    }

    public Future<Void> Connect(String host, int port) throws IOException {
        //create a socket channel
        socketChannel = AsynchronousSocketChannel.open();
        //try to connect to the server side
        return socketChannel.connect(new InetSocketAddress(host, port));
    }

    private void startRead(final AsynchronousSocketChannel sockChannel) {
        final ByteBuffer buf = ByteBuffer.allocate(2048);

        sockChannel.read( buf, sockChannel, new CompletionHandler<Integer, AsynchronousSocketChannel>(){

            @Override
            public void completed(Integer result, AsynchronousSocketChannel channel) {
                //print the message
                System.out.println( "Read message:" + new String( buf.array()) );
            }

            @Override
            public void failed(Throwable exc, AsynchronousSocketChannel channel) {
                System.out.println( "fail to read message from server");
            }

        });

    }
    public Future<Integer> startWrite(final String message) {
        ByteBuffer buf = ByteBuffer.allocate(Config.BUFFER_SIZE);
        buf.put(message.getBytes());
        buf.flip();
        return socketChannel.write(buf);
    }

    public static void main(String[] args ) throws Exception {
                Client client = new Client();
                client.Connect(Config.HOST_NAME, Config.PORT).get();
                Future<Integer> boss = client.startWrite("BOSSULE");
                while (!boss.isDone()) {}
               // Thread.sleep(200);
    }

}