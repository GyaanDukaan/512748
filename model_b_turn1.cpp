
#include <iostream>
#include <vector>

using namespace std;

inline int midPointCircleAlgorithm(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    do
    {
        putPixel(xc + x, yc + y);
        putPixel(xc - x, yc + y);
        putPixel(xc + x, yc - y);
        putPixel(xc - x, yc - y);

        int error = 2 * p + 1;
        if (error <= 0)
        {
            x++;
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    } while (x <= y);
}

// Put a pixel at the position (x, y)
inline void putPixel(int x, int y, vector<vector<bool>>& grid)
{
    if (0 <= x && x < grid.size() && 0 <= y && y < grid[x].size()) {
        grid[x][y] = true;
    }
}

int main()
{
    int radius = 10;
    int xcenter = 20;
    int ycenter = 20;
    int width = 40;
    int height = 40;

    vector<vector<bool>> grid(width, vector<bool>(height, false));

    // Clear the grid to black
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            grid[i][j] = false;
        }
    }

    midPointCircleAlgorithm(xcenter, ycenter, radius);

    // Display the circle
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (grid[i][j])
            {
                cout << "* ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }

    return 0;
}
