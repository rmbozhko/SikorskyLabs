import java.util.*;

public class Sort {

	public String[]	shellSort(String[] arr) {
		
	}

	public String[]	insertionSort(String[] arr) {
		String temp;
		System.out.println("insertionSort");
		for (int i = 1; i < arr.length; i++) {
			for (int j = i; j > 0 && (arr[j].compareTo(arr[j - 1]) < 0); j--) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			System.out.println(Arrays.asList(arr));
		}
		return arr;
	}

	public String[]	bubbleSort(String[] arr) {
		String 	temp;
		boolean	swapped;

		System.out.println("bubbleSort");
		swapped = false;
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length - 1; j++) {
				if (arr[j].compareTo(arr[j + 1]) > 0) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					swapped = true;
				}
			}
			if (!swapped) { break; }
			System.out.println(Arrays.asList(arr));
		}
		return arr;
	}
	
	public String[]	cocktailSort(String[] arr) {
		String 	temp;
		int 	right;
		int 	left;
		int 	last_swap;

		System.out.println("cocktailSort");
		left = 0;
		right = arr.length - 1;

		while (left < right) {
			last_swap = 0;
			for (int i = left; i < right; i++) {
				if (arr[i].compareTo(arr[i + 1]) > 0) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					last_swap = i;
				}
			}
			
			right = last_swap;
			for (int i = right; i > left; i--) {
				if (arr[i].compareTo(arr[i - 1]) < 0) {
					temp = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = temp;
					last_swap = i;
				}
			}
			left = last_swap;
		}

		return arr;
	}

	public static void main(String[] args) {
		List<String> arrayRandom = new ArrayList<>();
		Random rand = new Random();
		rand.setSeed(System.currentTimeMillis());
		int size = 4;
		for (int i = size; i > 0; i--) {
			arrayRandom.add(new Integer(i).toString());
		}
		// 2 4 1 3 -> 2 1 4 3 -> 1 2 4 3 -> 1234
		// arrayRandom.add(new Integer(2).toString());
		// arrayRandom.add(new Integer(4).toString());
		// arrayRandom.add(new Integer(1).toString());
		// arrayRandom.add(new Integer(3).toString());
		System.out.println(arrayRandom);
		Sort s = new Sort();
		// System.out.println(Arrays.asList(s.insertionSort(arrayRandom.toArray(new String[9]))));
		System.out.println(Arrays.asList(s.bubbleSort(arrayRandom.toArray(new String[size]))));
		// System.out.println(Arrays.asList(s.cocktailSort(arrayRandom.toArray(new String[9]))));
	}
}