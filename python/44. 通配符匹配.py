class Solution_44:
    def isMatch(self,s,p):
        m,n=len(s),len(p)
        if(m==0 and n==0):
            return true
        dp=[[0]*(n+1) for _ in range(m+1)]
        dp[0][0]=1
        for i in range(1,n+1):
            if(p[i-1]=="*"):
                dp[i][0]=1
            else:
                break
        for i in range(1,m+1):
            for j in range(1,n+1):
                if(s[i-1]==p[i-1] or p[i-1]=='?'):
                    dp[i][j]=dp[i-1][j-1]
                elif(p[i-1]=='*'):
                    dp[i][j]=dp[i-1][j] or dp[i][j-1]
        return dp[m][n]

if __name__ == '__main__':
    s_44=Solution_44()
    s=input("s")
    p=input("p")
    if(s_44.isMatch(s,p)):
        print("True")
    else:print("False")
