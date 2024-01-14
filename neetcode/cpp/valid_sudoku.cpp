#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board){
    std::unordered_map<int, int> check;

    // row check
    for(int i = 0; i < 9; ++i){
      for(int j = 0; j < 9; ++j){
        if(board[i][j] != '.') check[board[i][j]] += 1;
      }

      for(auto idx = check.begin(); idx != check.end(); ++idx){
        if(idx->second > 1) return false;
      }

      check.clear();
    }

    // col check
    for(int j = 0; j < 9; ++j){
      for(int i = 0; i < 9; ++i){
        if(board[i][j] != '.') check[board[i][j]] += 1;
      }

      for(auto idx = check.begin(); idx != check.end(); ++idx){
        if(idx->second > 1) return false;
      }

      check.clear();
    }

    // block check
    int sweep_i = 0;
    int sweep_j = 0;

    for(int i_sweep = 0; i_sweep < 3; ++i_sweep){
      for(int j_sweep = 0; j_sweep < 3; ++j_sweep){
        for(int i = i_sweep*3; i < i_sweep*3 + 3; ++i){
          for(int j = j_sweep*3; j < j_sweep*3 + 3; ++j){
            if(board[i][j] != '.') check[board[i][j]] += 1;
          }
        }

        for(auto idx = check.begin(); idx != check.end(); ++idx){
          if(idx->second > 1) return false;
        }

        check.clear();
      }
    }

    return true;
  }
};

int main(){
  std::vector<std::vector<char>> board_in = {{'5','3','.','.','7','.','.','.','.'},
                                             {'6','.','.','1','9','5','.','.','.'},
                                             {'.','9','8','.','.','.','.','6','.'},
                                             {'8','.','.','.','6','.','.','.','3'},
                                             {'4','.','.','8','.','3','.','.','1'},
                                             {'7','.','.','.','2','.','.','.','6'},
                                             {'.','6','.','.','.','.','2','8','.'},
                                             {'.','.','.','4','1','9','.','.','5'},
                                             {'.','.','.','.','8','.','.','7','9'}};

  auto result = Solution().isValidSudoku(board_in);
  std::cout << result << std::endl;
}