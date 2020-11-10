public class Lr21 {
    public double           task1(double x) {
        double  a;
        double  b;
        double  z;
        double  res;
        double  temp;

        a = 0.1;
        b = 3.25;
        z = Math.pow(Math.cos(x), 2.0);
        res = 0.0;
        if (x < a) {
            res = (a + z);
            temp = b * x + Math.pow(x, 3.0);
            res *= Math.pow(Math.cos(temp), 2.0);
        } else if (x >= a && x <= b) {
            res = a * Math.log10(z * x);
            temp = Math.pow(b, 2.0);
            res += Math.pow(Math.sin(temp), 2.0);
        } else if (x > b) {
            temp = a - Math.pow(z, 2.0);
            res = Math.sqrt(Math.abs(temp));
            res += 0.3 * b;
            res = Math.cbrt(res);
        }
        return (res);
    }

    public double           task2(double x, double b, double m, double n) {
        double      res;
        double      temp;

        res = 0.0;
        if (Math.abs(b * m) > Math.pow(x, 2.0)) {
            temp = n * x;
            res = Math.cos(temp);
            temp = b * m;
            res = temp + res;
            res = Math.sin(res);
        } else if (Math.abs(b * m) < Math.pow(x, 2.0)) {
            temp = b * m;
            res = temp - Math.sin(x);
            res = Math.cos(res);
        } else if (Math.abs(b * m) == Math.pow(x, 2.0)) {
            temp = b * m * x;
            temp = Math.sqrt(Math.abs(temp));
            res = Math.abs(Math.cos(x));
            res = Math.exp(res);
            res = Math.sqrt(res + temp);
        }
        return (res);
    }

    public static void      main(String[] args) {
        Lr21 temp = new Lr21();

        System.out.printf("%.4f\n",temp.task1(-2.3));
        System.out.printf("%.4f\n",temp.task1(0.6));
        System.out.printf("%.4f\n", temp.task1(4.8));

        System.out.printf("%.4f\n",temp.task2(-2.3, -1.6, 0.9, -1.4));
        System.out.printf("%.4f\n",temp.task2(-2.3, 4.5, -2, 2.2));
        System.out.printf("%.4f\n",temp.task2(-2.3, -4.5, 0.5, -1.5));

        System.out.printf("%.4f\n",temp.task2(0.6, -1.6, 0.9, -1.4));
        System.out.printf("%.4f\n",temp.task2(0.6, 4.5, -2, 2.2));
        System.out.printf("%.4f\n",temp.task2(0.6, -4.5, 0.5, -1.5));

        System.out.printf("%.4f\n",temp.task2(4.8, -1.6, 0.9, -1.4));
        System.out.printf("%.4f\n",temp.task2(4.8, 4.5, -2, 2.2));
        System.out.printf("%.4f\n",temp.task2(4.8, -4.5, 0.5, -1.5));
    }
}
