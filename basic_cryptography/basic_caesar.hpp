#pragma once // ensures the .hpp will not be used more than once per .cpp file.

int mod(int a, int b);

std::string lower_fullstring(std::string my_str);

std::string encryptCaesar(std::string message, int shift);

std::string decryptCaesar(std::string message, int shift);