class Solution:
    def defangIPaddr(self, address: str) -> str:
        temp = ""
        for x in address:
            if (x == '.'):
                temp+='[.]'
            else:
                temp+=x
        return temp