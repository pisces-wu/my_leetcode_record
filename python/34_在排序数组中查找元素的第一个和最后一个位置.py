class Solution_34:
    def searchRange(self,nums,target):
        n=len(nums)
        l,r=0,n-1
        pos=-1
        ret=[]
        while l<=r:
            mid=(l+r)//2
            if(nums[mid]>target):
                r=mid-1
            elif(nums[mid]<target):
                l=mid+1
            else:
                pos=mid
                break
        ll, rr = pos, pos
        if(pos!=-1):
            while(ll-1>=0 and nums[ll-1]==nums[ll]):
                ll=ll-1
            while(rr+1<n and nums[rr+1]==nums[rr]):
                rr=rr+1
            ret.append(ll)
            ret.append(rr)
            return ret
        else:
            return [-1,-1]
if __name__ == '__main__':
    nums=eval(input("请输入一个数组"))
    target=eval(input("请输入目标值"))
    s_64=Solution_34()
    #list=s_64.searchRange(nums,target)
    #print(list)
    li=s_64.searchRange(nums,target)
    print(li)
    #print(s_64.searchRange(nums,target))
    print('\n')
