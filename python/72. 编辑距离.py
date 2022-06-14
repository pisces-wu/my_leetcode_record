class Solution_72:
    def minDistance(self,nums1,nums2):
        m,n=len(nums1),len(nums2)
        if m==0:
            return n
        if n==0:
            return m
        dp=[[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            dp[m][0]=m
        for j in range(1,n+1):
            dp[0][n]=n
        for i in range(1,m+1):
            for j in range(1,n+1):
                if(nums1[i-1]==nums2[j-1]):
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
        return dp[m][n]
if __name__ == '__main__':
    s_72=Solution_72()
    nums1=input("nums1")
    nums2=input("nums2")
    print(s_72.minDistance(nums1,nums2))
