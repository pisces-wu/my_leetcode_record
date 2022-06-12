import sys
class solution_53:
    def maxSubArray(self,nums):
        n=len(nums)
        if n<=0:
            return n
        if n==1:
            return nums[0]
        dp=[0]*n
        dp[0]=max(0,nums[0])
        ret=nums[0]
        for i in range(1,n):
            dp[i]=max(nums[i],nums[i]+dp[i-1])
            ret=max(ret,dp[i])
        return  ret
if __name__ == '__main__':
    nums=eval(input("输入一个列表"))
    s53=solution_53()
    print("\n")
    print(s53.maxSubArray(nums))