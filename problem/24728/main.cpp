#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "pancakecookie.h"

using namespace std;

vector<tuple<int, int, int>> positions;

PanCakeCookie::PanCakeCookie(int w, int h, int maxC, int u, int d) {
    positions.resize(w + 1);
    this->w = w;
    this->h = h;
    this->maxC = maxC;
    this->u = u;
    this->d = d;
    reset();
}

int PanCakeCookie::getX() { return this->x; }
int PanCakeCookie::getY() { return this->y; }
int PanCakeCookie::getU() { return this->u; }
int PanCakeCookie::getD() { return this->d; }
int PanCakeCookie::getScore() { return this->score; }
int PanCakeCookie::getC() { return this->curC; }

void PanCakeCookie::reset() {
    x = 0;
    y = 0;
    t = 0;
    score = 0;
    curC = maxC;
    positions[0] = {0, maxC, 0};
    int cur_c = maxC;
    int cur_y = 0;
    int cur_score = 0;
    for (int i = 1; i < w; i++) {
        if (cur_c > 0) {
            cur_c--;
            cur_y += u;
            if (cur_y > h) {
                cur_y = h;
            }
            cur_score += cur_y;
            positions[i] = {cur_y, cur_c, cur_score};
        } else {
            cur_c++;
            cur_y -= d;
            if (cur_y < 0) {
                cur_y = 0;
            }
            cur_score += cur_y;
            positions[i] = {cur_y, cur_c, cur_score};
        }
    }
}

void PanCakeCookie::setU(int x) {
    if (x >= 1 && x <= 1000) {
        u = x;
        reset();
    }
}

void PanCakeCookie::setD(int x) {
    if (x >= 1 && x <= 1000) {
        d = x;
        reset();
    }
}

void PanCakeCookie::setC(int x) {
    if (x >= 1 && x <= 1000) {
        maxC = x;
        reset();
    }
}

void PanCakeCookie::setT(int t) {
    if (t >= 0 && t < this->w) {
        this->t = t;
        x = t;
        auto [t1, t2, t3] = positions[t];
        y = t1;
        curC = t2;
        score = t3;
    }
}

#ifndef ONLINE_JUDGE
int w, h;
int expNum = 0;
int maxC, u, d;
int timeNum;
int curtime;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w >> h >> maxC >> u >> d;
    PanCakeCookie pancake = PanCakeCookie(w, h, maxC, u, d);
    cin >> timeNum;
    for (int i = 0; i < timeNum; i++) {
        cin >> curtime;
        pancake.setT(curtime);
        cout << pancake.getX() << " " << pancake.getY() << " " << pancake.getScore() << " " << pancake.getC() << " " << pancake.getU() << " " << pancake.getD() << "\n";
    }
    cin >> expNum;
    char type;
    int num;
    for (int i = 0; i < expNum; i++) {
        cin >> type >> num >> timeNum;
        if (type == 'u') {
            pancake.setU(num);
            for (int j = 0; j < timeNum; j++) {
                cin >> curtime;
                pancake.setT(curtime);
                cout << pancake.getX() << " " << pancake.getY() << " " << pancake.getScore() << " " << pancake.getC() << " " << pancake.getU() << " " << pancake.getD() << "\n";
            }
        } else if (type == 'd') {
            pancake.setD(num);
            for (int j = 0; j < timeNum; j++) {
                cin >> curtime;
                pancake.setT(curtime);
                cout << pancake.getX() << " " << pancake.getY() << " " << pancake.getScore() << " " << pancake.getC() << " " << pancake.getU() << " " << pancake.getD() << "\n";
            }
        } else if (type == 'c') {
            pancake.setC(num);
            for (int j = 0; j < timeNum; j++) {
                cin >> curtime;
                pancake.setT(curtime);
                cout << pancake.getX() << " " << pancake.getY() << " " << pancake.getScore() << " " << pancake.getC() << " " << pancake.getU() << " " << pancake.getD() << "\n";
            }
        } else {
            cout << "Invalid input\n";
            return 0;
        }
    }
    return 0;
}
#endif
