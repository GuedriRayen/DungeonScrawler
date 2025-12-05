#ifndef INPUT_H
#define INPUT_H
struct Input {
    int hb;        // horizontal movement: -1 = left, +1 = right
    int vb;        // vertical movement: -1 = up, +1 = down
    bool exit;

    Input(int hb = 0, int vb = 0, bool exit = false) : hb(hb),vb(vb), exit(exit) {}
};
#endif // INPUT_H
