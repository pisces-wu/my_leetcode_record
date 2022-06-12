import  bisect
class Solution_10_09:
    # Z型查找
    def searchMatrix(self,matrix,target):
        if(len(matrix)==0): return False
        rows,cols=len(matrix),len(matrix[0])
        i,j=rows-1,0
        while(i>=0 and j<cols):
            if(matrix[i][j]>target):
                i-=1
                
            elif(matrix[i][j]<target):
                j+=1
            else:
                return True
        return False

    # 二分查找
    # def searchMatrix(self,matrix,target):
    #     if(len(matrix)==0): return False
    #     rows,cols=len(matrix),len(matrix[0])
    #     row=0
    #     while(row<rows):
    #         index=bisect.bisect_left(matrix[row],target)
    #         if(index<cols and matrix[row][index]==target):
    #             return True
    #         row+=1
    #     return  False
if __name__ == '__main__':
    s1009=Solution_10_09()
    matrix=[]
    #print("请输入行数")
    rows=eval(input("请输入行数"))
    while(rows):
        rows-=1
        mat = eval(input())
        matrix.append(mat)
    target=eval(input("请输入要查找的数"))
    print(s1009.searchMatrix(matrix,target))


