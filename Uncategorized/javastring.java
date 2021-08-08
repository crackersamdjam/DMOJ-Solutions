public class Main{

    public static void main(String[] args) throws Exception{
        //String str = System.console().readLine();
        String str = "", reg = "" + (char)106 + (char)97 + (char)118 + (char)97;
        byte[] buf = new byte[200];

        int n = System.in.read(buf);

        for(int i = 0; i < n; i++)
            str += (char)buf[i];
        
        System.out.print(str.replaceAll("(?i)"+reg, ""));
    }
}