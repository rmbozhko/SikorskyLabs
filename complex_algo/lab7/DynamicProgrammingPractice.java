public class DynamicProgrammingPractice {

	/*
	* Find the sum of first N numbers.
	* Objective function: f(i) is the sum of the first i elements
	* Recurrence objective: f(n) = f(n - 1) + n
	*/
	static int 	sum(int n) {
		int[] arr;

		arr = new int[n + 1];
		arr[0] = 0;
		
		for (int i = 1; i <= n; i++) {
			arr[i] = arr[i - 1] + i;
		}

		return arr[n];
	}

	public static void main(String[] args) {
		System.out.println("Sum for elements of 0: " + sum(0));
		System.out.println("Sum for elements of 1: " + sum(1));
		System.out.println("Sum for elements of 2: " + sum(2));
		System.out.println("Sum for elements of 15: " + sum(15));
		System.out.println("Sum for elements of 150: " + sum(150));
		System.out.println("Sum for elements of 1500: " + sum(1500));
		System.out.println("Sum for elements of 15000: " + sum(15000));
	}
}