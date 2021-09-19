package gauss;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;
import java.util.stream.Collectors;

public class Equation implements Gauss<Float, Equation> {

    private List<Float> equation;

    public List<Float> getEquation(){
        return equation;
    }

    public Equation(List<Float> equation) {
        this.equation = new ArrayList<>();
        this.equation.addAll(equation);
    }

    @Override
    public int size(){
        return equation.size();
    }

    @Override
    public void addEquations(Equation item){
        ListIterator<Float> i = equation.listIterator();
        ListIterator<Float> j = item.getEquation().listIterator();
        while (i.hasNext() && j.hasNext()) {
            Float a = i.next();
            Float b = j.next();
            i.set(a + b);
        }

    }

    @Override
    public void multiplyEquations(Float coefficient){
        equation = equation.stream().map(elem -> elem * coefficient).collect(Collectors.toList());
    }

    @Override
    public Float getCoefficient(Float a, Float b){
        if (a == 0.0f) return 1.0f;
        return -b/a;
    }

    @Override
    public Float at(int index){
        return equation.get(index);
    }
}
