package gauss;

public interface Gauss<N extends Number, T extends Gauss<N, T>> {
    void addEquations(T item);
    void multiplyEquations(N coefficient);
    N getCoefficient(N a, N b);
    N at(int index);
    int size();
}