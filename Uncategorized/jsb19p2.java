//JSB p2
import java.lang.reflect.*;
import java.lang.instrument.*;
import java.lang.reflect.ReflectPermission;
import java.security.ProtectionDomain;
import java.security.*;

public class Main{

    public static void main(String[] args) throws Exception{
        System.setSecurityManager(new SecurityManager() {
            public void checkPermission(Permission perm){
            }
        });
        final SecurityManager sm = System.getSecurityManager();
        Class s = Class.forName("Secret");
        Object o= s.newInstance();
        Method m = s.getDeclaredMethod("flag");
        m.setAccessible(true);
        m.invoke(o);
    }
}
// javac Main.java && java -javaagent:p2_agent.jar Main