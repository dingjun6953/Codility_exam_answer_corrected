/*
Problem: find the minmal length of the unique substrings  among all substrings of a string
*/

#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int solution(string &S) {
    // Implement your solution here
int length=S.length();
int count=0;
int min=INT_MAX;
string output;
vector<string> text;
vector<string> result;

//find all substrings and store them into a vector.
for(int i=0;i<length-1;i++)
{
    for(int j=1;j<length-i+1;j++)
    {

        if(S.substr(i,j).length()>1)
        {
            text.push_back(S.substr(i,j));
        }
    }
}

//find all unique substrings of different length. 
for(auto elm:text)
{
    count=0;
    for(auto elm1:text)
    {
        if(elm==elm1) count++;
    }
    if (count==1) result.push_back(elm);
}

//find the minmal length of all unique substrings. 
for (auto elm2:result)
{
    if(elm2.length()<min)
    {
        output=elm2;
        min=elm2.length();
    }
}

return min ;
}

int main()
{
    //string  str="abaaba"; //example string 1
    string str="yzyzyzy"; //example string 2
    int result=solution(str);
    cout<<result<<endl;
    return 0;
}
