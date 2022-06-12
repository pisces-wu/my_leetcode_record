class Solution_1230:
    def probabilityOfHeads(self,prob,target):
        n=len(prob)
        dp=[[0]*(target+1) for i in range(n+1)]
        dp[0][0]=1
        for i in range(1,n+1):
            for j in range(target+1):
                if(j==0):
                    dp[i][j]=dp[i-1][j]*(1-prob[i-1])
                else:
                    dp[i][j]=dp[i-1][j]*(1-prob[i-1])+dp[i-1][j-1]*(prob[i-1])
        return dp[n][target]
if __name__ == '__main__':
    prob=eval(input("请输入序列概率："))
    target=eval(input("请输入正面向上的硬币数："))
    s_1230=Solution_1230();
    print(s_1230.probabilityOfHeads(prob,target))
