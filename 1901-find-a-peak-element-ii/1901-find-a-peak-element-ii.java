class Solution {

    int solve(int[][] mat, int n, int m, int col) {
        int maxvalue = -1;
        int index = -1;

        for(int i = 0; i < n; i++) {
            if(mat[i][col] > maxvalue) {
                maxvalue = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    public int[] findPeakGrid(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int low = 0;
        int high = m - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            int mri = solve(mat, n, m, mid);

            int left = mid - 1 >= 0
                ? mat[mri][mid - 1] : -1;

            int right = mid + 1 < m
                ? mat[mri][mid + 1] : -1;

            if(mat[mri][mid] > left &&
               mat[mri][mid] > right) {
                return new int[]{mri, mid};
            }

            else if(mat[mri][mid] < left) {
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return new int[]{-1, -1};
    }
}