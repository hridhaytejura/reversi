//
// Author:
//
#include <stdio.h>
#include <stdlib.h>
#include "lab8part2.h"
#include "liblab8part2.h"

void printBoard(char board[][26], int n) {

  printf("  ");
  for(char ch = 'a'; ch<(char)((int)'a'+n); ch++)
  {
    printf("%c", ch);
  }
  printf("\n");
  for(char row = 'a'; row<(char)((int)'a'+n); row++)
  {
    printf("%c ", row);
    for(char col = 'a'; col<(char)((int)'a'+n); col++)
    {
      printf("%c", board[(int)row - 97][(int)col - 97]);
    }
    printf("\n");
  }
}

bool positionInBounds(int n, int row, int col) {
  if(row<n && col<n && row>=0 && col >=0)
  {
    return true;
  }
  return false;
}

bool checkLegalInDirectionConstant(const char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
  
char opp = (colour == 'B')?'W':'B';

int countopp = 0;
for(int i = row, j = col; i < n && i>=0 && j<n && j>= 0; i += deltaRow, j += deltaCol)
{

  if(board[i][j] == 'U')
  {
    return false;
  }
  
  if(board[i][j] == colour && countopp>0)
  {
    return true;
  }
  if(board[i][j] == colour && countopp == 0)
  {
    return false;
  }
  if(board[i][j] == opp)
  {
    countopp++;
  }
  
}
return false;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
  
char opp = (colour == 'B')?'W':'B';

int countopp = 0;
for(int i = row, j = col; i < n && i>=0 && j<n && j>= 0; i += deltaRow, j += deltaCol)
{

  if(board[i][j] == 'U')
  {
    return false;
  }
  
  if(board[i][j] == colour && countopp>0)
  {
    return true;
  }
  if(board[i][j] == colour && countopp == 0)
  {
    return false;
  }
  if(board[i][j] == opp)
  {
    countopp++;
  }
  
}
return false;
}

int checkValidMove(char player, char row, char col, char Wa[8][2], char Ba[8][2])
{
  char check [8][2];

  if(player == 'W')
  {
    for(int i = 0; i<8; i++)
    {
      for(int j = 0; j<2; j++)
      {
        char temp = Wa[i][j];
        check[i][j] = temp;
      }
    }
  }
  if(player == 'B')
  {
    for(int i = 0; i<8; i++)
    {
      for(int j = 0; j<2; j++)
      {
        char temp = Ba[i][j];
        check[i][j] = temp;
      }
    }
  }

  //int count = 0;
  for(int i = 0; i<8; i++)
  {
    if(row == check[i][0] && col == check[i][1])
    {
      return i;
    }
  }
  return -1;
}

void changeBoard(char board[][26], int n, int row, int col, char player, int deltaRow, int deltaCol)
{
  
  for(int i = row, j = col; i < n && i>=0 && j<n && j>= 0; i += deltaRow, j += deltaCol)
  {

    if(board[i][j] == player)
    {
      break;
    }

    //if(board[i][j] == opp)
    else
    {
      board[i][j] = player;
    }

  }
  //printBoard(board, n);

}

bool drawOrWin(char board[][26], int n)
{
  bool ret = false;
  int Wcount = 0, Bcount = 0, Wscore = 0, Bscore = 0;

  char colour = 'W';
  
  for(char row = 'a'; row<(char)((int)'a'+n); row++)
  {
    for(char col = 'a'; col<(char)((int)'a'+n); col++)
    {
      
      int deltaRow, deltaCol;
      for(int i = 1; i<=8; i++)
      {
        switch(i)
        {
          case 1:
          deltaRow = -1;
          deltaCol = 0;
          break;
          case 2:
          deltaRow = -1;
          deltaCol = 1;
          break;
          case 3:
          deltaRow = 0;
          deltaCol = 1;
          break;
          case 4:
          deltaRow = 1;
          deltaCol = 1;
          break;
          case 5:
          deltaRow = 1;
          deltaCol = 0;
          break;
          case 6:
          deltaRow = 1;
          deltaCol = -1;
          break;
          case 7:
          deltaRow = 0;
          deltaCol = -1;
          break;
          case 8:
          deltaRow = -1;
          deltaCol = -1;
          break;
          default:
          deltaRow = 0;
          deltaCol = 0;
          break;

        }


        if(board[(int)row - 97][(int)col - 97] == 'U')
      {
        if(checkLegalInDirection(board, n, (int)row - 97+deltaRow, (int)col - 97+deltaCol, colour, deltaRow, deltaCol))
        {
          Wcount++;
        }
      }
      }
      
    }
  }

  
  
  colour = 'B';
  
  for(char row = 'a'; row<(char)((int)'a'+n); row++)
  {
    for(char col = 'a'; col<(char)((int)'a'+n); col++)
    {
      
      int deltaRow, deltaCol;
      for(int i = 1; i<=8; i++)
      {
        switch(i)
        {
          case 1:
          deltaRow = -1;
          deltaCol = 0;
          break;
          case 2:
          deltaRow = -1;
          deltaCol = 1;
          break;
          case 3:
          deltaRow = 0;
          deltaCol = 1;
          break;
          case 4:
          deltaRow = 1;
          deltaCol = 1;
          break;
          case 5:
          deltaRow = 1;
          deltaCol = 0;
          break;
          case 6:
          deltaRow = 1;
          deltaCol = -1;
          break;
          case 7:
          deltaRow = 0;
          deltaCol = -1;
          break;
          case 8:
          deltaRow = -1;
          deltaCol = -1;
          break;
          default:
          deltaRow = 0;
          deltaCol = 0;
          break;

        }


        if(board[(int)row - 97][(int)col - 97] == 'U')
      {
        if(checkLegalInDirection(board, n, (int)row - 97+deltaRow, (int)col - 97+deltaCol, colour, deltaRow, deltaCol))
        {
          Bcount++;
        }
      }
      }
      
    }
  }
  
  if(Bcount == 0 && Wcount == 0)
  {
    ret = true;
    for(int x = 0; x<n; x++)
    {
      for(int y = 0; y<n; y++)
      {
        if(board[x][y] == 'W')
        {
          Wscore++;
        }
        if(board[x][y] == 'B')
        {
          Bscore++;
        }
      }
    }
    if(Bscore < Wscore)
    {
      printf("W player wins.");
      exit(0);
    }
    else if(Bscore > Wscore)
    {
      printf("B player wins.");
      exit(0);
    }
    else
    {
      printf("Draw!");
      exit(0);
    }
  }
  
  
  return ret;
}

bool drawOrWin1(char board[][26], int n)
{
  bool ret = false;
  int Wcount = 0, Bcount = 0, Wscore = 0, Bscore = 0;

  char colour = 'W';
  
  for(char row = 'a'; row<(char)((int)'a'+n); row++)
  {
    for(char col = 'a'; col<(char)((int)'a'+n); col++)
    {
      
      int deltaRow, deltaCol;
      for(int i = 1; i<=8; i++)
      {
        switch(i)
        {
          case 1:
          deltaRow = -1;
          deltaCol = 0;
          break;
          case 2:
          deltaRow = -1;
          deltaCol = 1;
          break;
          case 3:
          deltaRow = 0;
          deltaCol = 1;
          break;
          case 4:
          deltaRow = 1;
          deltaCol = 1;
          break;
          case 5:
          deltaRow = 1;
          deltaCol = 0;
          break;
          case 6:
          deltaRow = 1;
          deltaCol = -1;
          break;
          case 7:
          deltaRow = 0;
          deltaCol = -1;
          break;
          case 8:
          deltaRow = -1;
          deltaCol = -1;
          break;
          default:
          deltaRow = 0;
          deltaCol = 0;
          break;

        }


        if(board[(int)row - 97][(int)col - 97] == 'U')
      {
        if(checkLegalInDirection(board, n, (int)row - 97+deltaRow, (int)col - 97+deltaCol, colour, deltaRow, deltaCol))
        {
          Wcount++;
        }
      }
      }
      
    }
  }

  
  
  colour = 'B';
  
  for(char row = 'a'; row<(char)((int)'a'+n); row++)
  {
    for(char col = 'a'; col<(char)((int)'a'+n); col++)
    {
      
      int deltaRow, deltaCol;
      for(int i = 1; i<=8; i++)
      {
        switch(i)
        {
          case 1:
          deltaRow = -1;
          deltaCol = 0;
          break;
          case 2:
          deltaRow = -1;
          deltaCol = 1;
          break;
          case 3:
          deltaRow = 0;
          deltaCol = 1;
          break;
          case 4:
          deltaRow = 1;
          deltaCol = 1;
          break;
          case 5:
          deltaRow = 1;
          deltaCol = 0;
          break;
          case 6:
          deltaRow = 1;
          deltaCol = -1;
          break;
          case 7:
          deltaRow = 0;
          deltaCol = -1;
          break;
          case 8:
          deltaRow = -1;
          deltaCol = -1;
          break;
          default:
          deltaRow = 0;
          deltaCol = 0;
          break;

        }


        if(board[(int)row - 97][(int)col - 97] == 'U')
      {
        if(checkLegalInDirection(board, n, (int)row - 97+deltaRow, (int)col - 97+deltaCol, colour, deltaRow, deltaCol))
        {
          Bcount++;
        }
      }
      }
      
    }
  }
  
  if(Bcount == 0 && Wcount == 0)
  {
    ret = true;
  }
  
  return ret;
}


//lab8part1 edits start here

int scoreInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){

  int sum = 0;
  char opp = (colour == 'B')?'W':'B';

  for(int i = row, j = col; i<n && i>=0 && j<n && j>=0; i+= deltaRow, j+= deltaCol)
  {
    if(board[i][j] == opp)
    {
      sum++;
    }
    if(board[i][j] == colour)
    {
      break;
    }
  }
  return sum;

}

//lab8part2 functions start here

void changeTempBoard(char tempBoard[][26], int n, int row, int col, char player, int deltaRow, int deltaCol)
{
  
  for(int i = row, j = col; i < n && i>=0 && j<n && j>= 0; i += deltaRow, j += deltaCol)
  {

    if(tempBoard[i][j] == player)
    {
      break;
    }

    //if(board[i][j] == opp)
    else
    {
      tempBoard[i][j] = player;
    }

  }
  //printBoard(board, n);

}

int score(char tempBoard[][26], int n, char find)
{
  int count = 0;
  for(int i = 0; i<n; i++)
  {
    for(int j = 0; j<n; j++)
    {
      if(tempBoard[i][j] == find)
      {
        count++;
      }
    }
  }
  return count;
}

int heuristic(char tempBoard[][26], int n, char turn)
{
  char opp = (turn == 'W')?'B':'W';
  int ourScore = score(tempBoard, n, turn);
  int opponentScore = score(tempBoard, n, opp);
  return ourScore-opponentScore;
}

int minimax(char tempBoard[][26], int n, char turn, char opp, int depth, int alpha, int beta)
{
  if(depth == 3 || drawOrWin1(tempBoard, n))//can change depth
  {
    return heuristic(tempBoard, n, turn);
  }

  //int rowplay, colplay;
  char opponent = (turn == 'W')?'B':'W';

  bool onevalidmove = false;
  for(int i = n-1; i>=0; i--)
  {
    for(int j = n-1; j>=0; j--)
    {
      
      int deltaRow, deltaCol;
      for(int k = 1; k<=8; k++)
      {
        switch(k)
        {
          case 1:
          deltaRow = -1;
          deltaCol = 0;
          break;
          case 2:
          deltaRow = -1;
          deltaCol = 1;
          break;
          case 3:
          deltaRow = 0;
          deltaCol = 1;
          break;
          case 4:
          deltaRow = 1;
          deltaCol = 1;
          break;
          case 5:
          deltaRow = 1;
          deltaCol = 0;
          break;
          case 6:
          deltaRow = 1;
          deltaCol = -1;
          break;
          case 7:
          deltaRow = 0;
          deltaCol = -1;
          break;
          case 8:
          deltaRow = -1;
          deltaCol = -1;
          break;
          default:
          deltaRow = 0;
          deltaCol = 0;
          break;

        }


      
      
      if(checkLegalInDirection(tempBoard, n, i+deltaRow, j+deltaCol, turn, deltaRow, deltaCol) && tempBoard[i][j] == 'U')
      {
        onevalidmove = true;
        break;
      }
      
      }
      if(onevalidmove)
      {
        break;
      }
   
    }
    if(onevalidmove)
    {
      break;
    }
  }

  if(!onevalidmove)
  {
    return minimax(tempBoard, n, turn, opponent, depth + 1, alpha, beta);
  }
  else
  {
    int score = (turn != opponent)?99999:-99999;

    for(int i = n-1; i>=0; i--)
    {
      for(int j = n-1; j>=0; j--)
      {
        bool validposition = false; 
        int deltaRow, deltaCol;
        for(int k = 1; k<=8; k++)
        {
          switch(k)
          {
            case 1:
            deltaRow = -1;
            deltaCol = 0;
            break;
            case 2:
            deltaRow = -1;
            deltaCol = 1;
            break;
            case 3:
            deltaRow = 0;
            deltaCol = 1;
            break;
            case 4:
            deltaRow = 1;
            deltaCol = 1;
            break;
            case 5:
            deltaRow = 1;
            deltaCol = 0;
            break;
            case 6:
            deltaRow = 1;
            deltaCol = -1;
            break;
            case 7:
            deltaRow = 0;
            deltaCol = -1;
            break;
            case 8:
            deltaRow = -1;
            deltaCol = -1;
            break;
            default:
            deltaRow = 0;
            deltaCol = 0;
            break;

          }


        
        
          if(checkLegalInDirection(tempBoard, n, i+deltaRow, j+deltaCol, turn, deltaRow, deltaCol) && tempBoard[i][j] == 'U')
          {
            validposition = true;
            break;
          }
        
        }
        if(validposition){
          char tempBoard1[26][26];
          
          for(int x = 0; x<n; x++)
          {
            for(int y = 0; y<n; y++)
            {
              tempBoard1[x][y] = tempBoard[x][y];
            }
          }

          for(int k = 1; k<=8; k++)
          {
            switch(k)
            {
              case 1:
              deltaRow = -1;
              deltaCol = 0;
              break;
              case 2:
              deltaRow = -1;
              deltaCol = 1;
              break;
              case 3:
              deltaRow = 0;
              deltaCol = 1;
              break;
              case 4:
              deltaRow = 1;
              deltaCol = 1;
              break;
              case 5:
              deltaRow = 1;
              deltaCol = 0;
              break;
              case 6:
              deltaRow = 1;
              deltaCol = -1;
              break;
              case 7:
              deltaRow = 0;
              deltaCol = -1;
              break;
              case 8:
              deltaRow = -1;
              deltaCol = -1;
              break;
              default:
              deltaRow = 0;
              deltaCol = 0;
              break;

            }

            if(checkLegalInDirection(tempBoard1, n, i + deltaRow, j+deltaCol, turn, deltaRow, deltaCol) && tempBoard1[i][j] == 'U')
            {
              //validcount++;
              changeTempBoard(tempBoard1, n, i+deltaRow, j + deltaCol, turn, deltaRow, deltaCol);
            }
          }

          int positionscore = minimax(tempBoard1, n, turn, opp, depth+1, alpha, beta);//try changing to tempBoard if some error

          if(turn == opp)
          {
            if(positionscore > score)
            {
              score = positionscore;
            }
            alpha = (alpha>positionscore)?alpha:positionscore;
            if(beta<=alpha)
            {
              return score;
            }
          }
          else{
            if(positionscore<score)
            {
              score = positionscore;
            }
            beta = (beta<positionscore)?beta:positionscore;
            if(beta<=alpha)
            {
              return score;
            }
          }


        }
      }
    }
    return score;
  }
  return -1;
}

int makeMove(const char board[][26], int n, char turn, int *row, int *col)
{
  char opp = (turn == 'B')?'W':'B';

  int rowplay = 0, colplay = 0, score = -99999;

  for(int i = n-1; i>=0; i--)
  {
    for(int j = n-1; j>=0; j--)
    {
      bool validposition = false; 
      int deltaRow, deltaCol;
      for(int k = 1; k<=8; k++)
      {
        switch(k)
        {
          case 1:
          deltaRow = -1;
          deltaCol = 0;
          break;
          case 2:
          deltaRow = -1;
          deltaCol = 1;
          break;
          case 3:
          deltaRow = 0;
          deltaCol = 1;
          break;
          case 4:
          deltaRow = 1;
          deltaCol = 1;
          break;
          case 5:
          deltaRow = 1;
          deltaCol = 0;
          break;
          case 6:
          deltaRow = 1;
          deltaCol = -1;
          break;
          case 7:
          deltaRow = 0;
          deltaCol = -1;
          break;
          case 8:
          deltaRow = -1;
          deltaCol = -1;
          break;
          default:
          deltaRow = 0;
          deltaCol = 0;
          break;

        }


      
      
        if(checkLegalInDirectionConstant(board, n, i+deltaRow, j+deltaCol, turn, deltaRow, deltaCol) && board[i][j] == 'U')
        {
          validposition = true;
          break;
        }
      
      }
      if(validposition){
        char tempBoard[26][26];
        
        for(int x = 0; x<n; x++)
        {
          for(int y = 0; y<n; y++)
          {
            tempBoard[x][y] = board[x][y];
          }
        }

        for(int k = 1; k<=8; k++)
        {
          switch(k)
          {
            case 1:
            deltaRow = -1;
            deltaCol = 0;
            break;
            case 2:
            deltaRow = -1;
            deltaCol = 1;
            break;
            case 3:
            deltaRow = 0;
            deltaCol = 1;
            break;
            case 4:
            deltaRow = 1;
            deltaCol = 1;
            break;
            case 5:
            deltaRow = 1;
            deltaCol = 0;
            break;
            case 6:
            deltaRow = 1;
            deltaCol = -1;
            break;
            case 7:
            deltaRow = 0;
            deltaCol = -1;
            break;
            case 8:
            deltaRow = -1;
            deltaCol = -1;
            break;
            default:
            deltaRow = 0;
            deltaCol = 0;
            break;

          }

          if(checkLegalInDirectionConstant(board, n, rowplay + deltaRow, colplay+deltaCol, turn, deltaRow, deltaCol) && tempBoard[rowplay][colplay] == 'U')
          {
            //validcount++;
            changeTempBoard(tempBoard, n, i + deltaRow, j + deltaCol, turn, deltaRow, deltaCol);
          }
        }

        int positionscore = minimax(tempBoard, n, turn, opp, 1, -99999, 99999);
        if(i == 0 || j == 0 || i == n-1 || j == n-1)
        {
            positionscore *= 2;
        }
        if((i == 0 && j == 0) || (i == 0 && j == n-1) || (j == 0 && i == n-1) || (i == n-1 && j == n-1))
        {
            positionscore *= 2;
        }
        if(positionscore > score)
        {
          score = positionscore;
          rowplay = i;
          colplay = j;
        }
      }
   
    }
  }
  *row = rowplay;
  *col = colplay;
  return 0;
}






//void copyBoard(char src[][26], char dest[][26])
//{
//  memcpy(dest, src, 8*8*sizeof(char));
//}

//lab8part2 functions end here

void computerPlay(char board[][26], int n, char colour){
  
  int rowplay = 0, colplay = 0, score = 0;
  int *row = &rowplay;
  int *col= &colplay;
  makeMove(board, n, colour, row, col);

  int deltaRow, deltaCol;
  int validcount = 0;
      for(int k = 1; k<=8; k++)
      {
        switch(k)
        {
          case 1:
          deltaRow = -1;
          deltaCol = 0;
          break;
          case 2:
          deltaRow = -1;
          deltaCol = 1;
          break;
          case 3:
          deltaRow = 0;
          deltaCol = 1;
          break;
          case 4:
          deltaRow = 1;
          deltaCol = 1;
          break;
          case 5:
          deltaRow = 1;
          deltaCol = 0;
          break;
          case 6:
          deltaRow = 1;
          deltaCol = -1;
          break;
          case 7:
          deltaRow = 0;
          deltaCol = -1;
          break;
          case 8:
          deltaRow = -1;
          deltaCol = -1;
          break;
          default:
          deltaRow = 0;
          deltaCol = 0;
          break;

        }

        if(checkLegalInDirection(board, n, rowplay + deltaRow, colplay+deltaCol, colour, deltaRow, deltaCol) && board[rowplay][colplay] == 'U')
        {
          validcount++;
          changeBoard(board, n, rowplay + deltaRow, colplay + deltaCol, colour, deltaRow, deltaCol);
        }



      }
  if(validcount == 0)
  {
    printf("%c player has no valid move.\n", colour);
  }
  else{
    board[rowplay][colplay] = colour;
  
  printf("Computer places %c at %c%c.\n", colour, (char)(rowplay+97), (char)(colplay+97));
  printBoard(board, n);
  }

}



                   
void humanPlay(char board[][26], int n, char colour)
{

  int optioncount = 0;

  for(char row = 'a'; row<(char)((int)'a'+n); row++)
  {
    for(char col = 'a'; col<(char)((int)'a'+n); col++)
    {
      
      int deltaRow, deltaCol;
      for(int i = 1; i<=8; i++)
      {
        switch(i)
        {
          case 1:
          deltaRow = -1;
          deltaCol = 0;
          break;
          case 2:
          deltaRow = -1;
          deltaCol = 1;
          break;
          case 3:
          deltaRow = 0;
          deltaCol = 1;
          break;
          case 4:
          deltaRow = 1;
          deltaCol = 1;
          break;
          case 5:
          deltaRow = 1;
          deltaCol = 0;
          break;
          case 6:
          deltaRow = 1;
          deltaCol = -1;
          break;
          case 7:
          deltaRow = 0;
          deltaCol = -1;
          break;
          case 8:
          deltaRow = -1;
          deltaCol = -1;
          break;
          default:
          deltaRow = 0;
          deltaCol = 0;
          break;

        }


        if(board[(int)row - 97][(int)col - 97] == 'U')
        {
          if(checkLegalInDirection(board, n, (int)row - 97+deltaRow, (int)col - 97+deltaCol, colour, deltaRow, deltaCol))
          {
            optioncount++;
          }
        }
      }
      
    }
  }
  
  if(optioncount == 0)
  {
    printf("%c player has no valid move.\n", colour);
  }

  else{
    char opp = (colour == 'B')?'W':'B';
    int row, col;
    //char roww, coll;
    findSmarterMove(board, n, colour, &row, &col);
    printf("Testing AI move (row, col): %c%c\n", row + 'a', col + 'a');

    //printf("Enter move for colour %c (RowCol): ", colour);
    //scanf(" %c%c", &roww, &coll);
    //row = (int)roww - 97;
    //col = (int)coll - 97;

    int validcount = 0;
    for(int i = 0; i<8; i++)
    {
      int deltaRow, deltaCol;
      switch(i+1)
      {
        case 1:
        deltaRow = -1;
        deltaCol = 0;
        break;
        case 2:
        deltaRow = -1;
        deltaCol = 1;
        break;
        case 3:
        deltaRow = 0;
        deltaCol = 1;
        break;
        case 4:
        deltaRow = 1;
        deltaCol = 1;
        break;
        case 5:
        deltaRow = 1;
        deltaCol = 0;
        break;
        case 6:
        deltaRow = 1;
        deltaCol = -1;
        break;
        case 7:
        deltaRow = 0;
        deltaCol = -1;
        break;
        case 8:
        deltaRow = -1;
        deltaCol = -1;
        break;
        default:
        deltaRow = 0;
        deltaCol = 0;
        break;

      }
      //board[(int)row - 97][(int)col - 97] = 'U';
      if(checkLegalInDirection(board, n, row + deltaRow, col+deltaCol, colour, deltaRow, deltaCol) && board[row][col] == 'U')
      {
        validcount++;
        changeBoard(board, n, row+deltaRow, col+deltaCol, colour, deltaRow, deltaCol);
      }
    }

    //if(checkValidMove(player, row, col, Wa, Ba) != -1)
    //{
      //printf("Valid move.\n");
      //int direction = checkValidMove(player, row, col, Wa, Ba)+1;
      //changeBoard(board, n, (int)row - 97, (int)col - 97, direction, player);
      //printBoard(board, n);
    //}
    
    if(validcount == 0)
    {
      printf("Invalid move.\n%c player wins.", opp);
      exit(0);
    }
    else{
      board[row][col] = colour;
      printBoard(board, n);
    }
  }
  

}




int main(void) {

  char board[26][26];
  //char tempBoard[26][26];
  int n = 0;
  printf("Enter the board dimension: ");
  scanf("%d", &n);

  for(int i = 0; i<n; i++)
  {
    for(int j = 0; j<n; j++)
    {
      board[i][j] = 'U';
    }
  }
  board[(n/2) - 1][(n/2) - 1] = 'W';
  board[(n/2) - 1][n/2] = 'B';
  board[n/2][(n/2) - 1] = 'B';
  board[n/2][n/2] = 'W';

  char computercolour;

  printf("Computer plays (B/W): ");
  scanf(" %c", &computercolour);

  

  printBoard(board, n);//print initial board configuration

  while(!drawOrWin(board, n))
  {
    if(computercolour == 'B')
    {
      computerPlay(board, n, 'B');
      bool blah = drawOrWin(board, n);
      humanPlay(board, n, 'W');
    }
    else{
      humanPlay(board, n, 'B');
      bool blah = drawOrWin(board, n);
      computerPlay(board, n, 'W');
    }
  }
  return 0;
}

