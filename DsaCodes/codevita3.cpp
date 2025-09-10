#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cmath> 
using namespace std;

int wordToNum(string word) {
    unordered_map<string, int> wordToDigit = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3},
        {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7},
        {"eight", 8}, {"nine", 9}
    };
    
    stringstream ss(word);
    string temp;
    int result = 0;
    
    while (getline(ss, temp, 'c')) {
        if (wordToDigit.find(temp) == wordToDigit.end()) {
            return -1;  
        }
        result = result * 10 + wordToDigit[temp];
    }
    
    return result;
}

int evaluate(vector<string> tokens) {
    int n = tokens.size();
    if (n < 3) return -1; 

    string op = tokens[0];  
    int result;

    if (op == "add" || op == "sub" || op == "mul" || op == "rem" || op == "pow") {
        if (n < 3) return -1; 
        
        int num1 = wordToNum(tokens[1]);
        int num2 = wordToNum(tokens[2]);

        if (num1 == -1 || num2 == -1) return -1;  

        if (op == "add") result = num1 + num2;
        else if (op == "sub") result = num1 - num2;
        else if (op == "mul") result = num1 * num2;
        else if (op == "rem") result = num1 % num2;
        else if (op == "pow") result = pow(num1, num2);
        
        if (n == 3) return result;  

        vector<string> nextTokens = {tokens[0], to_string(result)};
        nextTokens.insert(nextTokens.end(), tokens.begin() + 3, tokens.end());
        return evaluate(nextTokens);
    }
    
    return -1; 
}

int main() {
    int t;
    cin >> t;
    cin.ignore();  
    
    while (t--) {
        string input;
        getline(cin, input); 

        vector<string> tokens;
        stringstream ss(input);
        string word;

        while (ss >> word) {
            tokens.push_back(word);
        }

        int result = evaluate(tokens);

        if (result == -1) {
            cout << "expression evaluation stopped invalid words present" << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}
