#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull sumDigitsUpto(ull n){
    if ((long long)n < 0) return 0;
    ull sum = 0, place = 1;
    while (place <= n) {
        ull high = n / (place * 10);
        ull current = (n / place) % 10;
        ull low = n % place;
        sum += high * 45 * place;
        sum += (current * (current - 1) / 2) * place;
        sum += current * (low + 1);
        place *= 10;
    }
    return sum;
}

ull calculateSum(ull k) {
    ull result = 0;
    ull remaining = k;
    ull powersOf10[20];
    powersOf10[0] = 1;
    for (int i = 1; i < 20; i++) powersOf10[i] = powersOf10[i - 1] * 10ULL;

    for (int digitLen = 1; digitLen < 19; digitLen++) {
        ull countNumbers = 9ULL * powersOf10[digitLen - 1];
        bool canSubtract = false;

        if (countNumbers != 0 && remaining / digitLen >= countNumbers) {
            canSubtract = true;
        }

        if (canSubtract) {
            ull lowRange = powersOf10[digitLen - 1];
            ull highRange = powersOf10[digitLen] - 1;
            result += sumDigitsUpto(highRange) - sumDigitsUpto(lowRange - 1);
            remaining -= countNumbers * digitLen;
        } else {
            ull fullNums = remaining / digitLen;
            ull leftoverDigits = remaining % digitLen;
            ull baseNum = powersOf10[digitLen - 1];

            if (fullNums > 0) {
                ull highNum = baseNum + fullNums - 1;
                result += sumDigitsUpto(highNum) - sumDigitsUpto(baseNum - 1);
            }

            if (leftoverDigits > 0) {
                ull number = baseNum + fullNums;
                string numStr = to_string(number);
                for (ull i = 0; i < leftoverDigits; i++) {
                    result += (numStr[i] - '0');
                }
            }
            break;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ull k;
        cin >> k;
        cout << calculateSum(k) << "\n";
    }

    return 0;
}
