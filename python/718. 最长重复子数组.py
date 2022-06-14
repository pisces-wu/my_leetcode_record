class Solution_718:
    def findLength(self,nums1,nums2):
        m,n=len(nums1),len(nums2)
        if(m==0 or n==0):
            return 0
        dp=[[0]*(n+1) for _ in range(m+1)]
        ret=0
        for i in range(1,m+1):
            for j in range(1,n+1):
                if(nums1[i-1]==nums2[j-1]):
                    dp[i][j]=dp[i-1][j-1]+1
                    ret=max(dp[i][j],ret)
        return  ret
if __name__ == '__main__':
    nums1=eval(input("数组nums1"))
    nums2=eval(input("数组nums2"))
    s_718=Solution_718()
    print(s_718.findLength(nums1,nums2))
