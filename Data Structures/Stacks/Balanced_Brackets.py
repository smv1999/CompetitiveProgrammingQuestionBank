def Balanced_Brackets(Expr):
    stack = []
    for Brkt in Expr:
        if Brkt in ["(", "{", "["]:
            stack.append(Brkt)
        else:
            if not stack:
                return False
            Current_Brkt = stack.pop()
            if Current_Brkt == "(":
                if Brkt != ")":
                    return False
            if Current_Brkt == "{":
                if Brkt != "}":
                    return False
            if Current_Brkt == "[":
                if Brkt != "]":
                    return False
    if stack:
        return False
    return True


if __name__ == "__main__":
    Expr = "{()}[]"
    if Balanced_Brackets(Expr):
        print("Balanced Brackets")
    else:
        print("UnBalanced Brackets")
