#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // declaring two one dimensional vectors.
    vector <int> vector1; 
    vector <int> vector2;
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    //printing the elements and the number of elements in the vector using size() function.
    cout << endl << "vector1 has " << endl << vector1.at(0) << ", " << vector1.at(1) << endl;
    cout << endl << "The size of vector1 is of " << vector1.size() << " elements" << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << endl << "vector2 has " << endl << vector2.at(0) << ", " << vector2.at(1) << endl;
    cout << endl << "The size of vector2 is of " << vector2.size() << " elements" << endl;
    
    // declaring a two dimensional vector.
    vector <vector <int>> vector_2d;
    
    //adding vector1 to vector_2d dynamically using push_back.
    vector_2d.push_back(vector1);
    //adding vector2 to vector_2d dynamically using push_back.
    vector_2d.push_back(vector2);
    
    //printing elements of vector_2d.
    cout << endl << "vector_2d: " << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << vector_2d.at(i).at(j) << " ";
        }
        cout << endl;
    }
    
    //changing vector1.at(0) from 10 to 1000.
    vector1.at(0) = 1000;
    
    //displaying the elements of vector_2d again after changing the value at vector1.at(0).
    cout << endl << "vector_2d after changing the value of vector1.at(0): "<< endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << vector_2d.at(i).at(j) << " ";
        }
        cout << endl;
    }
    
    //printing vector1 again.
    cout << endl << "vector1: " << endl << vector1.at(0) << ", " << vector1.at(1) << endl;
    return 0;
}