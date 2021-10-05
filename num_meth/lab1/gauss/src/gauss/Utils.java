package gauss;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Utils {
    public static final int EQUATIONS_NUMBER = 4;

    public static LinearSystem generateSystem() {
        LinearSystem list = new LinearSystem();
        List<Float> row = new ArrayList<>();

        row.add(3.81f);
        row.add(0.25f);
        row.add(1.28f);
        row.add(1.75f);
        row.add(4.21f);
        list.push(new Equation(row));
        row.clear();

        row.add(2.25f);
        row.add(1.32f);
        row.add(5.58f);
        row.add(0.49f);
        row.add(7.47f);
        list.push(new Equation(row));
        row.clear();

        row.add(5.31f);
        row.add(7.28f);
        row.add(0.98f);
        row.add(1.04f);
        row.add(2.38f);
        list.push(new Equation(row));
        row.clear();

        row.add(10.39f);
        row.add(2.45f);
        row.add(3.35f);
        row.add(2.28f);
        row.add(11.48f);
        list.push(new Equation(row));
        row.clear();

        return list;
    }

    public static void printSystem(LinearSystem system) {
        for (int i = 0; i < system.size(); i++) {
            Equation temp = system.get(i);
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < temp.size(); j++) {
                s.append(String.format("%f; %s", system.get(i, j), "\t"));
            }
            System.out.println(s);
        }
        System.out.println();
    }

    public static void printVector(List<Float> x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.size(); i++) {
            s.append(String.format("x%d = %f; ", i, x.get(i)));
        }
        System.out.println(s);
    }

    public static boolean checkSystem(LinearSystem system) {
        if (system.size() < 2) return false;
        for (int i = 0; i < system.size(); i++) {
            if (system.get(i).size() != (system.size() + 1)) {
                return false;
            }
        }
        return true;
    }

    public static Float calculateCoefficient(Float a, Float b) {
        if (a == 0.0f) return 1.0f;
        return -b / a;
    }


    public static List<Float> multiplyEquations(List<Float> equation, Float coefficient) {
        return equation.stream().map(elem -> elem * coefficient).collect(Collectors.toList());
    }

    public static List<Float> addEquations(List<Float> a, List<Float> b) {
        assert a.size() == b.size();

        List<Float> updatedEquation = new ArrayList<>(a.size());

        for (int i = 0; i < a.size(); i++) {
            updatedEquation.add(a.get(i) + b.get(i));
        }
        return updatedEquation;
    }

    public static double calculateRMSE(double[] actual, double[] predicted) {
        int n = actual.length;
        double sum = 0.0;
        double diff;
        for (int i = 0; i < n; i++) {
            diff = actual[i] - predicted[i];
            sum = sum + diff * diff;
        }
        double mse = sum / n;

        return Math.sqrt(mse);
    }
}
