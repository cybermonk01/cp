class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        {
            return 1; // Increment perimeter only if it's outside the grid or water.
        }

        if (grid[i][j] == -1)
        {
            return 0; // Already visited cell.
        }

        grid[i][j] = -1;
        int perimeter = 0;
        perimeter += dfs(i + 1, j, grid);
        perimeter += dfs(i - 1, j, grid);
        perimeter += dfs(i, j + 1, grid);
        perimeter += dfs(i, j - 1, grid);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    perimeter += dfs(i, j, grid);
                }
            }
        }

        return perimeter;
    }
};
