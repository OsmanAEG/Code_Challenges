import numpy as np
from numpy.typing import NDArray


class Solution:
  def get_derivative(self,
                      model_prediction: NDArray[np.float64],
                      ground_truth: NDArray[np.float64],
                      N: int, X: NDArray[np.float64],
                      desired_weight: int) -> float:
    return -2 * np.dot(ground_truth - model_prediction, X[:, desired_weight]) / N

  def get_model_prediction(self,
                           X: NDArray[np.float64],
                           weights: NDArray[np.float64]) -> NDArray[np.float64]:
    return np.squeeze(np.matmul(X, weights))

  learning_rate = 0.01

  def train_model(
    self,
    X: NDArray[np.float64],
    Y: NDArray[np.float64],
    num_iterations: int,
    initial_weights: NDArray[np.float64]) -> NDArray[np.float64]:

    for i in range(num_iterations):
      prediction = self.get_model_prediction(X, initial_weights)
      print(prediction)

      initial_weights[0] -= self.get_derivative(prediction, Y, len(X), X, 0)*self.learning_rate
      initial_weights[1] -= self.get_derivative(prediction, Y, len(X), X, 1)*self.learning_rate
      initial_weights[2] -= self.get_derivative(prediction, Y, len(X), X, 2)*self.learning_rate

    return np.round(initial_weights, 5)

def ex1():
  X = np.array([[1, 2, 3], [1, 1, 1]])
  Y = np.array([6, 3])
  num_iterations = 1000
  initial_weights = [0.2, 0.1, 0.6]

  sol = Solution()
  ans = sol.train_model(X, Y, num_iterations, initial_weights)
  print(ans)

ex1()