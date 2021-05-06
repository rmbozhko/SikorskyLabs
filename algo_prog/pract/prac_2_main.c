int*	removeEven() {
	for (int i = 0; i < count; ++i)
		{
			if (even) {
				erase();
			}
		}
}

int*	removeDuplicates() {
	for (int i = 0; i < count; ++i)
	{
		for (int i = 0; i < count; ++i)
		{
			if (duplicate) {
				erase();
			}
		}
	}
}

int*	erase() {

}

int*	insert() {

}

int*	resize(int* arr, int& size) {
	int*	temp;

	temp = new int[size + 1];
	for (int i = 0; i < size; ++i) {
		temp[i] = arr[i];	
	}
	
	temp[++size] = 0;
	delete[] arr;
	return (temp);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}