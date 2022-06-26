class Solution_174:
    #贪心，解法有点问题
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m,n=len(dungeon),len(dungeon[0])
        if(m==0 or n==0):
            return 0
        i,j=0,0
        ret=dungeon[0][0]
        res=ret
        if(m==1 and n==1):
            res=dungeon[0][0]
        elif(m==1 and j<n and j>0):
            ret+=dungeon[0][j]
            j+=1
            res=min(res,ret)
        elif(n==1 and i<m and i>0):
            ret+=dungeon[i][0]
            i+=1
            res=min(res,ret)
        while(i<m-1 or j<n-1):
            if(i==m-1 and j+1<n):
                ret+=dungeon[i][j+1]
                j+=1
            elif(j==n-1 and i+1<m):
                ret+=dungeon[i+1][j]
                i+=1
            elif(i+1<m and j+1<n):
                if dungeon[i+1][j]>dungeon[i][j+1] :
                    ret+=dungeon[i+1][j]
                    i+=1
                else:
                    ret+=dungeon[i][j+1]
                    j+=1
            res=min(res,ret)
        if res<0:
            return -res+1
        else:
            return 1