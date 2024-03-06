import torch
import torch.nn
from torchtyping import TensorType

class Solution:
  def reshape(self, to_reshape: TensorType[float]) -> TensorType[float]:
    M, N = to_reshape.shape
    M_new = M*N//2
    N_new = 2
    reshaped_matrix = torch.reshape(to_reshape, (M_new, N_new))
    return torch.round(reshaped_matrix, decimals=4)

  def average(self, to_avg: TensorType[float]) -> TensorType[float]:
    avg = torch.mean(to_avg, dim=0)
    return torch.round(avg, decimals=4)

  def concatenate(self, cat_one: TensorType[float],
                        cat_two: TensorType[float]) -> TensorType[float]:
    combined_tensor = torch.cat((cat_one, cat_two), dim=1)
    return torch.round(combined_tensor, decimals=4)

  def get_loss(self, prediction: TensorType[float],
                     target: TensorType[float]) -> TensorType[float]:
    mse = torch.nn.functional.mse_loss(prediction, target)
    return torch.round(mse, decimals=4)

