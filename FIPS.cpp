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

    //std::cout << keyStr;

    return keyStr;
}

bool level1(std::string key) {
    int onebitCount = 0;

    for (int i = 0; i < key.length(); i++) {
        if (key[i] == '1') {
            onebitCount++;
        }
    }

    std::cout << onebitCount << std::endl;

    return (onebitCount < 10346 && onebitCount > 9654) ? true : false;
}

bool level2(std::string key) {
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

bool level3(std::string key) {
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


bool level4(std::string key) {
    int array[6] = { 0 };
    int set = 0;
    char flag = '1';

    for (int i = 0; i < key.length(); i++) {

        if (key[i] == flag) {
            set++;
        }
        else {
            if (set >= 6) {
                array[5]++;
            }
            else {
                array[set]++;
            }
            set = 0;
        }
    }

    int size = sizeof(array) / sizeof(array[0]);

    // Shifting elements one position to the left
    for (int i = 0; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }

    
    for (int i = 0; i < sizeof(array) / sizeof(4); i++) {
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

            default:
                if (count < 90 || count > 223) {
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

    
    if (level1(key)) {
        std::cout << "Level 1: passed!" << std::endl;
    }
    else {
        std::cout << "Level 1: failed" << std::endl;
    }
    
    //+++++++++++++++++++++++++++++++++++++++++++

    if (level2(key)) {
        std::cout << "Level 2: passed!" << std::endl;
    }
    else {
        std::cout << "Level 2: failed" << std::endl;
    }

    //+++++++++++++++++++++++++++++++++++++++++++

    if (level3(key)) {
        std::cout << "Level 3: passed!" << std::endl;
    }
    else {
        std::cout << "Level 3: failed" << std::endl;
    }

    //+++++++++++++++++++++++++++++++++++++++++++

    if (level4(key)) {
        std::cout << "Level 4: passed!" << std::endl;
    }
    else {
        std::cout << "Level 4: failed" << std::endl;
    }


    return 0;
}
