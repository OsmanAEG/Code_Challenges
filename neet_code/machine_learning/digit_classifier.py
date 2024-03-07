import torch
import torch.nn as nn
from torchtyping import TensorType

class Solution(nn.Module):
  def __init__(self):
    super().__init__()
    torch.manual_seed(0)
    self.layer1  = nn.Linear(784, 512)
    self.relu    = nn.ReLU()
    self.dropout = nn.Dropout(p=0.2)
    self.layer2  = nn.Linear(512, 10)
    self.sigmoid = nn.Sigmoid()

  def forward(self, images: TensorType[float]) -> TensorType[float]:
    torch.manual_seed(0)
    layer1  = self.layer1(images)
    relu    = self.relu(layer1)
    dropout = self.dropout(relu)
    layer2  = self.layer2(dropout)
    result  = self.sigmoid(layer2)

    return torch.round(result, decimals=4)

