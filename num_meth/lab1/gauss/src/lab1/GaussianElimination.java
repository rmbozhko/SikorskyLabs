package lab1;

import java.util.List;

import static lab1.Utils.*;

public class GaussianElimination {
    LinearSystem equations;

    public GaussianElimination(LinearSystem system) {
        equations = system;
    }

    public void forwardElimination() throws NullPointerException, ArithmeticException {
        for (int i = 0; i < equations.size() - 1; i++) {
            for (int j = i + 1; j < equations.size(); j++) {
                Float coefficient = calculateCoefficient(equations.get(j, i), equations.get(i, i));
                equations.get(j).setEquation(multiplyEquationByConstant(equations.get(j), coefficient));
                equations.get(j).setEquation(addEquations(equations.get(j), equations.get(i)));
            }
        }
    }

    public List<Float> backSubstitution() {
        Float[] x = new Float[Utils.EQUATIONS_NUMBER];
        for (int i = equations.size() - 1, j; i >= 0; i--) {
            Float sum = 0.0f;
            for (j = equations.size() - 1; j > i; j--) {
                sum += equations.get(i, j) * x[j];
            }
            x[i] = (equations.get(i, equations.size()) - sum) / equations.get(i, j);
        }
        return List.of(x);
    }
}
