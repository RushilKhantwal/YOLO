#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
unsigned int unsignedMax(const unsigned int& a, const unsigned int& b) {
  return (a < b ? b : a);
}

unsigned int maxAbsoluteConsecutiveDifferenceSum(const vector<int>& B) {
  unsigned int hi = 0, lo = 0;
  unsigned int hi_lo_diff, lo_hi_diff, lo_temp, hi_temp;

  for(size_t i = 1; i < B.size(); i++) {
    hi_lo_diff = B[i-1] - 1; // B[i-1] >= 1
    lo_hi_diff = B[i] - 1; // B[i] >= 1

    lo_temp = unsignedMax(lo, hi + hi_lo_diff);
    hi_temp = unsignedMax(hi, lo + lo_hi_diff);

    lo = lo_temp;
    hi = hi_temp;
  }

  return unsignedMax(hi, lo);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split_string(B_temp_temp);

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        int result = maxAbsoluteConsecutiveDifferenceSum(B);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
