#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    //create a vector iterator
    vector<int> :: iterator vec_itr;

    //create a map iterator
    map<char , int> :: iterator map_itr;

    //create a vector of integer type
    vector<int> num {1,2,3};

    //Error: itr can only be used with integers vector
    //vector<double> :: iterator itr = num.begin();

    vector<string> languages = {"Python","C++","Java"};

    //create an iterator to a string vector
    vector<string>:: iterator itr; // auto itr = languages.begin();

    //iterate over all elements
    //languages.begin() puntero al primer elemento
    //languages.end() puntero al elemento mas alla del ultimo elemento
    for (itr = languages.begin(); itr != languages.end(); itr++){
        cout << *itr << ", ";
    }

    return 0;

}