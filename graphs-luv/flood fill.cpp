
void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image)
{

    int n = image.size();
    int m = image[0].size();

    if (i < 0 || j < 0 || j >= m || i >= n || image[i][j] != initialColor) // range me rahe aur image initial color ke barabr na ho to wapas
        return;

    image[i][j] = newColor;

    dfs(i - 1, j, initialColor, newColor, image);
    dfs(i + 1, j, initialColor, newColor, image);
    dfs(i, j - 1, initialColor, newColor, image);
    dfs(i, j + 1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{

    int initalColor = image[sr][sc];

    if (initialColor != color)
        dfs(i, j, initialColor, color, image);
    return image;
}