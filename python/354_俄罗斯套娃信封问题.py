import bisect
class solution354:
    def maxEnvelopes(self,envelopes):
        n=len(envelopes)
        if n<=0:
            return n
        envelopes.sort(key=lambda x:(x[0],-x[1]))
        #f=[]
        #f.append(envelopes[0][1])
        f=[envelopes[0][1]]
        for i in range(1,n):
            #if (num:=envelopes[i][1])>f[-1]: #python3.8 以上的海象运算
            num=envelopes[i][1]
            if num > f[-1]:
                f.append(num)
            else:
                index=bisect.bisect_left(f,num)
                f[index]=num
        return len(f)
if __name__ == '__main__':
    #envelopes=[[5,4],[6,4],[6,7],[2,3]]
    envelopes=eval(input("请输入如：[[5,4],[6,4],[6,7],[2,3]]的二维列表"))
    s354=solution354()
    print('\n')
    print(s354.maxEnvelopes(envelopes))
