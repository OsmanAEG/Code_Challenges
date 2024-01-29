#include <vector>
#include <iostream>
#include <string>

void output_grid(std::vector<std::string> pieces_position_list){
  int num_rows = 6;
  int num_cols = 7;

  int num_entries = pieces_position_list.size();

  std::vector<std::vector<char>> grid(num_cols, std::vector<char>(num_rows, ' '));

  for(int idx = 0; idx < num_entries; ++idx){
    const int col = pieces_position_list[idx][0] - 'A';
    const int plr = pieces_position_list[idx][2];

    for(int row = 0; row < num_rows; ++row){
      if(grid[col][row] == ' '){
        grid[col][row] = plr;
        break;
      }
    }
  }

  for(int row = num_rows-1; row >= 0; --row){
    for(int col = 0; col < num_cols; ++col){
      std::cout << "|" << grid[col][row];
    }
    std::cout << "|" << std::endl;
  }
}

std::string who_is_winner(std::vector<std::string> pieces_position_list){
  int num_rows = 6;
  int num_cols = 7;

  int num_entries = pieces_position_list.size();
  std::vector<std::vector<char>> grid(num_cols, std::vector<char>(num_rows, ' '));

  for(int idx = 0; idx < num_entries; ++idx){
    const int col = pieces_position_list[idx][0] - 'A';
    const int plr = pieces_position_list[idx][2];

    // finding empty element in column
    for(int row = 0; row < num_rows; ++row){
      if(grid[col][row] == ' '){
        grid[col][row] = plr;
        int in_order;
        int i_pos;
        int j_pos;

        // vertical check
        in_order = 0;
        for(int i = 0; i < num_rows; ++i){
          if(grid[col][i] == plr) ++in_order;
          else in_order = 0;
          if(in_order == 4) return (plr == 'Y') ? "Yellow" : "Red";
        }

        // horizontal check
        in_order = 0;
        for(int i = 0; i < num_cols; ++i){
          if(grid[i][row] == plr) ++in_order;
          else in_order = 0;
          if(in_order == 4) return (plr == 'Y') ? "Yellow" : "Red";
        }

        // bottom left to top right diagonal
        in_order = 0;
        i_pos = (col > row)  ? col - row : 0;
        j_pos = (row >= col) ? row - col : 0;

        while(i_pos < num_cols && j_pos < num_rows){
          if(grid[i_pos][j_pos] == plr) ++in_order;
          else in_order = 0;
          if(in_order == 4) return (plr == 'Y') ? "Yellow" : "Red";

          ++i_pos;
          ++j_pos;
        }

        // top left to bottom right diagonal
        int row_max = num_rows - 1;
        i_pos = (col > row_max - row)  ? col - (row_max - row) : 0;
        j_pos = (num_rows - row >= col) ? col + row : 0;
        in_order = 0;

        while(i_pos < num_cols && j_pos >= 0){
          if(grid[i_pos][j_pos] == plr) ++in_order;
          else in_order = 0;
          if(in_order == 4) return (plr == 'Y') ? "Yellow" : "Red";

          ++i_pos;
          --j_pos;
        }

        break;
      }
    }
  }

  return "Draw";
}

int main(){
  std::vector<std::string> pieces_position_list{
                "A_Red",
                "B_Yellow",
                "A_Red",
                "B_Yellow",
                "A_Red",
                "B_Yellow",
                "G_Red",
                "B_Yellow"
  };

  auto result = who_is_winner(pieces_position_list);
  std::cout << result << std::endl;
  output_grid(pieces_position_list);
}
