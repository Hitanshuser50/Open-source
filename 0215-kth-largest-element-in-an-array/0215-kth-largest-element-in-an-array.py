class Solution:
    def findKthLargest(self, nums: List[int], t: int) -> int:
        def quickslect(A, k):
            P = random.choice(A)
            L, R = [a for a in A if a < P], [a for a in A if a > P]
            if len(R) >= k:
                return quickslect(R, k)
            elif len(A)-len(L) >= k:
                return P
            else:
                return quickslect(L, k - (len(A) - len(L)))

        return quickslect(nums, t)