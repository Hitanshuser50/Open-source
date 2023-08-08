#User function Template for python3

class Solution:
    def simplify(self, nu, de):
        A, B = nu, de
        while A != 0:
            rem = B % A
            B = A
            A = rem
        return nu//B, de//B

    def countFractions(self, n, numerator, denominator):
        ans = 0

        map = {}

        for i in range(n):
            a, b = self.simplify(numerator[i], denominator[i])

            frac = str(a) + ',' + str(b)
            sub = str(b-a) + ',' + str(b)

            if sub in map:
                ans += map[sub]

            if frac not in map:
                map[frac] = 1
            else:
                map[frac] += 1

        return ans

#{ 
 # Driver Code Starts

#Initial Template for Python 3

for _ in range(int(input())):
    n = int(input())
    numerator = list(map(int,input().split()))
    denominator = list(map(int,input().split()))
    ob = Solution()
    print(ob.countFractions(n,numerator,denominator))
# } Driver Code Ends