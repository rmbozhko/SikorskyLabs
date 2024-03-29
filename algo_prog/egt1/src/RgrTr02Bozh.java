import java.util.InputMismatchException;
import java.util.Locale;
import java.util.Scanner;

public class RgrTr02Bozh {
    interface readInput {
        int readInputArgument();
    }
    private final static int n = 10;

    private static double           task1() {
        double  outer_var;

        outer_var = 0.0;
        for (int k = 0; k <= n; k++) {
            if (k == 5) // divisor is 0 in case k = 5
                continue;
            double  in_var;

            in_var = 1.0;
            for (int i = 1; i <= (k + 1); i++) {
                if (i == 4) // divisor is 0 in case i = 4
                    continue;
                double temp;

                temp = Math.pow(i, 2);
                temp -= 16.0;
                in_var *= i / temp;
            }
            outer_var += (Math.pow(-2, k + 1) * in_var) / (k - 5);
        }
        return (outer_var);
    }

    private static int              task2(int n) {
        int     res;

        res = 0;
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                res += (i == (n / i)) ? i : (i + (n / i));
            }
        }
        return (res);
    }

    public static void              main(String[] args) {
        double      eq_res;

        eq_res = task1();
        System.out.printf("Result of equation: %.4f\n", eq_res);
        readInput temp = () -> {
            Scanner     scan;
            int         arg;

            scan = new Scanner(System.in);
            scan.useLocale(Locale.US);
            while (true) {
                try {
                    System.out.print("Enter natural number: ");
                    arg = scan.nextInt();
                    if (arg == Integer.MAX_VALUE || arg < 1) {
                        throw new InputMismatchException("Inappropriate value was passed");
                    }
                    return arg;
                } catch (java.util.InputMismatchException e) {
                    System.out.println(e.getMessage());
                }
            }
        };

       for (int i = 0, div_sum; i < 3; i++) {
                div_sum = task2(temp.readInputArgument());
                System.out.printf("Sum of passed parameter divisors: %d\n", div_sum);
        }
    }
}
