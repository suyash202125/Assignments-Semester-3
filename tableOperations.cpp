//Program performing addition, subtraction, multiplication and transpose with two tables.
#include <iostream>
using namespace std;

//function for adding two tables/matrices
void addition(int **arr1, int **arr2, int row, int column){
    
    cout << endl;
    cout << "The addition of table1 and table2 gives: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cout << arr1[i][j] + arr2[i][j] << "  ";
        }
        cout << endl;
    }
}

//function for subtracting one table/matrix from the other.
void subtraction(int **arr1, int **arr2, int row, int column){

    cout << endl;
    cout << "The subtraction of table2 from table1 gives: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cout << arr1[i][j] - arr2[i][j] << "  ";
        }
        cout << endl;
    }
}

//function for multiplying the two tables
void multiply(int **arr1, int **arr2, int row, int column){
    
    if(row != column){
        cout << "\nThe multiplication is not possible as number of rows in table2 is not equal to number of columns in table1."<< endl;
    }else{
    cout << endl;
    int sum = 0;
    cout << "The multiplication of table1 and table2 gives: " << endl;
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                for(int k=0; k<row; k++){
                    sum += arr1[i][k] * arr2[k][j];
                }
                cout << sum << "  ";
                sum = 0;
            }
            cout << endl;
        }
    }
}

//function for transposing the tables.
void transpose(int **arr, int row, int column){
    int temp = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<i; j++){
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    
    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){

    int rows, columns;
    cout << "Enter the number of rows you want: ";
    cin >> rows;
    cout << "Enter the number of columns you want: ";
    cin >> columns;
    
    //declaring a double pointer and allocating rows of pointer in heap for table1
    int **table1 = new int*[rows];
    
    for (int i=0; i<rows; i++){ // allocating columns to each row of pointers in heap
        table1[i] = new int[columns];
    }

    cout << endl;
    // taking input values in table1
    cout << "For table1: " << endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << "Enter the element at row " << i+1 <<  " and column " << j+1 << " of table1: ";
            cin >> table1[i][j];
        }
    }

    cout << endl;
    // printing table1
    cout << "The table1 is: " << endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << table1[i][j] << " ";
        }
        cout << endl;
    }

    //declaring a double pointer and allocating rows of pointer in heap for table2
    int **table2 = new int*[rows];
    for(int i=0; i<rows; i++){
        table2[i] = new int[columns];
    }

    cout << endl << "For table2: " << endl;
    // taking input values in table2
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << "Enter the element at row " << i+1 <<  " and column " << j+1 << " of table2: ";
            cin >> table2[i][j];
        }
    }

    cout << endl;
    cout << "The table2 is: " << endl;
    // printing table2
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << table2[i][j] << " ";
        }
        cout << endl;
    }
    
    addition(table1, table2, rows, columns);//calling the addition function.
    subtraction(table1, table2, rows, columns);//calling the subtraction function.
    multiply(table1, table2, rows, columns);//calling the multiplication function.

    cout << endl;
    cout << "transpose of table1: " << endl;
    transpose(table1, rows, columns);//calling the transpose function for table1.

    cout << "transpose of table2: " << endl;
    transpose(table2, rows, columns);//calling the transpose function for table2.
    return 0;
}