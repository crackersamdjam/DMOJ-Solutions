import java.lang.reflect.*;


public class Main{

    public static void main(String[] args) throws Exception{

        Class s = Class.forName("Secret");
        Object o= s.newInstance();
        Method m = s.getDeclaredMethod("flag");
        m.setAccessible(true);
        m.invoke(o);
    }
}
// javac Main.java
// java -javaagent:p1_agent.jar Main