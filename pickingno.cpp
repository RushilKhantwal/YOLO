/*
Given an array of integers, find and print the maximum number of integers you can select from the array such that the
absolute difference between any two of the chosen integers is less than or equal to 1 . 
For example, if your array is a=[1,1,2,2,4,4,5,5,5], you can create two subarrays meeting the criterion:[1,1,2,2]  and
[4,4,5,5,5] . 
The maximum length subarray has 5 elements.

Complete the pickingNumbers function in the editor below. It should return an integer that represents the length of the longest array that can be created.

pickingNumbers has the following parameter(s):

a: an array of integers
*/
------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {

    int actualCount = 0;
        int temp = 0;
        for(int i =0;i<a.size();i++){
            int A = a[i]+1;
            int B = a[i]-1;
            int C = a[i];
            int count1 =0;
            int count2 =0;
            int count3 = 0;
            for(int j =0;j<a.size();j++){
             if(a[j] == A){
                 count1++;
             } 
             if(a[j] == B){
                 count2++;
             }
             if(a[j] == C){
                 count3++;
             }
            
                if((count1+count3) > (count2 + count3)){
                    actualCount = count1+count3;
                }else{
                    actualCount = count2+count3;
                }
            }
            if(actualCount > temp){
                temp = actualCount;
            }
        }
        return temp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
