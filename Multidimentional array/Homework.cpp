#include <iostream>
#include <assert.h>
#include <vector>
#include <cmath>
#include <cstdlib>  // For srand() and rand()
#include <ctime>
#include <string> // For time()
using namespace std;

const int rows = 2;
const int cols = 3;

enum dir {RIGHT = 0,  DOWN,LEFT, UP, UP_LEFT,DOWN_RIGHT, UP_RIGHT, DOWN_LEFT};

int dir_r[] = {0,1,0,-1,-1,1,-1,1};
int dir_c[] = {1,0,-1,0,-1,1,1,-1};
void add(int arr1[rows][cols], int arr2[rows][cols], int result[rows][cols])
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}
void multiplication(int arr1[rows][cols],int arr2[cols][rows],int result [rows][cols])
{
    // Initialize the array
    for(int r = 0 ; r < rows; ++r)
        for(int c  = 0 ; c < rows; ++c)
            result[r][c] = 0 ;

    for(int r = 0 ; r < rows; ++r)
    {
        for(int c  = 0 ; c < rows; ++c)
        {
            for(int t = 0 ; t < cols ; ++t )
                result[r][c] += arr1[r][t] * arr2[t][c] ;
        }

    }
}
void print(int arr[rows][cols], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool magicSquare(const vector<vector<int>>& arr)   // you can check the size of the sum of each rows columns and the main diagonals by calculating
{
    bool passed  = true ;
    // this method : n*(n^2 +1)/2 for example the sum of 5*5 square is 65
    int rows = arr.size();
    if (rows == 0) return false; // handle empty array
    int cols = arr[0].size();
    if (cols == 0) return false;

    if(rows != cols)
    {
        cout <<"Function accept only square rows and cols"<<endl;
        return false;
    }
    int standardNum = 0 ;
    for(int i = 0 ; i < cols ; ++i)
    {
        standardNum += arr[0][i];

    }
    int sRow = 0,sCol = 0, sDiag1 = arr[0][0],sDiag2 = arr[0][rows - 1];
    //Check the sum of rows and columns and diagonal
    for(int r = 1 ; r < rows ; ++r )
    {
        for(int c = 0 ; c < cols; ++c)
        {
            sRow += arr[r][c];
            for(int t = 0 ; t< cols; ++t)
            {
                sCol += arr[t][c];
            }

            if(sCol != standardNum)
            {
                return false ;
            }
            sCol = 0 ;
        }
        if(sRow != standardNum)
        {
            return false;
        }
        sRow = 0 ;
        sDiag1 += arr[r][r];
        sDiag2 += arr[r][rows - 1 - r];
    }
    if(sDiag1 != standardNum ||sDiag2 != standardNum )
        return false;
    cout <<"Rows and Columns and diagonals test pass successfully!"<<endl;
    return passed ;
}
// work with directions
int sumWithDir(int r, int c,int dir, int steps,const vector<vector<int>>& square)
{
    int sum = 0 ;
    for(int i = 0 ; i< steps ; ++i)
    {
        sum += square[r][c];
        r += dir_r[dir];
        c += dir_c[dir];
    }
    return sum ;
}
bool magic_square(const vector<vector<int>>& square)
{
    int rows = square.size();
    if (rows == 0) return false; // handle empty array
    int cols = square[0].size();
    if (cols == 0) return false;
    //Check the sum of rows
    // this method : n*(n^2 +1)/2 for example the sum of 5*5 square is 65
    int standr = rows*(pow(rows,2) + 1) / 2 ;

    for(int r = 0 ; r< rows; ++r)
    {
        if(standr != sumWithDir(r,0,RIGHT,rows,square)) return false ;
        if(standr != sumWithDir(0,r,DOWN,rows,square)) return false ;

    }
    if(standr != sumWithDir(0,0,DOWN_RIGHT,rows,square)) return false ;
    if(standr != sumWithDir(0,rows - 1,DOWN_LEFT,rows,square)) return false;
    return true;
}

void spiralMatrixOrder(const vector<vector<int>>& square)
{
    int rows = square.size();
    int cols = square[0].size() ;
    int r = 0, c = 0 ;
    int dir = 0 ;
    for(int i = 0; i < cols*2 ; ++i )
    {
        for(int j = 0 ; j < rows - 1 ; ++j)  //RIGHT DOWN LEFT UP 0 1 2 3
        {
            cout << square[r][c] <<" ";
            r += dir_r[dir];
            c += dir_c[dir];
        }
        dir++;
        if(dir == 3 && i < 4) //
        {
            rows--;
        }
        if(dir > 3)
        {
            dir =0; //wrap dir = 0
        }
        if(i % 2 == 0 && i >= 4 )
        {
            rows--; // 6 8
        }
        if(cols*2 - i == 1 )
        {
            cout <<square[r][c];
        }

    }
    cout << endl;

}
// the proof solution of this problem
const int  N = 5 ;
void spiral(int arr[N][N])
{
    cout <<"Case N = "<<N<<": \t";
    int cnt = 0, r = 0, c = 0, steps = N, dir =0 ;
    while(cnt < N*N)
    {
        for(int s = 0 ; s<4 && cnt < N*N; ++s)
        {
            int m = steps - 1 ; // N-1 steps per direction
            if(s==3) --m;  // Except last direction,N-2

            for(int i = 0; i< m && cnt < N*N; ++i) // move in specific direction
            {
                cout << arr[r][c]<<" ";
                ++cnt, r += dir_r[dir],c += dir_c[dir]; // Move step
            }
            dir = (dir+1) %4 ; // change direction - wrap

        }
        cout << arr[r][c]<<" ";// Special handling for last element
        // Notice, our direction is already correct form last loop
        ++cnt,r += dir_r[dir], c += dir_c[dir]; // Move to new (N-2)x(N-2) matrix
        steps -=2;
    }
    cout << "\n";
}
void printGame(char matrix[3][3])
{
    cout <<" 0 1 2"<<endl;
    for(int r = 0; r<3; ++r)
    {
        cout <<r<<" ";
        for(int c = 0; c<3; ++c)
        {
            cout<<matrix[r][c];
        }
        cout <<endl;
    }
}
bool validateTheGame(char matrix[3][3],char standard)
{
    bool passed = true ;
    int c = 0 , r = 0 ;
    //Test all rows
    for(int t = 0 ; t < 3; ++t)
    {
        r = t;
        for(int i = 0 ; i<3; ++i)
        {
            if(matrix[r][c] != standard)
            {
                passed = false ;
                break;
            }
            r += dir_r[RIGHT];
            c += dir_c[RIGHT];
        }
        c = 0 ; //All the 3 rows
    }
    if(passed == false )
    {
        //Test all columns
        for(int t = 0 ; t < 3; ++t)
        {
            c = t;
            for(int i = 0; i< 3; ++i)
            {
                r += dir_r[DOWN];
                c += dir_c[DOWN];
                if(matrix[r][c] != standard)
                {
                    passed = false ;
                    break;
                }
                else
                {
                    passed = true;
                }
            }
            r = 0 ;
        }
        if(passed == false)
        {
            //Check all diagonals
            r = 0 ;
            c = 0 ;
            for(int i = 0; i< 3; ++i)
            {
                if(matrix[r][c] != standard)
                {
                    passed = false ;
                    break;
                }
                else
                {
                    passed = true;
                }
                r += dir_r[DOWN_RIGHT];
                c += dir_c[DOWN_RIGHT];

            }
            if(passed == false)
            {
                r = 2 ;
                c = 2 ;
                for(int i = 0; i< 3; ++i)
                {
                    if(matrix[r][c] != standard)
                    {
                        passed = false ;
                        break;
                    }
                    else
                    {
                        passed = true;
                    }
                    r += dir_r[DOWN_LEFT];
                    c += dir_c[DOWN_LEFT];
                }
                if(passed == false )
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true ;
    }
    return false ;
}
void gameInFunction()
{
    bool alive = true;
    char c1 = '.',c2 = '.';
    string name1 , name2  ;
    cout<<"This is a X-O Game "<<endl ;
    cout <<"Player number 1 entire your name \n";
    getline(cin,name1);
    cout << "Player number 2 entire your name \n";
    getline(cin,name2);
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random 0 or 1
    bool start = rand() % 2;  // This will give either 0 or 1
    if(start)
    {
        cout << name1<<" choose your symbol x or o ?";
        cin >> c1 ;
        while(cin.fail())
        {
            cout << "Write the correct character";
            cin >> c1;
        }
        switch(c1)
        {
        case 'o':
            c2 = 'x';
            break;
        case 'x':
            c2 = 'o';
            break;
        }
    }
    else
    {
        cout << name2<<" choose your symbol x or o ?";
        cin >>  c2 ;
        while(cin.fail())
        {
            cout << "Write the correct character";
            cin >> c2;
        }
        switch(c2)
        {
        case 'o':
            c1 = 'x';
            break;
        case 'x':
            c1 = 'o';
            break;
        }
    }
    cout <<name1<<" choose : "<<c1<<" "<<name2<<" choose : "<<c2<<endl;
    char matrix[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    printGame(matrix);
    int i = rand() % 2, r = 0, c = 0 ;

    while(alive)
    {
        if(i == 9){
            alive = false ;
            cout << "There is a draw !"<<endl;
            break;
        }

        if(i % 2 != 0)
        {
            cout <<name1<<" choose position ex:1 2 \n";
            cin >> r >> c;

            while(cin.fail() || r >= 3 || r < 0 || c >= 3 || c < 0)
            {
                cout <<"Bad input!, Entire again \n";
                cin >> r >> c;
            }
            while(matrix[r][c] != '.')
            {
                cout <<"This position is not empty, repeat again \n";
                cin>> r >> c;
                while(cin.fail() || r >= 3 || r < 0 || c >= 3 || c < 0)
                {
                    cout <<"Bad input!, Entire again \n";
                    cin >> r >> c;
                }
            }

            matrix[r][c] = c1;
        }
        else
        {
            cout <<name2<<" choose position ex:1 2 \n";
            cin >> r >> c;
            while(cin.fail() || r >= 3 || r < 0 || c >= 3 || c < 0)
            {
                cout <<"Bad input!, Entire again \n";
                cin >> r >> c;
            }
            while(matrix[r][c] != '.')
            {
                cout <<"This position is not empty, repeat again \n";
                cin>> r >> c;
                while(cin.fail() || r >= 3 || r < 0 || c >= 3 || c < 0)
                {
                    cout <<"Bad input!, Entire again \n";
                    cin >> r >> c;
                }
            }
            matrix[r][c] = c2;
        }
        printGame(matrix);
        i++;
        if(i > 2){
            if(validateTheGame(matrix,c2)){
                alive = false;
                cout << "End of the game"<<endl;
                cout << "The winner is the player 2"<<endl;
            }if(validateTheGame(matrix,c1)){
                alive = false;
                cout << "End of the game"<<endl;
                cout << "The winner is the player 1"<<endl;
            }
        }

    }

}

int main()
{
    // Initialize two 2D arrays
    int arr1[rows][cols] = {{1, 2, 3}, {4, 5, 6}};
    int arr2[rows][cols] = {{7, 8, 9}, {10, 11, 12}};
    int arr3[cols][rows] = {{5,7},{7,9},{7,9}};

    // Array to store the result
    int result[rows][cols] = {0};

    // Call the add function
    add(arr1, arr2, result);

    // Print the result
    cout << "Resultant array after addition:" << endl;
    print(result,rows,cols);
    cout << "Resultant array after multiplication: "<<endl;
    multiplication(arr1,arr3,result);
    print(arr1,rows,cols);
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
    print(result,rows,rows);
    vector<vector<int>> arr =
    {
        {17, 24,  1,  8, 15},
        {23,  5,  7, 14, 16},
        { 4,  6, 13, 20, 22},
        {10, 12, 19, 21,  3},
        {11, 18, 25,  2,  9}
    };
    cout << "{17, 24,  1,  8, 15},\n"
         << "{23,  5,  7, 14, 16},\n"
         << "{ 4,  6, 13, 20, 22},\n"
         << "{10, 12, 19, 21,  3},\n"
         << "{11, 18, 25,  2,  9} \n";
    cout << magicSquare(arr)<< endl; // success
    cout << magic_square(arr) <<endl;
    spiralMatrixOrder(arr); // test odd
    // Initialize the matrix with given values
    vector<vector<int>> matrix =
    {
        {1,   2,  3,  4},
        {5,   6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << endl ;
    spiralMatrixOrder(matrix); //test even
    cout <<endl ;
    //Test boundaries
    vector<vector<int>> matrix2 =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    spiralMatrixOrder(matrix2);
    vector<vector<int>> matrix0 =
    {
        {
            1
        }
    };
    spiralMatrixOrder(matrix0);
    //
    int arr7[5][5]
    {
        {17, 24,  1,  8, 15},
        {23,  5,  7, 14, 16},
        { 4,  6, 13, 20, 22},
        {10, 12, 19, 21,  3},
        {11, 18, 25,  2,  9}
    };
    spiral(arr7);
    gameInFunction();
    return 0 ;
}
