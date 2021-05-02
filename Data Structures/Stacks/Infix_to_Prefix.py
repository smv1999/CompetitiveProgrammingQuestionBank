class Coversion_Infi_Prefi:

    def __init__(self, size):
        self.top = -1
        self.size = size
        self.garbage = []
        self.Result = []
        self.precedence = {"+": 1, "-": 1, "*": 2, "/": 2, "^": 3}

    def Is_Empty(self):
        return True if self.top == -1 else False

    def Peek(self):
        return self.garbage[-1]

    def Pop(self):
        if not self.Is_Empty():
            self.top -= 1
            return self.garbage.pop()
        else:
            return "$"

    def Push(self, data):
        self.top += 1
        self.garbage.append(data)

    def Is_Operand(self, ch):
        return ch.isalpha()

    def Is_Greater(self, ele):
        try:
            a = self.precedence[ele]
            b = self.precedence[self.Peek()]
            return True if a <= b else False
        except KeyError:
            return False

    def Infix_to_Prefix(self, Expres):
        for i in Expres:
            if self.Is_Operand(i):
                self.Result.append(i)
            elif i == "(":
                self.Push(i)
            elif i == ")":
                while (not self.Is_Empty() and self.Peek() != "("):
                    ele = self.Pop()
                    self.Result.append(ele)
                if (not self.Is_Empty() and self.Peek() != "("):
                    return -1
                else:
                    self.Pop()
            else:
                while(not self.Is_Empty() and self.Is_Greater(i)):
                    self.Result.append(self.Pop())
                self.Push(i)
        while (not self.Is_Empty()):
            self.Result.append(self.Pop())
        print("".join(self.Result))


if __name__ == "__main__":
    Expr = "a+b*(c^d-e)^(f+g*h)-i"
    Stack_Expr = Coversion_Infi_Prefi(len(Expr))
    Stack_Expr.Infix_to_Prefix(Expr)