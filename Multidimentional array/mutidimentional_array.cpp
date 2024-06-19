#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 4, COLS = 3, SLICE = 2, BLOCK = 2;
void print1(int arr[ROWS][COLS])
{
    for (int r = 0; r < ROWS; ++r) // Row-major order
    {
        for (int c = 0; c < COLS; ++c)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
}
void print(const vector<int> &arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Convert from 3D to 1D array
vector<int> convert3DTo1D(int arr[SLICE][ROWS][COLS])
{
    vector<int> arr2(SLICE * ROWS * COLS, 0);
    // method idx = i�(ROWS�COLS)+j�COLS +k ;

    int idx = 0;
    for (int s = 0; s < SLICE; ++s)
    {
        for (int r = 0; r < ROWS; ++r)
        {
            for (int c = 0; c < COLS; ++c)
            {
                arr2[idx++] = arr[s][r][c];
            }
        }
    }
    return arr2;
}
vector<int> convert4DTo1D(int arr[BLOCK][SLICE][ROWS][COLS])
{
    vector<int> arr2(BLOCK * SLICE * ROWS * COLS);
    int idx = 0; // idx=i�(SLICE�ROWS�COLS)+j�(ROWS�COLS)+k�COLS+l
    for (int b = 0; b < BLOCK; ++b)
    {
        for (int s = 0; s < SLICE; ++s)
        {
            for (int r = 0; r < ROWS; ++r)
            {
                for (int c = 0; c < COLS; ++c)
                {
                    arr2[idx++] = arr[b][s][r][c];
                }
            }
        }
    }
    return arr2;
}
int main()
{
    // Definition
    int val[ROWS][COLS] = {{1, 5, 3}, {8, 6, 9}, {5, 6, 9}, {7, 8, 9}};
    // int arr[ROWS*COLS]  = {1,5,3,8,6,9,5,6,9,7,8,9};
    int arr[ROWS * COLS] = {0}; // initialize with 0s
    int arr2[ROWS][COLS];
    print1(val);
    // Covert this arr2D to a 1D array
    // by applying this method int idx = r * COLS + c
    //  r is the position of the element in the rows of the array and c is the position of column in the array
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            arr[r * COLS + c] = val[r][c];
            cout << arr[r * COLS + c] << " ";
        }
    }
    cout << endl;
    // From the index to rows and cols
    for (int i = 0; i < ROWS * COLS; i++)
    {
        int rr = i / COLS;
        int cc = i % COLS;
        arr2[rr][cc] = arr[i];
    }
    print1(arr2);
    int arr3[2][4][3] = {{{1, 5, 3}, {8, 6, 9}, {5, 6, 9}, {7, 8, 9}}, {{1, 5, 3}, {8, 6, 9}, {5, 6, 9}, {7, 8, 9}}};
    int arr4[2][2][4][3] = {
        {{{1, 5, 3}, {8, 6, 9}, {5, 6, 9}, {7, 8, 9}}, {{1, 5, 3}, {8, 6, 9}, {5, 6, 9}, {7, 8, 9}}},
        {{{1, 5, 3}, {8, 6, 9}, {5, 6, 9}, {7, 8, 9}},
         {{1, 5, 3}, {8, 6, 9}, {5, 6, 9}, {7, 8, 9}}}};
    vector<int> arr3To1D(2 * 4 * 3);
    arr3To1D = convert3DTo1D(arr3);
    vector<int> arr4To1D(BLOCK * SLICE * ROWS * COLS);
    arr4To1D = convert4DTo1D(arr4);
    print(arr3To1D, 2 * 4 * 3);
    print(arr4To1D, BLOCK * SLICE * ROWS * COLS);
    return 0;
}
