#include <bits/stdc++.h>
using namespace std;

struct Time {
    string date;
    string time;
};

vector<Time> store;
unordered_map<string, int> dateIndexMap;

vector<string> inline split(const string& s, const string& delimiter) {
    vector<string> tokens;
    size_t delPos = 0;
    size_t sPos = 0;
    while ((delPos = s.find(delimiter, sPos)) != string::npos) {
        string token = s.substr(sPos, delPos - sPos);
        tokens.emplace_back(token);
        sPos = delPos + delimiter.length();
    }
    string lastToken = s.substr(sPos, s.length() - sPos);
    if (!lastToken.empty()) {
        tokens.push_back(lastToken);
    }
    return tokens;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("15.txt", "r", stdin);

    store.reserve(10001); // Reserve memory for the store vector

    Time t;
    while (cin >> t.date && t.date != "*") {
        store.push_back(t);
        dateIndexMap[t.date] = store.size() - 1; // Store the position in the map
    }

    while (true) {
        int duration;
        cin >> t.date >> t.time >> duration;
        if (t.date == "***")
            break;

        vector<string> ti = split(t.time, ":");
        int h1 = stoi(ti[0]);
        int m1 = stoi(ti[1]);
        int s1 = stoi(ti[2]);
        int d2 = duration / 86400;
        int h2 = (duration %= 86400) / 3600;
        int m2 = (duration %= 3600) / 60;
        int s2 = (duration % 60);

        // Use the unordered_map to get the position directly
        int position = dateIndexMap[t.date];

        if (s1 + s2 >= 60) {
            m2 += 1;
        }
        if (m1 + m2 >= 60) {
            h2 += 1;
        }
        if (h1 + h2 >= 24) {
            d2 += 1;
        }

        int s = (s1 + s2) % 60;
        int m = (m1 + m2) % 60;
        int h = (h1 + h2) % 24;

        cout << store[position + d2].date << " " << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << '\n';
    }

    return 0;
}