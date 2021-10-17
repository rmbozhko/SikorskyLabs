package lab1;

import java.util.ArrayList;
import java.util.List;

public class LinearSystem {
    private final List<Equation> system = new ArrayList<>();

    public Equation get(int index) {
        return system.get(index);
    }

    public void push(Equation elem) {
        system.add(elem);
    }

    public int size() {
        return system.size();
    }

    public Float get(int i, int j) {
        return system.get(i).get(j);
    }

    @Override
    public String toString() {
        StringBuilder system = new StringBuilder();
        for (int i = 0; i < size(); i++) {
            Equation temp = get(i);
            for (int j = 0; j < temp.size(); j++) {
                system.append(String.format("%f; %s", get(i, j), "\t"));
            }
            system.append("\n");
        }
        return system.toString();
    }
}
