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

	/*
		1. Objective function: f(i) is a number of distinct ways to reach i-th stair.
		2. Base cases: f(0) = 1, f(1) = 1, f(2) = 2
		3. Recurrence relation; f(n) = f(n - 1) + f(n - 2)
		4. Order of execution: Bottom-up
	*/
	static int 	climbingStairs(int n) {
		int[] arr;

		arr = new int[n + 1];
		if (n < 0) return (-1);
		if (n >= 0) arr[0] = 1;
		if (n >= 1) arr[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}

		return arr[n];	
	}

	public static void main(String[] args) {
		/*
		System.out.println("Sum for elements of 0: " + sum(0));
		System.out.println("Sum for elements of 1: " + sum(1));
		System.out.println("Sum for elements of 2: " + sum(2));
		System.out.println("Sum for elements of 15: " + sum(15));
		System.out.println("Sum for elements of 150: " + sum(150));
		System.out.println("Sum for elements of 1500: " + sum(1500));
		System.out.println("Sum for elements of 15000: " + sum(15000));
		*/

		System.out.println("Number of ways to get to stair #0: " + climbingStairs(0));
		System.out.println("Number of ways to get to stair #1: " + climbingStairs(1));
		System.out.println("Number of ways to get to stair #2: " + climbingStairs(2));
		System.out.println("Number of ways to get to stair #3: " + climbingStairs(3));
		System.out.println("Number of ways to get to stair #5: " + climbingStairs(5));
		System.out.println("Number of ways to get to stair #150: " + climbingStairs(150));
		System.out.println("Number of ways to get to stair #1500: " + climbingStairs(1500));
		System.out.println("Number of ways to get to stair #15000: " + climbingStairs(15000));
	}
}