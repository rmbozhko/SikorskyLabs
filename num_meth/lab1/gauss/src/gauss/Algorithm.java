package gauss;

import java.util.List;

public class Algorithm {
    LinearSystem<Float, Equation> list;

    public Algorithm(LinearSystem<Float, Equation> system) {
        list = system;
    }

    public void forwardElimination() throws NullPointerException, ArithmeticException {
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                Float coefficient = list.get(j).getCoefficient(list.get(j).at(i),
                                                    list.get(i).at(i));
                list.get(j).multiplyEquations(coefficient);
                list.get(j).addEquations(list.get(i));
            }
        }
    }

    public List<Float> backSubstitution() {
        Float[] x = new Float[Utils.DEFAULT_EQUATIONS_NUMBER];
        int i, j;
        for (i = list.size() - 1; i >= 0; i--) {
            Float sum = 0.0f;
            for (j = list.size() - 1; j > i; j--) {
                sum += list.itemAt(i, j) * x[j];
            }
            x[i] = (list.itemAt(i, list.size()) - sum) / list.itemAt(i, j);
        }
        return List.of(x);
    }
}
