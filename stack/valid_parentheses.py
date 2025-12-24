class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        if len(s)<=1: 
            return False
        for i in s:
            if i == "(" or i =="[" or i == "{":
                stack.append(i)
            elif len(stack)>0:
                if i==")" and stack[-1]=="(":
                    stack.pop()
                elif i=="}" and stack[-1]=="{":
                    stack.pop()
                elif i=="]" and stack[-1]=="[":
                    stack.pop()
                else:
                    return False
            else:
                return False
        if len(stack)!=0:
            return False
        return True