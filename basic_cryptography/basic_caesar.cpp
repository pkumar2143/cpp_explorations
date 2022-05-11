#include <iostream>
#include <string>
#include "basic_caesar.hpp"

int mod(int a, int b){
    // Just to satisfy requirements of encrypting and decrypting based on a 26 letter alphabet. More general modulus operator to be coded.
    if (a > 0 && b > 0){
        return a % b;
    } else if (a < 0 && b > 0){
        while (a < 0){
            a += b;
        }
        return a;
    }
    return 0;
};

std::string lower_fullstring(std::string my_str){

    std::string final_string = "";                  // Initialize the final string

    // loop through my_str input, change each char successively.
    for (int i = 0; i < my_str.length(); i++){
        char lower_char = tolower(my_str[i]);       // tolower converts one char to a lowercase char.
        final_string = final_string + lower_char;    // Concatenate lowercase strings
    }

    return final_string;
}

// Create a function pointer to these two ... !!!!!!!!!!!!!!!!!!!!!

std::string encryptCaesar(std::string message, int shift){

    const std::string LETTERS  = "abcdefghijklmnopqrstuvwxyz";      // initialize letters
    std::string lowercase_message = lower_fullstring(message);      // convert message to lowercase
    std::string encrypted_message = "";                             // initialize final encrypted message
    int letter_index;
    int shifted_index;

    // find index of each letter in the message as referenced in LETTERS string.
    for (int i = 0; i < lowercase_message.length(); i++){
        if (lowercase_message[i] == ' '){
            encrypted_message = encrypted_message + " ";
        }
        else{
            letter_index = LETTERS.find(lowercase_message[i]);
            shifted_index = mod((letter_index + shift),26);
            encrypted_message = encrypted_message + LETTERS[shifted_index];
        }
    }
    
    return encrypted_message;
};

std::string decryptCaesar(std::string message, int shift){
    // Simple inversion of encryption

    const std::string LETTERS  = "abcdefghijklmnopqrstuvwxyz";      // initialize letters
    std::string lowercase_message = lower_fullstring(message);      // convert message to lowercase
    std::string decrypted_message = "";                             // initialize final encrypted message
    int letter_index;
    int shifted_index;

    // find index of each letter in the message as referenced in LETTERS string.
    for (int i = 0; i < lowercase_message.length(); i++){
        if (lowercase_message[i] == ' '){
            decrypted_message = decrypted_message + " ";
        }
        else{
            letter_index = LETTERS.find(lowercase_message[i]);
            shifted_index = mod((letter_index - shift),26); // Modulo operator in C++ sucks, does not know how to handle negative numbers...
            decrypted_message = decrypted_message + LETTERS[shifted_index];
        }
    }
    
    return decrypted_message;
};
