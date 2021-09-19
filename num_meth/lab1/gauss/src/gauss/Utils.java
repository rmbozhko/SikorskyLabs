package gauss;

import java.util.ArrayList;
import java.util.List;

public class Utils {
    public static final int DEFAULT_EQUATIONS_NUMBER = 4;

    public static LinearSystem<Float, Equation> generateSystem(){
        LinearSystem<Float, Equation> list = new LinearSystem<>();
        List<Float> row = new ArrayList<>();

        row.add(3.81f); row.add(0.25f); row.add(1.28f); row.add(1.75f); row.add(4.21f);
        list.push(new Equation(row));
        row.clear();

        row.add(2.25f); row.add(1.32f); row.add(5.58f); row.add(0.49f); row.add(7.47f);
        list.push(new Equation(row));
        row.clear();

        row.add(5.31f); row.add(7.28f); row.add(0.98f); row.add(1.04f); row.add(2.38f);
        list.push(new Equation(row));
        row.clear();

        row.add(10.39f); row.add(2.45f); row.add(3.35f); row.add(2.28f); row.add(11.48f);
        list.push(new Equation(row));
        row.clear();

        return list;
    }

    public static void printSystem(LinearSystem<Float, Equation> system){
        for (int i = 0; i < system.size(); i++){
            Equation temp = system.get(i);
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < temp.size(); j++){
                s.append(String.format("%f; %s", system.itemAt(i, j), "\t"));
            }
            System.out.println(s);
        }
        System.out.println();
    }

    public static void printVector(List<Float> x){
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.size(); i++){
            s.append(String.format("x%d = %f; ", i, x.get(i)));
        }
        System.out.println(s);
    }

    public static boolean checkSystem(LinearSystem<Float, Equation> system){
        if (system.size() < 2) return false;
        for(int i = 0; i < system.size(); i++){
            if (system.get(i).size() != (system.size() + 1)){
                return false;
            }
        }
        return true;
    }
}
