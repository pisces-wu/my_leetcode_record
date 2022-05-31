class solution_152:
    def maxProduct(self,nums):
        n=len(nums)
        if n<=0:
            return n
        if n==1:
            return nums[0]
        max_pre, min_pre, cur_max, cur_min = 1, 1, 1, 1
        ret=nums[0]
        for i in range(n):
            '''
            a,b=cur_max,cur_min
            cur_max=max(max_pre*nums[i],min_pre*nums[i],nums[i])
            cur_min=min(min_pre*nums[i],max_pre*nums[i],nums[i])
            max_pre,min_pre=a,b
            '''
            #cur_max,cur_min,max_pre,min_pre=max(max_pre*nums[i],min_pre*nums[i],nums[i]),min(min_pre*nums[i],max_pre*nums[i],nums[i]),cur_max,cur_min
            cur_max, cur_min = max(max_pre * nums[i], min_pre * nums[i], nums[i]), min( min_pre * nums[i], max_pre * nums[i], nums[i])
            max_pre,min_pre=cur_min,cur_min
            ret=max(ret,cur_max)
        return ret
if __name__ == '__main__':
    nums=eval(input("请输入一个列表"))
    #print(type(nums))
    s152=solution_152()
    print('\n')
    print(s152.maxProduct(nums))