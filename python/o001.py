class so001:
    def div(self,a,b):
        if a == 0:
            return 0
        if (b == 1 or b == -1):
            if b == 1:
                if a > 2 ** 31:
                    return 2 ** 31
                else:
                    return a
            if b == -1:
                if a <= -2 ** 31 + 1:
                    return 2 ** 31
                else:
                    return -a
        sign = 1 if ((a > 0 and b > 0) or (a < 0 and b < 0)) else -1
        if a > 0:
            a = -a
        if b > 0:
            b = -b
        ret = 0
        while (a <= b):
            a -= b
            if (ret >= 2 ** 31 - 1):
                ret = 2 ** 31 - 1
                break
            ret = ret + 1
        return ret * sign
if __name__ == '__main__':
    nums=eval(input())
    a,b=nums[0],nums[1]
    ss=so001()
    print(ss.div(a,b))
    #print(div(a,b))