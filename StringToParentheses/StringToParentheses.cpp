#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string inputStr{};
    char isAgain{'Y'};

    while (isAgain == 'Y') 
    {
        cout << "Your text for replaced: ";
        getline(cin >> ws, inputStr);

        // for storing pair: symbol of input string and its index
        map<char, int> symbolIndexes;
        const int sizeInputStr{ static_cast<int>(inputStr.length()) };
        string resultStr{ inputStr };

        for (int i{ 0 }; i < sizeInputStr; ++i) {
            // replace each symbol as unique
            resultStr[i] = '(';
            char symbol{ (char) tolower(inputStr[i]) };
            if (symbolIndexes.find(symbol) != symbolIndexes.end()) {
                // make changing '(' => ')' after next appearing of symbol
                resultStr[i] = ')';
                resultStr[symbolIndexes[symbol]] = ')';
            }
            else {
                // store first appearing symbol
                symbolIndexes.insert({ symbol, i });
            }
        }
        
        cout << "Result: " << inputStr << " => " << resultStr << '\n';
        isAgain = '\0';
        while (isAgain != 'Y' && isAgain != 'N')
        {
            cout << "Again? (Y/N) ";
            cin >> isAgain;
        }
    }
    
    return 0;
}
