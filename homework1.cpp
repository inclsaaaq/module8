#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

namespace passutils {
    bool checkSize(const std::vector<char>& pass,uint8_t size = 6);
    bool checkUpper(const char& ch);
    bool checkLower(const char& ch);
    bool checkDigit(const char& ch);
    bool notSame(const std::vector<char>& pass);
    
    bool isStrong(const std::vector<char>& pass);

    uint8_t generateRandom(uint8_t min,uint8_t max);
    void generatePassword(std::vector<char>& newPassword,uint8_t size = 8);
}


bool passutils::checkSize(const  std::vector<char> &pass, uint8_t size) {
    return pass.size() >= size;
}

bool passutils::checkUpper(const char& ch) {
    return std::isupper(ch);
}

bool passutils::checkLower(const char &ch) {
    return std::islower(ch);
}

bool passutils::checkDigit(const char &ch) {
    return std::isdigit(ch);
}

bool passutils::notSame(const std::vector<char>& pass) {
    for (uint8_t i = 1;i < pass.size();i++) {
        if (pass.at(i) != pass.at(0))
            return true;
    }
    return false;
}

bool passutils::isStrong(const std::vector<char>& pass) {
    if (!passutils::checkSize(pass) || !passutils::notSame(pass))
        return false;

    auto upperResult = false;
    auto lowerResult = false;
    auto digitResult = false;
    auto specialResult = false;

    for (const char& ch : pass) {
        if (passutils::checkUpper(ch))
            upperResult = true;
        else if (passutils::checkLower(ch))
            lowerResult = true;

        else if(passutils::checkDigit(ch))
            digitResult = true;
        else
            specialResult = true;
    }

    return upperResult && lowerResult && digitResult && specialResult;
}

uint8_t passutils::generateRandom(uint8_t min, uint8_t max) {
    return rand() % (max - min + 1) + min;
}

void passutils::generatePassword(std::vector<char> &newPassword, uint8_t size) {
    bool isStrong = false;

    while (!isStrong) {
        newPassword.clear();
        newPassword.resize(size);

        for (uint8_t i = 0;i < size;i++) {
            newPassword.at(i) = passutils::generateRandom(33,126);
        }

        isStrong = passutils::isStrong(newPassword);

    }
}

void e1() {
    srand(time(0));

    std::string password;
    std::cout << "enter password: ";
    std::cin >> password;

    std::vector<char> passwords(password.begin(),password.end());

    bool result = passutils::isStrong(passwords);

    std::cout << (result ? "password is strong" : "password not strong") << std::endl;


    if (!result) {
        passutils::generatePassword(passwords,9);

        std::cout << "\nnewPassword: ";

        for (const char& ch : passwords)
            std::cout << ch;
    }


}



int main() {
    e1();

}