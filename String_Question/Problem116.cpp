// Check givin string is Palindrome or not
#include<iostream>
using namespace std;
int main(){
    string s = "namano";
    int start = 0, end = s.size()-1;
    while(start<end){
        if(s[start] != s[end]){
            cout<<"Not Palindrome";
            return 0;
        }
        start++;
        end--;
    }
    cout<<"It is a Palindrome"<<endl;
}