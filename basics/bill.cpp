// Question2: Enter cost of 3 items from the user (using float data type)-a pencil,a pen and an eraser.You have to output the total cost of the items back to the user as their bill.(Add on :You can also try adding 18% GST tax to the items in the bill as an advanced problem)

#include<iostream>
using namespace std;
int main(){
    float pencil;
    float pen;
    float eraser;
    cout<< "Enter pencil amount : ";
    cin >> pencil;
    cout<< "Enter pen amount : ";
    cin >> pen;
    cout<< "Enter eraser amount : ";
    cin >> eraser;
    double total = pencil+pen+eraser;
    double withGST = total + (total/100)*18;

    cout <<"Total : "<< total << endl;
    cout <<"Included 18% GST : "<< withGST << endl;

}