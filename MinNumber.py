import fractions
def compute():
    ans = 1
    for i in range(1, 21):
        ans *= i // fractions.gcd(i, ans)
    return str(ans)

print(compute())



