class Solution:

    def solve(self, mat, n, m, col):
        maxvalue = -1
        index = -1

        for i in range(n):
            if mat[i][col] > maxvalue:
                maxvalue = mat[i][col]
                index = i

        return index

    def findPeakGrid(self, mat):

        n = len(mat)
        m = len(mat[0])

        low = 0
        high = m - 1

        while low <= high:
            mid = (low + high) // 2

            mri = self.solve(mat, n, m, mid)

            left = mat[mri][mid - 1] if mid - 1 >= 0 else -1
            right = mat[mri][mid + 1] if mid + 1 < m else -1

            if mat[mri][mid] > left and mat[mri][mid] > right:
                return [mri, mid]

            elif mat[mri][mid] < left:
                high = mid - 1

            else:
                low = mid + 1

        return [-1, -1]