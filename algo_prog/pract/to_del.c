int             task7(int arr[][10]) {
        int     result;
        int     i;
        int     j;

        result = 1;
        for (i = 0, j = 0; i < 5 && j < 10; i++, j++) {
                if (arr[i][j] != 0) {
                        result *= arr[i][j];
                }
                if (arr[i][10 - j] != 0 && i != 2) {
                        result *= arr[i][j];
                }
        }
        
        return (result);
}
