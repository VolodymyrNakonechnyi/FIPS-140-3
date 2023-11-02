# FIPS-140-3
Checking the randomness of keys that can be used in encryption

This C++ program performs randomness tests on a fixed-length string of bits to determine how random the string appears. The main objective is to assess the level of randomness in the generated bit string. The program employs four different tests to evaluate the randomness of the generated string:

<h5>Monobit Test:</h5> This test checks whether the bit string has approximately an equal number of ones and zeros. If the number of ones falls within the range of 9654 to 10346 (an acceptable range of randomness), the test is considered passed.

<h5>Max Series Length Test:</h5> This test examines whether the string contains excessively long sequences of identical bits. If the longest sequence of identical bits does not exceed 36, the test is considered passed.

<h5>Poker Test:</h5> This test divides the bit string into groups of 4 bits each and counts the occurrences of each possible 4-bit sequence. It then uses a poker coefficient to assess the distribution of these sequences. If the poker coefficient falls within the range of 1.03 to 57.04, the test is considered passed.

<h5>Check Series Lengths Test:</h5> This test checks whether the string contains sequences of identical bits that are neither too long nor too short. It uses different ranges for the lengths of identical bit sequences and verifies whether all sequence lengths fall within the appropriate ranges.

![image](https://github.com/VolodymyrNakonechnyi/FIPS-140-3/assets/146861887/6268ad38-ccb4-41fd-8107-e6272b7f3662)
![image](https://github.com/VolodymyrNakonechnyi/FIPS-140-3/assets/146861887/7195da8a-dce5-4dfb-874d-830d1a48b8cb)
