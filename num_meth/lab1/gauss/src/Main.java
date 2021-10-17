import lab1.GaussianElimination;
import lab1.LinearSystem;
import lab1.Utils;

import java.util.List;

import static lab1.Utils.*;

public class Main {

    public static void main(String[] args) {
        LinearSystem system = generateSystem();
        System.out.println(system);
        GaussianElimination eliminator = new GaussianElimination(system);

        try {
            eliminator.forwardElimination();
            System.out.println(system);
            List<Float> systemSolution = eliminator.backSubstitution();
            printVector(systemSolution);
            double[] actualSystemSolution = new double[]{0.94107373, -0.45285249, 1.1000052, -0.38301968};
            double rmse = calculateRMSE(systemSolution.stream().mapToDouble(Float::doubleValue).toArray(),
                    actualSystemSolution);
            System.out.println("Значення середньоквадратичної похибки: " + rmse);
        } catch (NullPointerException | ArithmeticException e) {
            System.out.println(e.getMessage());
            System.exit(1);
        }
    }
}
