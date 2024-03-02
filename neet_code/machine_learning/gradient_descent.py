class Solution:
  def get_minimizer(self,
                    iterations: int,
                    learning_rate: float,
                    init: int) -> float:
    x = init
    for i in range(iterations):
      x -= learning_rate*(2*x)
    return round(x, 5)

def ex1():
  it = 0
  lr = 0.01
  init = 5

  sol = Solution
  ans = sol.get_minimizer(sol, it, lr, init)
  print(ans)

def ex2():
  it = 10
  lr = 0.01
  init = 5

  sol = Solution
  ans = sol.get_minimizer(sol, it, lr, init)
  print(ans)

# ex1()
ex2()


