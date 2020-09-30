public class EquationSolverTest {
    public static void main(String[] args) {
        try {
            EquationSolver test = new EquationSolver();
            test.setA(3.2);
            test.setB(17.5);
            test.setX(-4.8);
            test.calculateY();
            test.calculateD();
            System.out.println(test);
            test.calculateInput();
            test.displayDate();
        } catch (IllegalArgumentException e) {
            System.out.println("Illegal argument was passed");
        }
    }
}

