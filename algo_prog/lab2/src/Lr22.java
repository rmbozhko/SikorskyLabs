import java.util.Locale;
import java.util.Scanner;

public class Lr22 {
    interface readInput {
        double readInputArgument();
    }

    public double           task3(double a, double b, double c) {
        boolean cond_a = ((a <= b && a >= c) || (a >= b && a <= c));
        boolean cond_b = ((b >= a && b <= c) || (b >= c && b <= a));
        boolean cond_c = ((c >= a && c <= b) || (c >= b && c <= a));

        if (cond_a)
            return a;
        else if (cond_b)
            return b;
        else if (cond_c)
            return c;
        else
            return ((a + b + c) / 3.0);
    }

    public boolean           task4(double x, double y, double r) {
        double      temp;

        temp = Math.pow(x, 2.0) + Math.pow (y, 2.0);
        if (temp < Math.pow(r, 2.0))
            return Boolean.TRUE;
        else
            return Boolean.FALSE;
    }

    public static void      main(String[] args) {
        Lr22 temp = new Lr22();
        readInput reader = () -> {
            Scanner     scan;

            scan = new Scanner(System.in);
            scan.useLocale(Locale.US);
            while (true) {
                try {
                    System.out.print("Enter a number: ");
                    return scan.nextDouble();
                } catch (java.util.InputMismatchException e) {
                    System.out.println(e.getMessage());
                }
            }
        };

        System.out.printf("%.4f\n", temp.task3(reader.readInputArgument(), reader.readInputArgument(), reader.readInputArgument()));
        System.out.printf("%b\n", temp.task4(3, -7, 5));
        System.out.printf("%b\n", temp.task4(12, 11, 16));
        System.out.printf("%b\n", temp.task4(-9, 6, 11));
    }
}
