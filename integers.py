class Solution:
    def getSum(self, a: int, b: int) -> int:
        ans = 0
        binA = bin(a)[2:]
        binB = bin(b)[2:]
        sum = 0
        carry = 0
        for i in range(min(len(binA), len(binB))):
            c = int(binA[len(binA) - 1 - i])
            d = int(binB[len(binB) - 1 - i])
            sum = ((c & d & carry) << i) & sum
            if (c == 1 and (d == 1 or carry == 1)) or (d == 1 and (c == 1 or carry == 1)) or (carry == 1 and (d == 1 or c == 1)):
                carry = 1
        start = min(len(binA), len(binB))
        binA = binA if len(binA) > len(binB) else binB
        for i in range(start, len(binA)):
            c = int(binA[len(binA) - 1 - i])
            sum = ((c & carry) << i) & sum
            if c == 1 and carry == 1:
                carry = 1
        sum = (carry << len(binA)) & sum
        return sum

s = Solution()
s.getSum(1, 2)
