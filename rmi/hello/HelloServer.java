import java.rmi.*;
import java.rmi.registry.*;
import java.rmi.server.*;
import java.net.*;

public class HelloServer
{
    public HelloServer() throws RemoteException
    { 
        try
        {
            // Default port: 1099
            //Registry registry = LocateRegistry.createRegistry(1099);
            //Registry registry = LocateRegistry.createRegistry(2020);
            
            Naming.rebind("Hello", new Hello ("Hello from JB"));
            //Naming.rebind("//127.0.0.1:2020/Hello", new Hello ("Hello from JB"));
            
            System.out.println("Server is connected and ready for operation");
        }
        catch (Exception e)
        {
            System.out.println("Server not connected: " + e);
        }
    }
    
    public static void main(String[] args)
    {
        try
        {
            HelloServer s = new HelloServer();
        }
        catch(Exception e)
        {
            e.printStackTrace();
            System.exit(1);
        }
    }
}

// steps to run:
// 1. run `rmiregistry [port]' // port is optional
// 2. java -Djava.security.policy=policy HelloServer
//
// to enable remote access, inform IP from the server
// 2. java -Djava.security.policy=policy -Djava.rmi.server.hostname=10.142.74.143 HelloServer
//
// to automatically obtain the ip (OBS.: check the command first):
// 2. java -Djava.security.policy=policy -Djava.rmi.server.hostname=$(hostname -I | cut -d' ' -f1) HelloServer

