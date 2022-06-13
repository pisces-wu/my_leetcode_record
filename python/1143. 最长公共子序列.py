class Solution_1143:
    def longestCommonSubsequence(self,text1,text2):
        m,n=len(text1),len(text2)
        if(m==0 or n==0):
            return 0
        dp=[[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                if(text1[i-1]==text2[j-1]):
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        return dp[m][n]
if __name__ == '__main__':
    text1=input("text1")
    # print(text1)
    text2=input("text2")
    s_1143=Solution_1143()
    print(s_1143.longestCommonSubsequence(text1,text2))