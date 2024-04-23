#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator> 

using namespace std;

int main() {
    //create an input iterator to read values from cin
    //istream_iterator<int> input_itr(cin);
    /*Supported operations
    ++,*,!=,==,->
    */

    //create an output iterator to write integers to the console
    //ostream_iterator<int> output_itr(cout, " ");
    /*Supported operations
    ++,*,=
    */

    //Forward Iterators
    /*Supported operations
    ++,*,!=,==,->
    */

    forward_list<int> nums {1,2,3,4,};

    //initialize an iterator to point 
    //to beginning of a forward list
    forward_list<int>:: iterator itr = nums.begin();

    //Se puede acceder y modificar los elementos de la lista
    while(itr != nums.end()){
        //access iterator values using indirection operator
        int original_values = *itr;

        //assign new value using indirection operator
        *itr = original_values * 2;

        //forward the iterator to the next position
        //Aumenta el puntero
        itr++;
    }

    //display contents of nums
    for (int num: nums){
        cout << num << ", ";
    }

    //Bidirectional Iterators
    /*Supported operations
    ++,*,!=,==,->,--
    */
    /*Iteradores de las clases:
    list, set, multiset, map, multimap
    */

    list<int> nums_2 {1,2,3,4,5};

    //initialize an iterator to point to the beginning of nums_2
    list<int>::iterator itr_2 = nums_2.begin();

    cout << "\nMoving forward: " << endl;

    //display the elements in forward order

    while (itr_2 != nums_2.end()) {
        cout << *itr_2 << ", ";

        //move the iterator by 1 position forward
        itr_2++;
    }

    cout << "\nMoving backward: " << endl;

    //display the elements in backward order
    while (itr_2 != nums_2.begin()) {
        //move the iterator by 1 position backward
        itr_2--;

        cout << *itr_2 << ", ";
    }

    cout << *itr_2 << endl; 

    //Random Access Iterators
    /*Supported operations
    ++,*,!=,==,->,--,+=,-=,>,<,>=,<=,[]
    */
    /*Los iteradores de las clases:
    vector, deque, string, array
    */

    //create a vector
    vector<int> vec{1,2,3,4,5};

    //create iterator to point to the firts and last element
    vector<int>::iterator itr_firts= vec.begin();
    vector<int>::iterator itr_last = vec.end() -1;

    //display the vector elements
    cout << "First element: " << *itr_firts << endl;
    cout << "Second element:"<< itr_firts[1] << endl;

    cout << "Second last element: " << *(itr_last -1) << endl;
    cout << "Last element: " << *(itr_last) << endl;
    return 0;
}