#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

std::string to_decimal(const int &type_input,const  std::string &input){
    std::string output = input;
    int temp_decimal = 0;
    int curr_index = 0;
    //Needed because of the alphanumeric nature of Hexadecimal
    std::unordered_map<char, int> map_hexa = {
        {'0', 0 },{'1', 1 },{'2', 2 },{'3', 3 },
        {'4', 4 },{'5', 5 },{'6', 6 },{'7', 7 },
        {'8', 8 },{'9', 9 },{'A', 10 },{'B', 11 },
        {'C', 12 },{'D', 13 },{'E', 14 },{'F', 15 }
    };
    double base = pow(2, type_input);
    for (int power = input.length()-1; power >= 0; --power) {
        temp_decimal += map_hexa[input.at(curr_index)] * pow(base, power);
        ++curr_index;
    }
    output = std::to_string(temp_decimal);
    return output;
}

std::string to_binary(const int &type_input, const std::string &input) {
    std::string output = input;

    std::unordered_map<char, std::string> map_bin = {
        {'0' , "0000"},{'1' , "0001"},{'2' , "0010"},{'3' , "0011"},
        {'4' , "0100"},{'5' , "0101"},{'6' , "0110"},{'7' , "0111"},
        {'8' , "1000"},{'9' , "1001"},{'A' , "1010"},{'B' , "1011"},
        {'C' , "1100"},{'D' , "1101"},{'E' , "1110"},{'F' , "1111"}
    };
    std::string binary;
    if ( type_input == 2) { //Decimal
        int temp_decimal = stoi(input);
        while ( temp_decimal > 0 ) {
            binary.insert(0, temp_decimal % 2 == 0 ? "0" : "1");
            temp_decimal /= 2;
        }
    }
    else { //Octadecimal and Hexadecimal
        std::string temp_binary;
        //Binary representation of octadecimal is 3 digits instead of 4
        int pos_substr = (type_input == 3 ? 1 : 0);
        temp_binary = map_bin[input.at(0)].substr(pos_substr);

        const size_t it = temp_binary.find('1');
        if (it != std::string::npos) {
            binary = temp_binary.substr(it);
        }
        //Iterate through the input
        for (auto iterator = input.begin()+1; iterator != input.end(); ++iterator) {
            binary.append(map_bin[*iterator].substr(pos_substr));
        }
    }
    output = binary;
    return output;
}
std::string to_hexadecimal(const int &type_input, const std::string &input) {
    std::string output = input;
    std::unordered_map<std::string, std::string> map_bin = {
        {"0000", "0"}, {"0001", "1"}, {"0010", "2"}, {"0011", "3"},
        {"0100", "4"}, {"0101", "5"}, {"0110", "6"}, {"0111", "7"},
        {"1000", "8"}, {"1001", "9"}, {"1010", "A"}, {"1011", "B"},
        {"1100", "C"}, {"1101", "D"}, {"1110", "E"}, {"1111", "F"}
    };
    std::string hex_string;
    if ( type_input == 2 ) { //Decimal
        std::unordered_map<int, std::string> hex_map = {
            {10, "A"}, {11, "B"}, {12, "C"},
            {13, "D"}, {14, "E"}, {15, "F"}
        };
        int temp_decimal = stoi(input);
        while ( temp_decimal > 0) {
            if (int remainder = temp_decimal % 16; remainder < 10) {
                hex_string.insert(0, std::to_string(remainder));
            }
            else {
                hex_string.insert(0, hex_map[remainder]);
            }
            temp_decimal /= 16;
        }
    }
    else { //Octadecimal and binary
        std::string temp_binary = (type_input == 3 ? to_binary(type_input, input) : input);
        while ( temp_binary.length() % 4 != 0 ) {
            temp_binary.insert(0, "0");
        }
        for (size_t i = 0; i < temp_binary.length(); i += 4) {
            hex_string.append(map_bin[temp_binary.substr(i, 4)]);
        }
    }
    output = hex_string;
    return output;
}

std::string to_octadecimal(const int &type_input, const std::string &input){
    std::string output = input;
    std::string octa_string;
    if (type_input == 2) { //Decimal
        int temp_decimal = stoi(input);
        while ( temp_decimal > 0) {
            const int remainder = temp_decimal % 8;
            octa_string.insert(0, std::to_string(remainder));
            temp_decimal /= 8;
        }
    }
    else {
        std::unordered_map<std::string, std::string> map_bin = {
            {"000", "0"}, {"001", "1"}, {"010", "2"}, {"011", "3"},
            {"100", "4"}, {"101", "5"}, {"110", "6"}, {"111", "7"}
        };
        std::string temp_binary = (type_input == 4 ? to_binary(type_input, input) : input);

        //Multiple of 3 needed for correct conversion
        while (temp_binary.length() % 3 != 0) {
            std::string temp = "0";
            temp_binary.insert(0, temp);
        }
        for ( size_t i  = 0; i < temp_binary.length(); i += 3) {
            octa_string.append(map_bin[temp_binary.substr(i,3)]);
        }
    }
    output = octa_string;
    return output;
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
    if (type_input > 4 || type_input < 1) {
        std::cout << "Invalid input";
        return 1;
    }

    std::cout << "1: Binary" << "\n";
    std::cout << "2: Decimal" << "\n";
    std::cout << "3: Octadecimal" << "\n";
    std::cout << "4: Hexadecimal" << "\n";
    std::cout << "Select the System to convert: ";

    std::cin >> type_output;

    if (type_output > 4 || type_output < 1) {
        std::cout << "Invalid output";
        return 1;
    }

    if (type_input == type_output) {
        std::cout << "Conversion not needed" << '\n';
        std::cout << "Output: " << input;
    }
    else {
        std::string output;
        std::string sys_output;
        if ( type_output == 1) {
            output = to_binary(type_input, input);
            sys_output = "binary";
        }
        else if ( type_output == 2) {
            output = to_decimal(type_input, input);
            sys_output = "decimal";
        }
        else if ( type_output == 3) {
            output = to_octadecimal(type_input, input);
            sys_output = "octadecimal";
        }
        else {
            output = to_hexadecimal(type_input, input);
            sys_output = "hexadecimal";
        }
        std::cout << input << " on " << sys_output << ": " << output;
    }
    return 0;
}