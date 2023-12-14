// #include <bits/stdc++.h>

// using namespace std;

// const int INF = 1e9 + 10;

// int vis[8][8];
// int level[8][8]; // Change 'lev' to 'level'

// int getX(string s)
// {
//     return s[0] - 'a';
// }

// int getY(string s)
// {
//     return s[1] - '1'; // Change to s[1]
// }

// bool isValid(int x, int y)
// {
//     return (x >= 0 && y >= 0 && x < 8 && y < 8);
// }

// vector<pair<int, int>> movements = {
//     {-1, 2},
//     {1, 2},
//     {-1, -2},
//     {1, -2},
//     {-2, -1},
//     {-2, 1},
//     {2, -1},
//     {2, 1},
// };

// int bfs(string src, string dest)
// {
//     int srcX = getX(src);
//     int srcY = getY(src);
//     int destX = getX(dest);
//     int destY = getY(dest);

//     queue<pair<int, int>> q;
//     q.push({srcX, srcY});
//     vis[srcX][srcY] = 1;
//     level[srcX][srcY] = 0; // Change 'lev' to 'level'

//     while (!q.empty())
//     {
//         pair<int, int> v = q.front();
//         q.pop();
//         int x = v.first, y = v.second;

//         for (auto movement : movements)
//         {
//             int childX = movement.first + x;
//             int childY = movement.second + y;

//             if (!isValid(childX, childY))
//                 continue;
//             if (!vis[childX][childY])
//             {
//                 q.push({childX, childY});
//                 level[childX][childY] = level[x][y] + 1; // Change 'lev' to 'level'
//                 vis[childX][childY] = 1;
//             }
//         }

//         if (level[x][y] != INF)
//         {
//             break;
//         }
//     }
//     return level[destX][destY];
// }

// void reset()
// {
//     for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 8; j++)
//         {
//             level[i][j] = INF; // Change 'lev' to 'level'
//             vis[i][j] = 0;
//         }
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     while (n--)
//     {
//         reset();

//         string s1, s2;
//         cin >> s1 >> s2;
//         cout << bfs(s1, s2) << "\n";
//     }
// }
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

int level[8][8];
int vis[8][8];

int getX(string s)
{
    return s[0] - 'a';
}

int getY(string s)
{
    return s[1] - '1'; // Since the board starts from 1
}

bool isValid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}

vector<pair<int, int>> movements = {
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

int bfs(string s1, string s2)
{
    int srcX = getX(s1);
    int srcY = getY(s1);
    int destX = getX(s2);
    int destY = getY(s2);

    queue<pair<int, int>> q;
    q.push({srcX, srcY});

    level[srcX][srcY] = 0;
    vis[srcX][srcY] = 1;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int x = p.first, y = p.second;
        q.pop();

        for (auto movement : movements)
        {
            int childX = movement.first + x;
            int childY = movement.second + y;

            if (isValid(childX, childY) && !vis[childX][childY])
            {
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
    }

    return level[destX][destY];
}

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    while (n--)
    {
        reset();
        string s1, s2;

        cin >> s1 >> s2;

        int result = bfs(s1, s2);
        if (result == INF)
        {
            cout << "No valid path found."
                 << "\n";
        }
        else
        {
            cout << "Minimum moves: " << result << "\n";
        }
    }
    return 0;
}
