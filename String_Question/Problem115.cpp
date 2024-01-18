// Reverse a String and calculate the length without using any function
#include<iostream>
using namespace std;
int main(){
    string s = "Shubhasheesh";
    int start = 0;
    int end = s.size()-1;
    while(start<=end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
    cout<<s<<endl;

    // calculate length
    int size=0;
    while(s[size] != '\0'){
        size++;
    }
    cout<<size<<" ";

}