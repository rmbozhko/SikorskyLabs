import gauss.Algorithm;
import gauss.LinearSystem;
import gauss.Equation;
import gauss.Utils;

import java.util.Arrays;
import java.util.List;

import static gauss.Utils.*;

public class Main {

    public static void main(String[] args) {
        LinearSystem list = generateSystem();
        printSystem(list);
        Algorithm alg = new Algorithm(list);

        try {
            if (!Utils.checkSystem(list)) {
                throw new ArithmeticException("Incorrect system for Gauss Method");
            }
            alg.forwardElimination();
            printSystem(list);
            List<Float> systemSolution = alg.backSubstitution();
            printVector(systemSolution);
            double[] actualSystemSolution = new double[]{0.94107373, -0.45285249, 1.1000052, -0.38301968};
            double rmse = calculateRMSE(systemSolution.stream().mapToDouble(Float::doubleValue).toArray(),
                    actualSystemSolution);
            System.out.println("Значення середньоквадратичної похибки: " + rmse);
        } catch (NullPointerException | ArithmeticException e) {
            System.out.println(e.getMessage());
            System.exit(0);
        }
    }
}
