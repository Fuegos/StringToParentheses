#include <iostream>
#include <string>
using namespace std;

int main()
{
    string inputStr{};
    char isAgain{'Y'};
    while (isAgain == 'Y') 
    {
        cout << "Your text for replaced: ";
        getline(cin >> ws, inputStr);
        string resultStr{ inputStr };
        const int sizeInputStr{ static_cast<int>(inputStr.length()) };
        for (int i{ 0 }; i < sizeInputStr; ++i) {
            bool isDuplicate{ false };
            for (int j{ 0 }; j < sizeInputStr; ++j) {
                if (i != j) {
                    if (tolower(inputStr[i]) == tolower(inputStr[j])) {
                        isDuplicate = true;
                        break;
                    }
                }
            }
            resultStr[i] = isDuplicate ? ')' : '(';
        }
        cout << "Result: " << inputStr << " => " << resultStr << '\n';
        cout << "Again? ";
        cin >> isAgain;
    }
    
    return 0;
}
