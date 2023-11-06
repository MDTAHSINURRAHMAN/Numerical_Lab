#include <bits/stdc++.h>
using namespace std;

map<int, int> pw;

void string_to_coefficient(string s) {
    for (int i = 0; i < s.length(); i++) {
        int coeff = atol(s.substr(i).c_str());
        i += log10(abs(coeff)) + 1;
        int power = 0;
        for (int j = i; j < s.length(); j++) {
            if (s[j] == '^') {
                power = atol(s.substr(j + 1).c_str());
                i = j + log10(power) + 1;
                break;
            }
        }
        pw[power] += coeff;
    }
}

float fx(float x) {
    float ans = 0;
    for (auto it : pw)
        ans += it.second * pow(x * 1.0, it.first);
    return ans;
}

void false_position() {
    double a, b, c;
    cout << "Enter the interval [a, b] for root approximation: ";
    cin >> a >> b;
    int it = 0;

    while (it++ < 100) {
        c = (a * fx(b) - b * fx(a)) / (fx(b) - fx(a));
        cout << "Iteration " << it << ": " << c << endl;

        if (fx(c) == 0.0 || ((b - a) / 2) < 0.0001) {
            cout << "Root: " << c << endl;
            return;
        }

        if (fx(c) * fx(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "Estimated Root: " << c << endl;
}

int main() {
    cout << "Enter the equation (e.g., 1x^2-4x^1-10): ";
    string s;
    cin >> s;
    string_to_coefficient(s);
    for (auto it : pw)
        cout << it.second << "x^" << it.first << " ";
    cout << endl;

    false_position();

    return 0;
}
