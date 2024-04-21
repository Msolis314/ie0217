#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
using namespace std;

int main() {

    //Contenedores de Secuencia
    //Vector,deque,list,
    //initialize a vector of int type
    vector<int> numbers = {1,100,10,70,100};

    //print the vector
    cout << "Numbers are: ";
    for (auto &num: numbers) {
        cout << num << ",";
    }

    //Contenedores de Asociación
    //Set,multiset,Map,multimap

    //initialize a set of int type 
    set<int> numbers_set = {1,100,10,70,100};

    //print the set
    cout << "\n Numbers in set are: ";
    //1,10,70,100
    //set no permite duplicados

    //auto se usa para deducir el tipo de variable
    for (auto &num: numbers_set) {
        cout << num << ",";
    }

    //map<key_type,value_type> map_name = {key1:value1,key2:value2,...}
    /*Funciones miembro de map
    insert(key,value)
    erase(key)
    find(key)
    clear()
    size()
    empty()
    */
    //create a map with integer keys and string values

    map<int,string> students = {{1,"Jacqueline"},{2,"Blake"},{3,"Denise"}};

    map<int,string> student;
    //use [] operator to add elements
    student[1] = "Jacqueline";
    student[2] = "Blake";

    //use insert() to add elements
    student.insert({3,"Denise"});

    //Los keys no se pueden repetir
    //Los valores si se pueden repetir
    student.insert({4,"Blake"});

    //add elements with duplicate keys
    student[5] ="Timothy";
    student[5] ="Aaron";

    for (int i = 1;i <= 5; i++){
        cout << "Student[" << i << "]: " << student[i] << endl;
    }

    //Contenedores Asoicativos desordenados
    //unordered_set,unordered_multiset,unordered_map,unordered_multimap

    //initialize a unordered set of int type
    unordered_set<int> numbers_unordered_set = {1,100,10,70,100};

    //print the unordered set
    cout << "\n Numbers in unordered set are: ";
    for (auto &num: numbers_unordered_set) {
        cout << num << ",";
    }
    //Imprime en orden diferente al set definido

    //Contendores Adaptadores
    /*Proporcionan una interfaz de contenedor diferente
    solo ciertos métodos están disponibles
    */
    //stack,queue,priority_queue

    //Create a stack of ints
    stack<int> numbers_stack;

    //push into stack
    numbers_stack.push(1);
    numbers_stack.push(100);
    numbers_stack.push(10);

    cout << "\nNumbers in stack are: ";
    //we can access the elements by getting the top and popping
    //until the stack is empty
    while (!numbers_stack.empty()) {
        //print top element
        cout << numbers_stack.top() << ",";

        //pop the top element from the stack
        numbers_stack.pop();
    }
    return 0;
}