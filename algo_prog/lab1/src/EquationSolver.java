import java.text.SimpleDateFormat;
import java.util.Locale;
import java.util.Scanner;
import java.util.Date;


public class EquationSolver {
    private double      a;
    private double      b;
    private double      x;
    private double      y;
    private double      d;

    public void setA(double a) {
        if (a <= 0.0)
            throw new IllegalArgumentException("Argument 'a' equals or less than 0");
        this.a = a;
    }

    public void setB(double b) {
        this.b = b;
    }

    public void setX(double x) {
        if (x == 0.0 | x == (Math.PI/2))
            throw new IllegalArgumentException("Argument 'x' equals to 0 or Pi/2");
        this.x = x;
    }

    private void setY(double y) {
        this.y = y;
    }

    private void setD(double d) {
        this.d = d;
    }

    public double getA() {
        return this.a;
    }

    public double getB() {
        return this.b;
    }

    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
    }

    public double getD() {
        return this.d;
    }

    public void     calculateY() {
        double      temp;

        temp = this.getB() * (Math.tan(this.getX())) * (Math.tan(this.getX()));
        temp -= this.getA() / (Math.sin(this.getX()/this.getA()) * Math.sin(this.getX()/this.getA()));
        this.setY(temp);
    }

    public void     calculateD() {
        double      temp;

        temp = this.getA() * Math.exp(-Math.sqrt(this.getA()));
        temp *= Math.cos((this.getB() * this.getX()) / this.getA());
        this.setD(temp);
    }

    public double   readInputArgument(char arg_name) {
        Scanner     scan;
        double      temp;

        scan = new Scanner(System.in);
        scan.useLocale(Locale.US);
        while (true) {
            try {
                System.out.printf("Enter value for argument %c:", arg_name);
                temp = scan.nextDouble();
                return temp;
            } catch (java.util.InputMismatchException e) {
                scan.next();
            }
        }
    }

    public void     readInput() {
        this.setA(this.readInputArgument('a'));
        this.setB(this.readInputArgument('b'));
        this.setX(this.readInputArgument('x'));
    }

    public void    calculateInput() {
        this.readInput();
        this.calculateY();
        this.calculateD();
        System.out.println(this);
    }

    public void     displayDate() {
        Date date = new Date();
        String format = new SimpleDateFormat("MMMM dd yyyy E", new Locale("uk", "UA")).format(date);
        System.out.println(format);
    }

    @Override
    public String toString() {
        return "a=" + this.getA() +
                ", b=" + this.getB() +
                ", x=" + this.getX() +
                ", y=" + this.getY() +
                ", d=" + this.getD();
    }
}
