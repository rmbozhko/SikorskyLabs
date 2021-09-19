import gauss.Algorithm;
import gauss.LinearSystem;
import gauss.Equation;
import gauss.Utils;

import static gauss.Utils.*;

public class Main {

    public static void main(String[] args){
        LinearSystem<Float, Equation> list = generateSystem();
        printSystem(list);
        Algorithm alg = new Algorithm(list);

        try {
            if (!Utils.checkSystem(list)) {
                throw new ArithmeticException("Incorrect system for Gauss Method");
            }
            alg.forwardElimination();
            printSystem(list);
            printVector(alg.backSubstitution());
        } catch (NullPointerException | ArithmeticException e){
            System.out.println(e.getMessage());
            System.exit(0);
        }
    }
}
