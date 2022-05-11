#include <iostream>
#include <string>
#include "basic_caesar.hpp"

int main(){
    std::string example_message = "abcdefghijklmnopqrstuvwxyz";
    
    for (int shift = 0; shift < 27; shift++){
        std::cout << "Shift = " << shift << std::endl;
        std::cout << "Original message = " << example_message << std::endl;
        std::cout << "Encryption = "  << encryptCaesar(example_message,shift) << std::endl;
        std::cout << "Decryption = " << decryptCaesar(encryptCaesar(example_message,shift),shift) << std::endl;
        std::cout << std::endl;
    }
} 