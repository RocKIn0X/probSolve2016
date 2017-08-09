#include <iostream>

using namespace std;

int n, hp, maxScene;
int scene[1005];

void pass () {
    int tmpScene, tmpHp, count;

    maxScene = 0;

    for (int i = 0; i < n; i++) {
        tmpScene = i;
        tmpHp = hp;
        count = 0;

        while (true) {
            tmpHp -= scene[tmpScene];

            if (tmpHp < 0) {
                break;
            }

            tmpScene++;

            if (tmpScene == n) {
                tmpScene = 0;
            } 
            
            count++;

            if (tmpScene == i) {
                break;
            }
        }

        if (count > maxScene) {
            maxScene = count;
        }
    }
}

int main () {
    cin >> n >> hp;

    for (int i = 0; i < n; i++) {
        cin >> scene[i];
    }

    pass ();

    cout << maxScene << endl;

    return 0;
}