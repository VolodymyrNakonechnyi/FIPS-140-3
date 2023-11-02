#include <iostream>
#include <cstdlib>
#include <string>
#include <bitset>
#include <ctime>
#include <cmath>
#include <string.h>
#include <vector>


std::string generateKey(int keyLength) {
    std::string keyStr = "";

    for (int i = 0; i < keyLength; i++) {
        int randomBit = std::round(std::rand() / static_cast<double>(RAND_MAX));
        keyStr += std::to_string(randomBit);
    }

    return keyStr;
}

bool monobit_test(std::string key) {
    int onebitCount = 0;

    for (int i = 0; i < key.length(); i++) {
        if (key[i] == '1') {
            onebitCount++;
        }
    }

    return (onebitCount < 10346 && onebitCount > 9654) ? true : false;
}

bool test_max_series_length(std::string key) {
    int set = 0;
    char flag = key[0];

    for (int i = 0; i < key.length(); i++) {
        if (set > 36) {
            std::cout << set;
            return false;
        }
        
        if (key[i] == flag) {
            set++;
        }
        else {
            flag = key[i];
            set = 0;
        }
    }
    
    return true;
}

bool poker_test(std::string key) {
    int step = 4;
    int array[16] = { 0 };
    int k = key.length() / step;
    
    for (int i = 0; i < key.length() - step; i += step) {
        int fourbit = std::stoi(key.substr(i, step), 0, 2);
        
        array[fourbit]++;
    }

    int sum = 0;

    for (int i = 0; i < pow(2, step); i++) {
        sum += std::pow(array[i], 2);
    }

    float pokerCoeff = (pow(2, step) / k) * (sum) - k;

    if (pokerCoeff > 1.03 && pokerCoeff < 57.04) {
        return true;
    }

    return false;

}


bool check_series_lengths(std::string key) {
    int array[6] = { 0 };
    int set = 0;
    char flag = '1';

    for (int i = 0; i < key.length(); i++) { // start the loop from 0

        if (key[i] == flag) {
            set++;
        }
        else {
            if (set >= 6) {
                array[5]++;
            }

            if (set != 0) {
                array[set - 1]++;
            }

            set = 0;
        }
    }

    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        int count = array[i];

        switch (i) {
        case 0:
            if (count < 2267 || count > 2733) {
                return false;
            }

            break;

        case 1:
            if (count < 1079 || count > 1421) {
                return false;
            }

            break;

        case 2:
            if (count < 502 || count > 748) {
                return false;
            }

            break;

        case 3:
            if (count < 223 || count > 402) {
                return false;
            }

            break;

        case 4:
            if (count < 90 || count > 223) {
                return false;
            }

            break;

        case 5:
            if (count < 90 || count >  223) {
                return false;
            }

            break;
        }
    }

    return true;
}



int main()
{
    std::srand(time(NULL));

    const std::string key = generateKey(20000);

    
    if (monobit_test(key)) {
        std::cout << "Level 1: passed!" << std::endl;
    }
    else {
        std::cout << "Level 1: failed" << std::endl;
    }
    
    //+++++++++++++++++++++++++++++++++++++++++++

    if (test_max_series_length(key)) {
        std::cout << "Level 2: passed!" << std::endl;
    }
    else {
        std::cout << "Level 2: failed" << std::endl;
    }

    //+++++++++++++++++++++++++++++++++++++++++++

    if (poker_test(key)) {
        std::cout << "Level 3: passed!" << std::endl;
    }
    else {
        std::cout << "Level 3: failed" << std::endl;
    }

    //+++++++++++++++++++++++++++++++++++++++++++

    if (check_series_lengths(key)) {
        std::cout << "Level 4: passed!" << std::endl;
    }
    else {
        std::cout << "Level 4: failed" << std::endl;
    }


    return 0;
}
