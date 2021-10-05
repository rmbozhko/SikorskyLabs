package gauss;

import java.util.List;

import static gauss.Utils.*;

public class Algorithm {
    LinearSystem list;

    public Algorithm(LinearSystem system) {
        list = system;
    }

    public void forwardElimination() throws NullPointerException, ArithmeticException {
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                Float coefficient = calculateCoefficient(list.get(j).get(i),
                        list.get(i).get(i));
                list.get(j).setEquation(multiplyEquations(list.get(j).getEquation(), coefficient));
                list.get(j).setEquation(addEquations(list.get(j).getEquation(), list.get(i).getEquation()));
            }
        }
    }

    public List<Float> backSubstitution() {
        Float[] x = new Float[Utils.EQUATIONS_NUMBER];
        int i, j;
        for (i = list.size() - 1; i >= 0; i--) {
            Float sum = 0.0f;
            for (j = list.size() - 1; j > i; j--) {
                sum += list.get(i, j) * x[j];
            }
            x[i] = (list.get(i, list.size()) - sum) / list.get(i, j);
        }
        return List.of(x);
    }
}
