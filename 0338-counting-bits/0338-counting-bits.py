class Solution:
    def countBits(self, n: int) -> List[int]:
        def hamming_weight(n: int) -> int:
            count = 0
            for i in range(0, 33):
                if n & 1 << i != 0:
                    count += 1
            return count
        scr = [0 for i in range(n+1)]
        for i in range(len(scr)):
            scr[i] = hamming_weight(i)
        return scr