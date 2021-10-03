def pi(n:int):
  num: float = 4.0
  den: float = 1.0
  oper: float = 1.0
  pi:float = 0.0

  for i in range(n):
    pi += oper * (num / den)
    den += 2.0
    oper *= -1.0

  return pi

print(pi(500000))
