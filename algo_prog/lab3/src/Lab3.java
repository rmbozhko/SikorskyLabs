import java.util.Locale;
import java.util.Scanner;

public class Lab3 {
    interface readInput {
        double readInputArgument();
    }

    static public class Factorial {
        private Factorial() {}

        static public int   factorial(int i) throws IllegalArgumentException {
            int  result;

            result = 1;
            if (i < 0)
                throw new IllegalArgumentException("Argument is less than zero");
            while (i > 0) {
                result *= i;
                i -= 1;
            }
            return (result);
        }
    }

    public void     task1(double start, double end, double h) {
        System.out.println("  x | y(x) |  z(x)  ");
        for (double x = start; x <= end; x += h) {
            double temp = 3 * (x - 0.6);
            System.out.printf("%3.1f|%6.4f|%6.4f\n", x, Math.exp(temp), Math.asin(x));
        }
    }

    public boolean  task2(double[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (i + 1 < arr.length && arr[i] < arr[i + 1])
                return Boolean.FALSE;
        }
        return Boolean.TRUE;
    }

    public double   task3(double x) {
        double result;

        result = 0.0;
        for (double i = 1.0; i <= 10.0; i += 1.0) {
            double numerator_temp = Math.pow(-1.0, i + 1.0);
            numerator_temp *= Factorial.factorial((int)i);
            double delimiter_temp = Math.pow(2.0, (2.0 * i - 1.0));
            delimiter_temp *= Math.sin(x);
            result += numerator_temp / delimiter_temp;
        }
        return (result);
    }

    public static void main(String[] args) {
        Lab3 test = new Lab3();
        double[] arr_1 = new double[]{5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5};
        double[] arr_2 = new double[]{78.2, 2.5, -2.1, 28.2, -49, 17.14, 8.7, -57, 8.2, 80.104};

        test.task1(-1.0, 1.0, 0.05);
        System.out.printf("Послідовність впорядкована за спаданням: %b\n", test.task2(arr_1));
        System.out.printf("Послідовність впорядкована за спаданням: %b\n", test.task2(arr_2));
        readInput reader = () -> {
            Scanner scan;
            double arg;

            scan = new Scanner(System.in);
            scan.useLocale(Locale.US);
            while (true) {
                try {
                    System.out.print("Enter a number: ");
                    arg = scan.nextDouble();
                    return arg;
                } catch (java.util.InputMismatchException e) {
                    System.out.println("Invalid input. Try again.");
                    scan.nextLine();
                }
            }
        };
        System.out.printf("%.4f\n", test.task3(reader.readInputArgument()));
        System.out.printf("%.4f\n", test.task3(reader.readInputArgument()));
    }
}
