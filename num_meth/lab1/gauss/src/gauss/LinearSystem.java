package gauss;

import java.util.ArrayList;
import java.util.List;

public class LinearSystem {
    private final List<Equation> list = new ArrayList<>();

    public Equation get(int index) {
        return list.get(index);
    }

    public void push(Equation elem) {
        list.add(elem);
    }

    public int size() {
        return list.size();
    }

    public Float get(int i, int j) {
        return list.get(i).get(j);
    }
}
