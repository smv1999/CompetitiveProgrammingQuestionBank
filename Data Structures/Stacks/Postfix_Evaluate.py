class Evaluate_Postfix:

    def __init__(self, size):
        self.top = -1
        self.size = size
        self.garbage = []

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

    def Postfix_Eval(self, Expres):
        for i in Expres:
            if i.isdigit():
                self.Push(i)
            else:
                Val_1 = self.Pop()
                Val_2 = self.Pop()
                self.Push(str(eval(Val_2+i+Val_1)))
        return int(self.Pop())


if __name__ == "__main__":
    Expr = "231*+9-"
    Stack_Expr = Evaluate_Postfix(len(Expr))
    print("%d" % (Stack_Expr.Postfix_Eval(Expr)))
