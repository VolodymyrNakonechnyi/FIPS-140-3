#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <bitset>
#include <cmath>
#include <vector>

std::string generateKey(int keyLength) {
    std::string keyStr = "";

    for (int i = 0; i < keyLength; i++) {
        int randomBit = std::rand() % 2;
        keyStr += std::to_string(randomBit);
    }

    return keyStr;
}

bool monobit_test(const std::string& key) {
    int onebitCount = std::count(key.begin(), key.end(), '1');
    return (onebitCount >= 9654 && onebitCount <= 10346);
}

bool test_max_series_length(const std::string& key) {
    int maxSet = 0;
    int currentSet = 0;
    char flag = key[0];

    for (char bit : key) {
        if (bit == flag) {
            currentSet++;
            maxSet = std::max(maxSet, currentSet);
        }
        else {
            flag = bit;
            currentSet = 1;
        }
    }

    return maxSet <= 36;
}

bool poker_test(const std::string& key) {
    const int step = 4;
    std::vector<int> array(16, 0);
    int k = key.length() / step;

    for (int i = 0; i < key.length() - step; i += step) {
        int fourbit = std::stoi(key.substr(i, step), 0, 2);
        array[fourbit]++;
    }

    int sum = 0;
    for (int count : array) {
        sum += count * count;
    }

    float pokerCoeff = (16.0 / k) * sum - k;
    return (pokerCoeff > 1.03 && pokerCoeff < 57.04);
}

bool check_series_lengths(const std::string& key) {
    int array[6] = { 0 };
    int set = 0;

    for (char bit : key) {
        if (bit == '1') {
            set++;
        }
        else {
            if (set >= 6) {
                array[5]++;
            }
            else if (set != 0) {
                array[set - 1]++;
            }
            set = 0;
        }
    }

    int ranges[6][2] = { { 2267, 2733 }, { 1079, 1421 }, { 502, 748 }, { 223, 402 }, { 90, 223 }, { 90, 223 } };

    for (int i = 0; i < 6; ++i) {
        if (array[i] < ranges[i][0] || array[i] > ranges[i][1]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::srand(std::time(nullptr));
    const std::string key = generateKey(20000);

    if (monobit_test(key)) {
        std::cout << "Monobit test: passed!" << std::endl;
    }
    else {
        std::cout << "Monobit test: failed" << std::endl;
    }

    if (test_max_series_length(key)) {
        std::cout << "Test max series length: passed!" << std::endl;
    }
    else {
        std::cout << "Test max series length" << std::endl;
    }

    if (poker_test(key)) {
        std::cout << "Poker test: passed!" << std::endl;
    }
    else {
        std::cout << "Poker test: failed" << std::endl;
    }

    if (check_series_lengths(key)) {
        std::cout << "Check series lengths test: passed!" << std::endl;
    }
    else {
        std::cout << "Check series lengths test: failed" << std::endl;
    }

    return 0;
}
