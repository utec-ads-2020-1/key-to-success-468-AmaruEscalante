#include <iostream>
#include "string"
#include <map>

using namespace std;

int main() {

    int number = 0;
    string input;
    string output_text;
    char letter;
    string encoded_text;
    map <char, int> not_encoded;
    map <char, int> encoded;
    map<int, char> s_not_encoded;
    map<int, char> s_encoded;

    cin >> input;
    cin.ignore(256,'\n');
    number = stoi(input);

    while(number--){

        cin.ignore(256,'\n');
        while(cin.get(letter) && (letter != '\n')) {
            not_encoded[letter]++;
        }
        while(cin.get(letter) && (letter != '\n')) {
            encoded_text.push_back(letter);
            encoded[letter]++;
        }

        //Logic to order the maps according to its values
        map<char, int>::iterator itr;
        for (itr = not_encoded.begin(); itr != not_encoded.end(); ++itr)
            s_not_encoded[itr->second] = itr->first;

        for (itr = encoded.begin(); itr != encoded.end(); ++itr)
            s_encoded[itr->second] = itr->first;

        for (char i : encoded_text) {
            for (auto it_m1 = s_encoded.cbegin(), end_m1 = s_encoded.cend(),
                         it_m2 = s_not_encoded.cbegin(), end_m2 = s_not_encoded.cend();
                 it_m1 != end_m1 || it_m2 != end_m2; ++it_m1, ++it_m2) {
                if(i == it_m1->second)
                    output_text.push_back(it_m2->second);
            }
        }


        if(number > 0){
            cout << output_text <<endl <<endl;
        }
        else{
            cout << output_text <<endl;
        }

        encoded.clear();
        not_encoded.clear();
        s_encoded.clear();
        s_not_encoded.clear();
        encoded_text.clear();
        output_text.clear();
    }
    return 0;
}