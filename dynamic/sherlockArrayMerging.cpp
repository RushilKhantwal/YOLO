#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the arrayMerging function below.
 */
const long MOD = 1e9 + 7;

void arrayMerging_helper(vector<vector<long long> > &dp, vector<vector<long long> > &per, vector<int> &m, size_t idx, size_t k) {
    if (dp[idx][k] != -1)
        return;
    size_t n = m.size();
    if (idx + k > n+1) {
        dp[idx][k] = 0;
    } else if (!std::is_sorted(m.begin()+idx-1, m.begin()+idx-1+k)) {
        dp[idx][k] = 0;
    } else if (idx + k == n+1) {
        dp[idx][k] = 1;
    } else {
        size_t next = idx + k;
        long long res = 0;
        for (size_t i=1; i<=k; i++) {
            if (dp[next][i] == -1)
                arrayMerging_helper(dp, per, m, next, i);
            res += (dp[next][i] * per[k][i]) % MOD;
            res %= MOD;
        }
        dp[idx][k] = res;
    }
}

long long arrayMerging(vector<int> m) {
    size_t n = m.size();
    vector<vector<long long> > dp(n+1, vector<long long>(n+1, -1));
    vector<vector<long long> > per(n+1, vector<long long>(n+1, 0));
    for (size_t i=1; i<=n; i++) {
        per[i][1] = i;
        size_t x = i-1;
        for (size_t j=2; j<=i; j++) {
            per[i][j] = (per[i][j-1] * x) % MOD;
            x--;
        }
    }
    dp[1][0] = 0;
    for (size_t i=1; i<=n; i++)
        arrayMerging_helper(dp, per, m, 1, i);
    vector<long long> &v = dp[1];
    long long res = 0;
    for (auto i : v) {
        res += i;
        res %= MOD;
    }
    return res;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int m_count;
    cin >> m_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string m_temp_temp;
    getline(cin, m_temp_temp);

    vector<string> m_temp = split_string(m_temp_temp);

    vector<int> m(m_count);

    for (int m_itr = 0; m_itr < m_count; m_itr++) {
        int m_item = stoi(m_temp[m_itr]);

        m[m_itr] = m_item;
    }

    long long result = arrayMerging(m);

    fout << result << "\n";

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
