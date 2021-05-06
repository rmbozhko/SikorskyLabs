import java.util.*;

public class insertionSort {

	public String[]	sort(String[] arr) {
		String temp;
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

	public static void main(String[] args) {
		List<String> arrayRandom = new ArrayList<>();
		Random rand = new Random();
		rand.setSeed(System.currentTimeMillis());
		for (int i = 9; i > 0; i--) {
			arrayRandom.add(new Integer(i).toString());
		}
		System.out.println(arrayRandom);
		insertionSort s = new insertionSort();
		System.out.println(Arrays.asList(s.sort(arrayRandom.toArray(new String[9]))));
	}
}