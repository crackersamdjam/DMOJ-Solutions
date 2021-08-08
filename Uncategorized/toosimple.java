public class Main {
    static int num;
    public static void main(String[] args) {
        int one = Integer.MAX_VALUE/Integer.MAX_VALUE;
        int two = one + one;
        int four = two*two;
        int eight = four*two;
        int sixteen = eight*two;
        int thirtytwo = sixteen*two;
        int sixtyfour = thirtytwo*two;
        System.out.print((char)(sixtyfour + eight));
        System.out.print((char)(sixtyfour*two - thirtytwo + four + one));
        System.out.print((char)(sixtyfour*two - thirtytwo + four + eight));
        System.out.print((char)(sixtyfour*two - thirtytwo + four + eight));
        System.out.print((char)(sixtyfour*two - thirtytwo + four + eight + two + one));
        System.out.print((char)(thirtytwo+eight+four));
        System.out.print((char)(thirtytwo));
        System.out.print((char)(sixtyfour + sixteen + four + two + one));
        System.out.print((char)(sixtyfour*two - thirtytwo + four + eight + two + one));
        System.out.print((char)(sixtyfour*two - thirtytwo + four + eight + two + four));
        System.out.print((char)(sixtyfour*two - thirtytwo + four + eight));
        System.out.print((char)(sixtyfour*two - thirtytwo + four));
        System.out.print((char)(thirtytwo+one));
    }
}