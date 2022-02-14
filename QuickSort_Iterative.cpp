#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//swapping two numbers.
void swap(int *x, int *y){ 

    int temp; 
         temp = *x;
           *x = *y;
           *y = temp;       
}

//partitioning the array.
int partition(int array[], int lowest_index, int highest_index){
    int pivot;
    pivot = array[highest_index];//assigning the element at highest index as the pivot
    int i = lowest_index - 1;

    for(int j = lowest_index; j < highest_index; j++){

        if(array[j] < array[highest_index]){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[highest_index]);

    return (i+1);
}

//Quicksort iterative algorithm
void quicksort(int array[], int lowest_index, int highest_index){

    stack<pair<int, int>> myStack;//Creating a stack of pair of intergers using stack library.
    
    myStack.push(make_pair(lowest_index, highest_index));// pushing the lowest and highest index in to the stack.

    //while myStack is not empty run the code in the block below
    while(!myStack.empty()){

        lowest_index = myStack.top().first;
        highest_index = myStack.top().second;
        myStack.pop();//removing the top element from myStack.

        //calling the partition function which returns the index of the pivot.
        int pivot_index = partition(array, lowest_index, highest_index);
   
        if(pivot_index + 1 < highest_index){//arranging the elements less than the pivot_index
                                            //element to the left of the pivot
            myStack.push(make_pair(pivot_index + 1, highest_index));

        }
        if((pivot_index - 1) > lowest_index){//arranging the elements more than the pivot_index
                                            //element to the right of the pivot

            myStack.push(make_pair(lowest_index, pivot_index - 1));

        }
    }
}


int main(){

    int array_size;
    cout << "Enter the size of array: ";
    cin >> array_size;

    int arr[array_size];

    cout << endl;
    for(int i = 0; i < array_size; i++){//taking the input of the elements of array
        cout << "Enter the element at index " << i << " in the array: ";
        cin >> arr[i];       
    }

    cout << endl;
    //unsorted array output.
    cout << "The unsorted array is: " << endl;
    for(int i=0; i<array_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, array_size - 1);// calling the quicksort function.

    cout << "\nThe sorted array is: " << endl;
    for(int i=0; i<array_size; i++){//printing the array.
        cout << arr[i] << " ";
    }

    return 0;
}