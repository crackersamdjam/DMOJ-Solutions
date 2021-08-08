import java.util.Scanner;
public class CCC08J2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        char[] list = {'A', 'B', 'C', 'D', 'E'};
        boolean end = false;
        OUTER:
        while (!end) {
            int in = input.nextInt();
            int n = input.nextInt();
            for(int j = 0; j < n; j++){
            switch (in) {
                case 1:
                    {
                        char temp = list[0];
                        for(int i = 1; i < list.length;i++){
                            list[i-1] = list[i];
                        }       list[list.length-1] = temp;
                        break;
                    }
                case 2:
                    {
                        char temp = list[list.length-1];
                        for(int i = list.length-1; i > 0 ;i--){
                            list[i] = list[i-1];
                        }       list[0] = temp;
                        break;
                    }
                case 3:
                    {
                        char temp = list[0];
                        list[0] = list [1];
                        list[1] = temp;
                        break;
                    }
                case 4:
                    for(int i = 0; i < list.length; i++){
                        System.out.print(list[i] + " ");
                    }
                    end = true;
                    break OUTER;
            }
        }
        }
    }
    
}