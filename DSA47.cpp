#include<iostream>
#include<vector>
using namespace std;
class solution
{
    public:
    bool possible(vector<vector<char>>&ans,int row, int column, char value)
    {
        //check the same data is available or not in same row.
        for(int i=0; i<9; i++)
        {
            if(ans[row][i]==value)
            {
                return false;
            }
        }
        //check the same data is available or not in same column
        for(int i=0; i<9; i++)
        {
            if(ans[i][column]==value)
            {
                return false;
            }
        }
        int strow=(row/3)*3;
        int stcolum=(column/3)*3;
        for(int i=strow; i<=strow+2; i++)
        {
            for(int j= stcolum; j<=stcolum+2; j++)
            {
                if(ans[i][j]==value)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool pushreal(vector<vector<char>>&name, int row, int column)
    {
        int next_row=row;
        int next_column=column+1;
        if(next_column==9)
        {
            next_row=row+1;
            next_column=0;
        }
        if(row==9)
        {
             return true;
        }
        if(name[row][column]!='.')
        {
            return pushreal(name,next_row,next_column);
        }
        for(char i='1'; i<='9'; i++)
        {

            if(possible(name, row, column,i))
            {
                name[row][column]=i;
                if(pushreal(name,next_row,next_column))
                {
                    return true;
                }
                name[row][column]='.';//back tracking
            }
        }
        return false;
    }
};
int main()
{
    solution r;
    vector<vector<char>>name=
    {
    {'2','.','.','.','.','1','4','.','.'},
    {'7','.','.','.','9','.','.','.','.'},
    {'.','3','.','.','5','6','.','.','2'},
    {'.','7','.','2','1','8','5','.','6'},
    {'1','.','2','.','.','5','9','3','.'},
    {'.','6','.','.','.','9','.','.','.'},
    {'6','.','.','.','8','.','.','.','.'},
    {'9','.','.','5','.','3','8','.','.'},
    {'4','1','8','.','2','.','.','6','5'}};
    cout<<"your entered sudoku is: "<<endl;
    for(auto val:name)
    {
        for(char res:val)
        {
            cout<<res<<" ";
        }cout<<endl;
    }
    cout<<"your solve sudoku is : "<<endl;
    if(r.pushreal(name,0,0))
    {
        for(auto val:name)
        {
            for(char res:val)
            {
                cout<<res<<" ";
            }cout<<endl;
        }
    }
    else
    {
        cout<<"the sudoku is not solve because preentered element place at wrong position: "<<endl;
    }
    return 0;
}