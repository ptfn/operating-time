def brackets(s):
    exists = []
    for i in range(len(s)):
        if s[i] == '(':
            for j in range(i, len(s)):
                if s[j] == ')' and j not in exists:
                    exists.append(j)
                    break
            else:
                return False
        elif s[i] == ')':
            for k in range(len(exists)):
                if i == exists[k]:
                    break
            else:
                return False
    return True


if __name__ == "__main__":
    # True
    print(brackets("()"))
    print(brackets("(()())"))
    print(brackets("()(()())"))
    # False
    print(brackets("())"))
    print(brackets(")("))
    print(brackets("())"))
    print(brackets("(()"))
