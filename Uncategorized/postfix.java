import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String str[] = in.readLine().split(" ");
        Stack<Double> st = new Stack<>();
        double first, last;
        for(int i = 0; i < str.length; i++){
            switch(str[i]){
                case "+":
                    last = st.pop();
                    first = st.pop();
                    st.push(first + last);
                    break;
                case "-":
                    last = st.pop();
                    first = st.pop();
                    st.push(first - last);
                    break;
                case "*":
                    last = st.pop();
                    first = st.pop();
                    st.push(first * last);
                    break;
                case "/":
                    last = st.pop();
                    first =  st.pop();
                    st.push(first / last);
                    break;
                case "%":
                    last = st.pop();
                    first = st.pop();
                    st.push(first % last);
                    break;
                case "^":
                    last = st.pop();
                    first =st.pop();
                    st.push(Math.pow(first, last));
                    break;
                default:
                    st.push(Double.parseDouble(str[i]));
                    break;
            }
        }
        System.out.println(st.pop());
    }
}