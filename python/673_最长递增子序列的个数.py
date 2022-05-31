class solution_673:
    def findNumberOfLIS(self,nums):
        n,max_l,ret=len(nums),0,0
        dp=[1]*n
        cnt=[1]*n
        for i,num in enumerate(nums):
            for j in range(i):
                if num>nums[j]:
                    if dp[j]+1>dp[i]:
                        dp[i]=dp[j]+1
                        cnt[i]=cnt[j]
                    elif dp[j]+1==dp[i]:
                        cnt[i]+=cnt[j]
            if dp[i]>max_l:
                max_l=dp[i]
                ret=cnt[i]
            elif dp[i]==max_l:
                ret+=cnt[i]
        return ret
if __name__ == '__main__':
    nums=eval(input("请输入一个数组"))
    print(nums)
    s673=solution_673()
    print("\n")
    print(s673.findNumberOfLIS(nums))




