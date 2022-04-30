//Program for 2D array linear search

#include <iostream>
#define M 2
#define N 3
using namespace std;



int main(){
    int a[M][N];
    int i=0, j=0, row, column;// first commit
    bool flag = 0;

    cout<<"Enter the elements of the array:"<<endl;
    for(i = 0; i<M; i++){
        for(j = 0; j<N; j++){
            cin>>a[i][j];
        }
    }

    int userValue;
    cout<<"Enter the element which you are looking for: ";
    cin>>userValue;

    //finding the element.
    for(i = 0; i<M; i++){
        for(j = 0; j<N; j++){
            if(userValue == a[i][j]){
                flag = 1;
                row = i;
                column = j;
                break;
            }         
        }
    }

    if(flag == 0){
        cout << "The element is not in the array." << endl;
    }
    else{
        cout << userValue << " is at index ("<<row<<","<<column<<")." << endl;
    }
}
