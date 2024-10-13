#include<bits/stdc++.h>

using namespace std;

bool ifIsPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

//bool ifIsHe(string str) {
//    int map[26] = {0};
//    for (int i = 0; i < str.length(); ++i) {
//        map[str[i] - 'a']++;
//    }
//    for (int m: map) {
//        if (m > 1) {
//            return false;
//        }
//    }
//    return true;
//}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string str;
        int map[26] = {0};
        bool flag = false;
        cin >> str;
        int strLen = str.length();
        for (int j = 1; j < strLen; ++j) {
            map[str[j - 1] - 'a']++;
            for (int m: map) {
                if (m > 1) {
                    printf("NaN\n");
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
            if (ifIsPalindrome(str.substr(j, strLen))) {
                printf("HE\n");
                flag = true;
                break;
            }
        }
        if (!flag) {
            printf("NaN\n");
        }
    }
}