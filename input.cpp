#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

int to_decimal(const int &type_input,const  std::string &input){
    int output = -1;
    int temp_decimal = 0;
    int curr_index = 0;
    //Needed because of the alphanumeric nature of Hexadecimal
    std::unordered_map<char, int> map_hexa = {
        {'0', 0 },{'1', 1 },{'2', 2 },{'3', 3 },
        {'4', 4 },{'5', 5 },{'6', 6 },{'7', 7 },
        {'8', 8 },{'9', 9 },{'A', 10 },{'B', 11 },
        {'C', 12 },{'D', 13 },{'E', 14 },{'F', 15 }
    };
    int base = pow(2, type_input);
    for (int power = input.length()-1; power >= 0; --power) {
        temp_decimal += map_hexa[input.at(curr_index)] * pow(base, power);
        ++curr_index;
    }
    output = temp_decimal;
    return output;
}

std::string to_binary(const int &type_input, const std::string &input) {
    std::string output = "-1";

    std::unordered_map<char, std::string> map_bin = {
        {'0' , "0000"},{'1' , "0001"},{'2' , "0010"},{'3' , "0011"},
        {'4' , "0100"},{'5' , "0101"},{'6' , "0110"},{'7' , "0111"},
        {'8' , "1000"},{'9' , "1001"},{'A' , "1010"},{'B' , "1011"},
        {'C' , "1100"},{'D' , "1101"},{'E' , "1110"},{'F' , "1111"}
    };
    int power = 0;

    switch (type_input){

        case 2: { //Decimal
            int temp_decimal = stoi(input);

            while (pow(2, power+1) <= temp_decimal) {
                ++power;
            }
            std::string binary_string = "1";
            temp_decimal -= pow(2,power);

            for(int i = 1; i < power+1; ++i){
                if(pow(2,power-i) <= temp_decimal){
                    binary_string.append("1");
                    temp_decimal -= pow(2,power-i);
                }
                else{
                    binary_string.append("0");
                }
            }
            output = binary_string;
            break;
        }
        case 3: { //Octadecimal
            //From 4 to 3 digits binary representation
            std::string temp_binary = map_bin[input.at(0)].substr(1);
            size_t it = temp_binary.find('1');
            std::string binary;
            if (it != std::string::npos) {
                binary = temp_binary.substr(it);
            }
            //Iterate through the input
            for (auto it = input.begin()+1; it != input.end(); ++it) {
                binary.append(map_bin[*it].substr(1));
            }
            output = binary;
            break;
        }

        case 4: { //Hexadecimal
            //Remove all 0s before the first 1
            std::string temp_binary = map_bin[input.at(0)];
            size_t it = temp_binary.find('1');
            std::string binary;
            if (it != std::string::npos) {
                binary = temp_binary.substr(it);
            }
            //Iterate through the input
            for (auto it = input.begin()+1; it != input.end(); ++it) {
                binary.append(map_bin[*it]);
            }
            output = binary;
            break;
        }
        default: {
            std::cout << "Invalid input";
            break;
        }
    }
    return output;
}
std::string to_hexadecimal(const int &type_input, const std::string &input) {
    std::string output = "-1";
    std::unordered_map<std::string, std::string> map_bin = {
        {"0000", "0"}, {"0001", "1"}, {"0010", "2"}, {"0011", "3"},
        {"0100", "4"}, {"0101", "5"}, {"0110", "6"}, {"0111", "7"},
        {"1000", "8"}, {"1001", "9"}, {"1010", "A"}, {"1011", "B"},
        {"1100", "C"}, {"1101", "D"}, {"1110", "E"}, {"1111", "F"}
    };

    switch ( type_input ) {
        case 1: { //Binary
            std::string temp_string;
            for (int i= -1; i < input.length()-4; i += 4) {
                temp_string.append(map_bin[input.substr(i+1, 4)]);
            }
            output = temp_string;
            break;
        }
        case 2: { //Decimal
            //Binary search for alphanumeric
            std::string temp_string;

        }

        case 3: { //Octadecimal
            std::string temp_string;
            std::string binary = to_binary(type_input, input);
            //4 digits binary representations
            while (binary.length() % 4 != 0) {
                std::string temp = "0";
                binary = temp.append(binary);
            }
            for (int i = -1; i < binary.length()-4; i += 4) {
                temp_string.append(map_bin[binary.substr(i+1, 4)]);
            }
            output = temp_string;
            break;
        }

        default: {
            std::cout << "Invalid input";
            break;
        }
    }
}
int main(){
    std::string input;
    int type_input, type_output;

    std::cout << "Enter the input: ";
    std::cin >> input;
    std::cout << "1: Binary" << "\n";
    std::cout << "2: Decimal" << "\n";
    std::cout << "3: Octadecimal" << "\n";
    std::cout << "4: Hexadecimal" << "\n";
    std::cout << "Select the System used: ";
    
    std::cin >> type_input;

    std::cout << "1: Binary" << "\n";
    std::cout << "2: Decimal" << "\n";
    std::cout << "3: Octadecimal" << "\n";
    std::cout << "4: Hexadecimal" << "\n";
    std::cout << "Select the System to convert: ";

    std::cin >> type_output;
    if (type_input == type_output) {
        std::cout << "Conversion not needed" << '\n';
        std::cout << "Output: " << input;
    }
    else {
        const std::string binary = to_binary(type_input, input);
        std::cout << binary << "\n";
    }
    return 0;
}