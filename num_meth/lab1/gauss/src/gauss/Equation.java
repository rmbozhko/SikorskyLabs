package gauss;

import java.util.ArrayList;
import java.util.List;

public class Equation {

    private List<Float> equation;

    public List<Float> getEquation() {
        return equation;
    }

    public void setEquation(List<Float> equation) {
        this.equation = equation;
    }

    public Equation(List<Float> equation) {
        this.equation = new ArrayList<>();
        this.equation.addAll(equation);
    }

    public int size() {
        return equation.size();
    }

    public Float get(int index) {
        return equation.get(index);
    }
}
