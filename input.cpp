#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

int to_decimal(int type_input, std::string &input){
    int output;
    int temp_decimal = 0;
    int curr_index = 0;
    //Needed because of the Alfanumeric nature of Hexadecimal
    std::unordered_map<char, int> map_Hexa = {
        {'0', 0 },{'1', 1 },{'2', 2 },{'3', 3 },
        {'4', 4 },{'5', 5 },{'6', 6 },{'7', 7 },
        {'8', 8 },{'9', 9 },{'A', 10 },{'B', 11 },
        {'C', 12 },{'D', 13 },{'E', 14 },{'F', 15 }
    };

    switch(type_input){

        case (1): //Decimal
            std::cout << "Input already in decimal";
            output = stoi(input);
            break;

        case (2): //Hexadecimal

            for (int power = input.length()-1; power >= 0; --power) {
                temp_decimal += map_Hexa[input.at(curr_index)] * pow(16, power);
                ++curr_index;
            }
            output = temp_decimal;
            break;

        case (3): //Octadecimal
            for (int power = input.length()-1; power >= 0; --power) {
                temp_decimal += map_Hexa[input.at(curr_index)] * pow(8, power);
                ++curr_index;
            }
            output = temp_decimal;
            break;

        case (4): //Binary
            for(int power = input.length() -1; power >= 0; --power){
                // - '0' added for char -> int conversion
                temp_decimal += (input.at(curr_index) - '0') * pow(2, power);
                ++curr_index;
            }
            output = temp_decimal;
            break;

        default:
            std::cout << "Invalid input";
            break;
    }
    return output;
}

std::string to_binary(int &type_input, std::string &input){
    std::string output;

    std::unordered_map<char, std::string> map_Bin = {
        {'0' , "0000"},{'1' , "0001"},{'2' , "0010"},{'3' , "0011"},
        {'4' , "0100"},{'5' , "0101"},{'6' , "0110"},{'7' , "0111"},
        {'8' , "1000"},{'9' , "1001"},{'A' , "1010"},{'B' , "1011"},
        {'C' , "1100"},{'D' , "1101"},{'E' , "1110"},{'F' , "1111"},
    };


    switch(type_input){

        case (1): //Decimal
            int temp_decimal = stoi(input);
            int power = 0;
            
            bool highest_power = false;
            while (!highest_power){
                if(pow(2, power) <= temp_decimal && pow(2, power+1) > temp_decimal){
                    highest_power = true;
                }
                else{
                    ++power;
                }
            }
            std::cout << power << '\n';

            char binary_string[power+1];
            binary_string[0] = '1';
            temp_decimal -= pow(2,power);

            for(int i = 1; i < power+1; ++i){
                if(pow(2,power-i) <= temp_decimal){
                    binary_string[i] = '1';
                    temp_decimal -= pow(2,power-i);
                }
                else{
                    binary_string[i] = '0';
                }
            }


            std::string temp_string;
            for(int i = 0; i < power+1; ++i){
                temp_string = temp_string + binary_string[i];
            }
            output = temp_string;
            break;

        case (2): //Hexadecimal

            break;
        case (3): //Octadecimal
            break;
        case (4): //Binary
            std::cout << "Input already in decimal";
            output = input;
            break;

        default:
            std::cout << "Invalid input";
            output = "-1";
            break;

    }

    return output;
}

int main(){
    std::string input;
    int type_input, type_output;

    std::cout << "Enter the input: ";
    std::cin >> input;
    std::cout << "1: Decimal" << "\n";
    std::cout << "2: Hexadecimal" << "\n";
    std::cout << "3: Octadecimal" << "\n";
    std::cout << "4: Binary" << "\n";
    std::cout << "Select the System used: ";
    
    std::cin >> type_input;

    std::cout << "1: Decimal" << "\n";
    std::cout << "2: Hexadecimal" << "\n";
    std::cout << "3: Octadecimal" << "\n";
    std::cout << "4: Binary" << "\n";
    std::cout << "Select the System to convert: ";

    std::cin >> type_output;

    int decimal = to_decimal(type_input, input);
    std::cout << decimal << "\n";

    return 0;
}