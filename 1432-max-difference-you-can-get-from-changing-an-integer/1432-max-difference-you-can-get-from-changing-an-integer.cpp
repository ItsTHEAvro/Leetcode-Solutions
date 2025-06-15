class Solution {
public:
    int maxDiff(int num) {
        using namespace std;

        string s = to_string(num);

        string a_s = s;
        char x_max = ' ';
        for (char c : a_s) {
            if (c != '9') {
                x_max = c;
                break;
            }
        }
        if (x_max != ' ') {
            for (char &c : a_s) {
                if (c == x_max) {
                    c = '9';
                }
            }
        }
        int a = stoi(a_s);

        string b_s = s;
        char x_min = ' ';
        char y_min = ' ';

        if (b_s[0] != '1') {
            x_min = b_s[0];
            y_min = '1';
        } else {
            for (size_t i = 1; i < b_s.length(); ++i) {
                if (b_s[i] != '0' && b_s[i] != '1') {
                    x_min = b_s[i];
                    y_min = '0';
                    break;
                }
            }
        }

        if (x_min != ' ') {
            for (char &c : b_s) {
                if (c == x_min) {
                    c = y_min;
                }
            }
        }
        int b = stoi(b_s);

        return a - b;
    }
};