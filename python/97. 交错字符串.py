class Solution_97:
    def isInterleave(self,s1,s2,s3):
        m, n, k = len(s1), len(s2), len(s3)
        if (m + n != k): return False
        dp = [0] * (n + 1)
        dp[0] = True
        for i in range(m + 1):
            for j in range(n + 1):
                if i > 0:
                    dp[j] = dp[j] and s1[i - 1] == s3[i + j - 1]
                if j > 0:
                    dp[j] = dp[j] or (dp[j - 1] and s2[j - 1] == s3[i + j - 1])
        return dp[n]
if __name__ == '__main__':
    s1=input()
    # print(len(s1))
    s2=input()
    s3=input()
    s_97=Solution_97()
    if(s_97.isInterleave(s1,s2,s3)):
        print("True")
    else:
        print("False")
