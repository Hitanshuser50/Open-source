class Solution:
    def kWeakestRows(self, matrix, k) -> list[int]:
        # Using a min heap to store tuples of the sum of soldiers and their respective row indices
        min_heap = []

        # Calculate the sum of soldiers for each row and store in the min heap
        for row in range(len(matrix)):
            soldier_count = self.find_soldier_count(matrix[row])
            heapq.heappush(min_heap, (soldier_count, row))

        # Extract the k weakest row indices
        weakest_rows = []
        for i in range(k):
            weakest_rows.append(heapq.heappop(min_heap)[1])

        return weakest_rows

    def find_soldier_count(self, row):
        left, right = 0, len(row) - 1

        # Perform binary search to find the count of soldiers
        while left <= right:
            mid = (left + right) // 2
            if row[mid] == 1:
                left = mid + 1
            else:
                right = mid - 1

        return left