class Solution_115:
    def numDistinct(self,s,p):
        m, n = len(s), len(t)
        if (m == 0 or n == 0): return 0
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, m + 1):
            for j in range(n, 0, -1):
                if (s[i - 1] == t[j - 1]):
                    dp[j] += dp[j - 1]
        return dp[n]
if __name__ == '__main__':
    s=input()
    t=input()
    s_115=Solution_115()
    print(s_115.numDistinct(s,t))