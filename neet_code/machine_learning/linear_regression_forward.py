import numpy as np
from numpy.typing import NDArray

class Solution:
  def get_model_prediction(self,
                           X: NDArray[np.float64],
                           weights: NDArray[np.float64]) -> NDArray[np.float64]:
    prod = np.matmul(X, weights)
    return np.round(prod, 5)


  def get_error(self,
                model_prediction: NDArray[np.float64],
                ground_truth: NDArray[np.float64]) -> float:
    abs_err = model_prediction - ground_truth
    avg_err = np.mean(np.square(abs_err))
    return round(avg_err, 5)
