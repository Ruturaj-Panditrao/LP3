// N Queens with 1 Queen Placed Beforehand
#include <vector>
#include <iostream>
using namespace std;
// Consider filling from Left to Right

bool sol = false;
int firstRow, firstCol;
bool isSafe(int row, int col, vector<vector<string>>&board, int n)
{
    int dupcol = col;
    int duprow = row;
    
    // Check Left in Row
    // Only Col decreases

    while(col>=0)
    {
        if(board[row][col]=="Q") return false;
        col--;
    }

    // Check Upper Left Diagonal
    // Row and Col both Decrease

    col = dupcol;
    row = duprow;

    while(col>=0 && row>=0)
    {
        if(board[row][col]=="Q") return false;
        row--; col--;
    }

    col = dupcol;
    row = duprow;

    // Check Down Left Diagonal
    // Row Increases, Col Decreases

    while(col>=0 && row<n)
    {
        if(board[row][col]=="Q") return false;
        col--; row++;
    }

    col = dupcol;
    row = duprow;

    // Check Right in Row
    // Only Col Increases

    while(col<n)
    {
        if(board[row][col]=="Q") return false;
        col++;
    }

    col = dupcol;
    row = duprow;

    // Check Upper Right Diagonal
    // Col increases, Row decreases

    while(row>=0 && col<n)
    {
        if(board[row][col]=="Q") return false;
        col++; row--;
    }

    col = dupcol;
    row = duprow;

    // Check Down Right
    // Col increases, Row increases

    while(col<n && row<n)
    {
        if(board[row][col]=="Q") return false;
        row++; col++;
    }

    col = dupcol;
    row = duprow;

    // Check Up
    // Col decreases

    while(col>=0)
    {
        if(board[row][col]=="Q") return false;
        col--;
    }

    col = dupcol;
    row = duprow;

    // Check Down
    // Col Increases

    while(col<n)
    {
        if(board[row][col]=="Q") return false;
        col++;
    }
    
    return true;
}

void printboard(vector<vector<string>>&board, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }

        cout<<endl;
    }
    
}
void solve(int col, int n, vector<vector<string>>&board)
{
    // Since the Queen is already placed in this Column, Move to the Next Column
    if(col==firstCol) 
    {   
        solve(col+1,n,board);
    }
    else
    {
    if(col==n)
    {
        printboard(board,n);
        sol = true;
        cout<<endl;
        return;
    }

    for(int row = 0; row<n; row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col] = "Q";
            solve(col+1,n,board);
            board[row][col] =".";
        }
    }
    }
}
int main()
{
    int n;
    cout<<"Enter n as 4 or 8 : ";
    cin>>n;
    vector<vector<string>>board(n,vector<string>(n,"."));
    cout<<"\nEnter the coordinates for the first queen (row and column): ";
    cin>>firstRow>>firstCol;
    board[firstRow][firstCol] = "Q";
    cout<<"Printing Solutions for a Board with First Queen Placed : "<<endl;
    solve(0,n,board);
    if(sol==false) cout<<"No Solution for this Configuration Exists"<<endl;
}

// Time Complexity : O(N!)
