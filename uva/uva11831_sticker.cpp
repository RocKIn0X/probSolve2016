#include <cstdio>
#include <string.h>
#define MAX 100


using namespace std;

int n, m, s, x, y;
char state;
char map[MAX][MAX];
char cmd[50005];
bool visited[MAX][MAX];

void init () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

void findStart () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'L' || map[i][j] == 'O') {
                x = i;
                y = j;
                state = map[i][j];
                visited[i][j] = true;
                return;
            }
        }
    }
}

int main () {
    while (true) {
        int count = 0;

        scanf(" %d %d %d", &n, &m, &s);

        init();

        if (n == 0 && m == 0 && s == 0) break;

        for (int i = 0; i < n; i++) {
            scanf("%s", map[i]);
        }

        scanf("%s", cmd);

        findStart();

        for (int i = 0; i < s; i++) {
            if (state == 'N') {
                if (cmd[i] == 'D') state = 'L';
                else if (cmd[i] == 'E') state = 'O';
                else if (cmd[i] == 'F') {
                    if (x - 1 < 0) {
                        continue;
                    }

                    if (map[x-1][y] == '*') {
                        if (visited[x-1][y] == false)   count++;
                        x = x - 1;
                        visited[x][y] = true;
                    } else if (map[x-1][y] == '#') {
                        continue;
                    } else {
                        x = x - 1;
                        visited[x][y] = true;
                    }
                }
            
            } else if (state == 'S') {              
                if (cmd[i] == 'D') state = 'O';
                else if (cmd[i] == 'E') state = 'L';
                else if (cmd[i] == 'F') {

                    if (x + 1 >= n) {
                        continue;
                    }

                    if (map[x+1][y] == '*') {
                        if (visited[x+1][y] == false)   count++;
                        x = x + 1;
                        visited[x][y] = true;
                    } else if (map[x+1][y] == '#') {
                        continue;
                    } else {
                        x = x + 1;
                        visited[x][y] = true;
                    }
                }
            
            } else if (state == 'L') {
                if (cmd[i] == 'D') state = 'S';
                else if (cmd[i] == 'E') state = 'N';
                else if (cmd[i] == 'F') {
                
                    if (y + 1 >= m) {
                        continue;
                    }

                    if (map[x][y+1] == '*') {
                        if (visited[x][y+1] == false)   count++;
                        y = y + 1;
                        visited[x][y] = true;
                    } else if (map[x][y+1] == '#') {
                        continue;
                    } else {
                        y = y + 1;
                        visited[x][y] = true;
                    }
                }
            
            } else if (state == 'O') {
                if (cmd[i] == 'D') state = 'N';
                else if (cmd[i] == 'E') state = 'S';
                else if (cmd[i] == 'F') {

                    if (y - 1 < 0) {
                        continue;
                    }

                    if (map[x][y-1] == '*') {
                        if (visited[x][y-1] == false)   count++;
                        y = y - 1;
                        visited[x][y] = true;
                    } else if (map[x][y-1] == '#') {
                        continue;
                    } else {
                        y = y - 1;
                        visited[x][y] = true;
                    }
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}