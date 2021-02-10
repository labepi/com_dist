import java.rmi.*;

public class HelloClient
{
    public static void main(String[] args)
    {
        try
        {
            // local connection
            //HelloInterface hello = (HelloInterface) Naming.lookup("//127.0.0.1/Hello");
            
            // local connection with port
            // syntax of the service: //host:port/name
            HelloInterface hello = (HelloInterface) Naming.lookup("//127.0.0.1:2020/Hello");
            
            System.out.println(hello.say());
        }
        catch(Exception e)
        {
            System.out.println("HelloClient exception: " + e);
        }
        
    }
}

// steps to run:
// 1. java -Djava.security.policy=policy HelloClient
