#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <cstdlib>
using namespace std;

const bool debug = false;

typedef long long i64;
#define None (-1)
typedef struct Area {
    char cmd;
    i64 p;
    i64 frontiers[4][2][2];
    Area() {
        this->cmd = ' ';
        this->p = None;
        for(i64 dp = 0; dp < 4; ++dp) {
            for (i64 cc = 0; cc < 2; ++cc) {
                for (i64 i = 0; i < 2; ++i) {
                    this->frontiers[dp][cc][i] = None;
                }
            }
        }
    }
} Area;

vector<Area> areas;
vector<vector<char>> raw_code;
vector<vector<i64>> area_idxs;
i64 r, c;
vector<char> input_data;
i64 input_idx;
vector<char> output;
vector<i64> stack;
i64 dp, cc;
i64 r_sum;
bool terminated;

void init(const char *input) {
    r = 0;
    c = 0;
    input_data.clear();
    for (char c: string(input)) {
        input_data.push_back(c);
    }
    input_idx = 0;
    output.clear();
    stack.clear();
    dp = 0;
    cc = 0;
    r_sum = 0;
    terminated = false;
}

void take_input() {
    if ((unsigned long long) input_idx >= input_data.size()) { return; }
    stack.push_back(input_data[input_idx]);
    input_idx += 1;
}

void do_output() {
    if (stack.empty()) { return; }
    i64 c = stack.back(); stack.pop_back();
    output.push_back(c & 255);
}

void push_const(i64 p) {
    stack.push_back(p);
}

void pop_discard() {
    if (stack.empty()) { return; }
    stack.pop_back();
}

void add() {
    if (stack.size() < 2) { return; }
    i64 x = stack.back(); stack.pop_back();
    i64 y = stack.back(); stack.pop_back();
    stack.push_back(y + x);
}

void sub() {
    if (stack.size() < 2) { return; }
    i64 x = stack.back(); stack.pop_back();
    i64 y = stack.back(); stack.pop_back();
    stack.push_back(y - x);
}

void mul() {
    if (stack.size() < 2) { return; }
    i64 x = stack.back(); stack.pop_back();
    i64 y = stack.back(); stack.pop_back();
    stack.push_back(y * x);
}

void div() {
    if (stack.size() < 2) { return; }
    i64 x = stack.back();
    if (x == 0) { return; }
    stack.pop_back();
    i64 y = stack.back(); stack.pop_back();
    i64 div = y / x;
    i64 rem = y % x;
    if (rem != 0 && (y >= 0) != (x >= 0)) { div -= 1; rem += x; }
    stack.push_back(div);
}

void rem() {
    if (stack.size() < 2) { return; }
    i64 x = stack.back();
    if (x == 0) { return; }
    stack.pop_back();
    i64 y = stack.back(); stack.pop_back();
    i64 div = y / x;
    i64 rem = y % x;
    if (rem != 0 && (y >= 0) != (x >= 0)) { div -= 1; rem += x; }
    stack.push_back(rem);
}

void gt() {
    if (stack.size() < 2) { return; }
    i64 x = stack.back(); stack.pop_back();
    i64 y = stack.back(); stack.pop_back();
    stack.push_back(y > x);
}

void unnot() {
    if (stack.empty()) { return; }
    i64 x = stack.back(); stack.pop_back();
    stack.push_back(x == 0);
}

void add_dp() {
    if (stack.empty()) { return; }
    i64 x = stack.back(); stack.pop_back();
    dp = (dp + x) & 3;
}

void add_cc() {
    if (stack.empty()) { return; }
    i64 x = stack.back(); stack.pop_back();
    cc = (cc + x) & 1;
}

void dup() {
    if (stack.empty()) { return; }
    i64 x = stack.back(); stack.push_back(x);
}

void roll() {
    if (stack.size() < 2) { return; }
    i64 x = stack.back(); stack.pop_back();
    i64 y = stack.back(); stack.pop_back();
    if (y <= 0 || (unsigned long long) y > stack.size()) {
        stack.push_back(y); stack.push_back(x); return;
    }
    r_sum += y;
    x = x % y;
    if (x < 0) { x += y; } // y > 0 guaranteed
    if (x == 0) { return; }
    x = y - x;
    i64 base = stack.size() - y;
    vector<i64> rolled {};
    for (i64 xx = base + x; xx < base + y; ++xx) {
        rolled.push_back(stack[xx]);
    }
    for (i64 xx = base; xx < base + x; ++xx) {
        rolled.push_back(stack[xx]);
    }
    for (i64 xx = 0; xx < y; ++xx) {
        stack[base + xx] = rolled[xx];
    }
}

void step() {
    Area *area = &areas[area_idxs[r][c]];
    if (debug) { cerr << "cmd: " << area->cmd << "\n"; }
    switch (area->cmd) {
        case 'I': take_input(); break;
        case 'O': do_output(); break;
        case 'P': push_const(area->p); break;
        case 'p': pop_discard(); break;
        case '+': add(); break;
        case '-': sub(); break;
        case '*': mul(); break;
        case '/': div(); break;
        case '%': rem(); break;
        case '!': unnot(); break;
        case '>': gt(); break;
        case 'D': add_dp(); break;
        case 'C': add_cc(); break;
        case 'd': dup(); break;
        case 'r': roll(); break;
        default:
            cerr << "Unexpected char `" << area->cmd << "` at row " << r << ", col " << c << "\n";
            exit(1);
            break;
    }
    if (debug) {
        cerr << "stack: ";
        for (i64 x: stack) { cerr << x << " "; }
        cerr << "\n";
    }
    i64 i = 0;
    for (; i < 8; ++i) {
        i64 frontr = area->frontiers[dp][cc][0];
        i64 frontc = area->frontiers[dp][cc][1];
        if (frontr == None) {
            if (i % 2 == 1) { dp = (dp + 1) & 3; }
            else { cc = (cc + 1) & 1; }
            continue;
        }
        r = frontr;
        c = frontc;
        break;
    }
    if (i == 8) { terminated = true; }
}

void interpret(i64 limit=None, i64 r_limit=None) {
    i64 steps = 0;
    for (; (limit == None || steps < limit) && (r_limit == None || r_sum <= r_limit); ++steps) {
        step();
        if (terminated) { break; }
    }
    if (!terminated && steps == limit) {
        cerr << "Program not finished in " << limit << " steps\n";
        exit(1);
    }
    if (r_sum > r_limit) {
        cerr << "r command costs exceeded limit of " << r_limit << "\n";
        exit(1);
    }
}

void process() {
    // assume raw_code is initialized; populates areas and area_idxs
    i64 rows = raw_code.size();
    i64 cols = raw_code[0].size();
    areas.clear();
    area_idxs.clear();
    for (i64 r0 = 0; r0 < rows; ++r0) {
        area_idxs.push_back({});
        for (i64 c0 = 0; c0 < cols; ++c0) {
            area_idxs[r0].push_back(None);
        }
    }
    for (i64 r0 = 0; r0 < rows; ++r0) {
        for (i64 c0 = 0; c0 < cols; ++c0) {
            char cur_cmd = raw_code[r0][c0];
            if (cur_cmd == ' ') { continue; }
            if (area_idxs[r0][c0] != None) { continue; }
            Area cur_area = Area();
            cur_area.cmd = cur_cmd;
            for (i64 dp = 0; dp < 4; ++dp) {
                for (i64 cc = 0; cc < 2; ++cc) {
                    cur_area.frontiers[dp][cc][0] = r0;
                    cur_area.frontiers[dp][cc][1] = c0;
                }
            }
            vector<pair<i64, i64>> stack{};
            stack.push_back({r0, c0});
            i64 p = 0;
            while (!stack.empty()) {
                pair<i64, i64> rc = stack.back();
                stack.pop_back();
                i64 r = rc.first;
                i64 c = rc.second;
                area_idxs[r][c] = areas.size();
                p += 1;
                i64 dp = 0, cc = 0;
                i64 fr = cur_area.frontiers[dp][cc][0];
                i64 fc = cur_area.frontiers[dp][cc][1];
                if (c > fc || (c == fc && r < fr)) {
                    cur_area.frontiers[dp][cc][0] = r;
                    cur_area.frontiers[dp][cc][1] = c;
                }
                dp = 0, cc = 1;
                fr = cur_area.frontiers[dp][cc][0];
                fc = cur_area.frontiers[dp][cc][1];
                if (c > fc || (c == fc && r > fr)) {
                    cur_area.frontiers[dp][cc][0] = r;
                    cur_area.frontiers[dp][cc][1] = c;
                }
                dp = 1, cc = 0;
                fr = cur_area.frontiers[dp][cc][0];
                fc = cur_area.frontiers[dp][cc][1];
                if (r > fr || (r == fr && c > fc)) {
                    cur_area.frontiers[dp][cc][0] = r;
                    cur_area.frontiers[dp][cc][1] = c;
                }
                dp = 1, cc = 1;
                fr = cur_area.frontiers[dp][cc][0];
                fc = cur_area.frontiers[dp][cc][1];
                if (r > fr || (r == fr && c < fc)) {
                    cur_area.frontiers[dp][cc][0] = r;
                    cur_area.frontiers[dp][cc][1] = c;
                }
                dp = 2, cc = 0;
                fr = cur_area.frontiers[dp][cc][0];
                fc = cur_area.frontiers[dp][cc][1];
                if (c < fc || (c == fc && r > fr)) {
                    cur_area.frontiers[dp][cc][0] = r;
                    cur_area.frontiers[dp][cc][1] = c;
                }
                dp = 2, cc = 1;
                fr = cur_area.frontiers[dp][cc][0];
                fc = cur_area.frontiers[dp][cc][1];
                if (c < fc || (c == fc && r < fr)) {
                    cur_area.frontiers[dp][cc][0] = r;
                    cur_area.frontiers[dp][cc][1] = c;
                }
                dp = 3, cc = 0;
                fr = cur_area.frontiers[dp][cc][0];
                fc = cur_area.frontiers[dp][cc][1];
                if (r < fr || (r == fr && c < fc)) {
                    cur_area.frontiers[dp][cc][0] = r;
                    cur_area.frontiers[dp][cc][1] = c;
                }
                dp = 3, cc = 1;
                fr = cur_area.frontiers[dp][cc][0];
                fc = cur_area.frontiers[dp][cc][1];
                if (r < fr || (r == fr && c > fc)) {
                    cur_area.frontiers[dp][cc][0] = r;
                    cur_area.frontiers[dp][cc][1] = c;
                }

                if (r > 0 && raw_code[r-1][c] == cur_cmd && area_idxs[r-1][c] == None) {
                    area_idxs[r-1][c] = areas.size();
                    stack.push_back({r-1, c});
                }
                if (r < rows-1 && raw_code[r+1][c] == cur_cmd && area_idxs[r+1][c] == None) {
                    area_idxs[r+1][c] = areas.size();
                    stack.push_back({r+1, c});
                }
                if (c > 0 && raw_code[r][c-1] == cur_cmd && area_idxs[r][c-1] == None) {
                    area_idxs[r][c-1] = areas.size();
                    stack.push_back({r, c-1});
                }
                if (c < cols-1 && raw_code[r][c+1] == cur_cmd && area_idxs[r][c+1] == None) {
                    area_idxs[r][c+1] = areas.size();
                    stack.push_back({r, c+1});
                }
            }
            i64 step_r[4] = {0, 1, 0, -1};
            i64 step_c[4] = {1, 0, -1, 0};
            for (i64 dp = 0; dp < 4; ++dp) {
                i64 rstep = step_r[dp];
                i64 cstep = step_c[dp];
                for (i64 cc = 0; cc < 2; ++cc) {
                    i64 frontr = cur_area.frontiers[dp][cc][0];
                    i64 frontc = cur_area.frontiers[dp][cc][1];
                    i64 nextr = frontr + rstep;
                    i64 nextc = frontc + cstep;
                    if (0 <= nextr && nextr < rows && 0 <= nextc && nextc < cols && raw_code[nextr][nextc] != ' ') {
                        cur_area.frontiers[dp][cc][0] = nextr;
                        cur_area.frontiers[dp][cc][1] = nextc;
                    } else {
                        cur_area.frontiers[dp][cc][0] = None;
                        cur_area.frontiers[dp][cc][1] = None;
                    }
                }
            }
            cur_area.p = p;
            cur_area.cmd = cur_cmd;
            areas.push_back(cur_area);
        }
    }
}

char inputbuf[1000000];

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Filename not provided\n";
        exit(1);
    }
    raw_code.clear();
    string line;
    ifstream in(argv[1]);
    i64 maxlen = 0;
    while (getline(in, line)) {
        vector<char> chars {};
        for (char c: line) {
            chars.push_back(c);
        }
        if ((unsigned long long) maxlen < chars.size()) { maxlen = chars.size(); }
        raw_code.push_back(chars);
    }
    if (raw_code.size() * maxlen > 1000000) {
        cerr << "rows * cols > 1000000\n";
        exit(1);
    }
    for (i64 i = 0; (unsigned long long) i < raw_code.size(); ++i) {
        i64 diff = maxlen - raw_code[i].size();
        for (i64 j = 0; j < diff; ++j) {
            raw_code[i].push_back(' ');
        }
    }
    if (raw_code.size() * maxlen == 0 || raw_code[0][0] == ' ') {
        cerr << "top left is blank\n";
        exit(1);
    }
    process();
    cin.get(inputbuf, 1000000, None);
    init(inputbuf);
    interpret(1000000, 1000000);
    for (char c: output) {
        cout << c;
    }
    return 0;
}