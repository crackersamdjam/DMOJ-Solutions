import java.util.Scanner;
public class CCC10J3 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = 0, b = 0;
        Outer:
        while(input.hasNext()){
            String str = input.nextLine();
            switch (str.charAt(0)) {
                case '1':
                    if(str.charAt(2)=='A'){
                        if(str.charAt(4)=='-'){
                            a = Integer.parseInt(str.substring(5));
                            a = a*-1;
                        }else{
                            a = Integer.parseInt(str.substring(4));
                        }
                    }
                    else{
                        if(str.charAt(4) == '-'){
                            b = Integer.parseInt(str.substring(5));
                            b = b*-1;
                        }else b = Integer.parseInt(str.substring(4));
                    }
                    break;
                case '2':
                    if(str.charAt(2)=='A') System.out.println(a);
                    else System.out.println(b);
                    break;
                case '3':
                    if(str.charAt(2)=='A'){
                        int temp1 = a;
                        if(str.charAt(4)=='A'){
                            a=temp1+a;
                        }else{
                            a=temp1+b;
                        }
                    }else{
                        int temp1 = b;
                        if(str.charAt(4)=='A'){
                            b=temp1+a;
                        }else{
                            b=temp1+b;
                        }
                    }
                    break;
                case '4':
                    if(str.charAt(2)=='A'){
                        int temp1 = a;
                        if(str.charAt(4)=='A'){
                            a=temp1*a;
                        }else{
                            a=temp1*b;
                        }
                    }else{
                        int temp1 = b;
                        if(str.charAt(4)=='A'){
                            b=temp1*a;
                        }else{
                            b=temp1*b;
                        }
                    }
                    break;
                case '5':
                    if(str.charAt(2)=='A'){
                        int temp1 = a;
                        if(str.charAt(4)=='A'){
                            a=temp1-a;
                        }else{
                            a=temp1-b;
                        }
                    }else{
                        int temp1 = b;
                        if(str.charAt(4)=='A'){
                            b=temp1-a;
                        }else{
                            b=temp1-b;
                        }
                    }
                    break;
                case '6':
                    if(str.charAt(2)=='A'){
                        int temp1 = a;
                        if(str.charAt(4)=='A'){
                            a=temp1/a;
                        }else{
                            a=temp1/b;
                        }
                    }else{
                        int temp1 = b;
                        if(str.charAt(4)=='A'){
                            b=temp1/a;
                        }else{
                            b=temp1/b;
                        }
                    }
                    break;
                case '7':
                    break Outer;
                default:
                    break;
            }
        }
    }
    
}