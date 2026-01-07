class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operations = ["*", "+", "-", "/"]
        stack = []
        while (len(tokens)):
            top = tokens.pop(0)
            if (top in operations):
                right = int(stack.pop())
                left = int(stack.pop())
                operation = top
                if operation == "+":
                    stack.append(left + right)
                elif operation == "-":
                    stack.append(left - right)
                elif operation == "*":
                    stack.append(left * right)
                elif operation == "/":
                    stack.append(int(left/right))
            else:
                stack.append(top)
        return int(stack.pop())

