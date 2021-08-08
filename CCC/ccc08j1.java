import java.util.Scanner;
public class CCC08J1 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double w = input.nextDouble();
        double h = input.nextDouble();
        Double bmi = w/(h*h);
        if(bmi > 25){
            System.out.println("Overweight");
        }else if(bmi < 18.5){
            System.out.println("Underweight");
        }else{
            System.out.println("Normal weight");
        }
    }
    
}