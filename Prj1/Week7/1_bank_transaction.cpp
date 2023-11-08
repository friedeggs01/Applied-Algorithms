#include<bits/stdc++.h>
using namespace std;

struct Transaction {
    string fromAcc;
    string toAcc;
    int money;
    string time;
    string atm;
};
vector<Transaction> list_trans;
int number_transactions = 0;
int total_money_transaction = 0;
map<string, int> total_money_from;
set<string> list_acc;
map<string, list<string>> adj;

vector<string> split(const string& s, const string& delimiter) {
    vector<string> tokens;
    size_t delPos = 0;
    size_t sPos = 0;
    while ((delPos = s.find(delimiter, sPos)) != string::npos) {
        string token = s.substr(sPos, delPos - sPos);
        tokens.push_back(token);
        sPos = delPos + delimiter.length();
    }
    string lastToken = s.substr(sPos, s.length() - sPos);
    if (!lastToken.empty()) {
        tokens.push_back(lastToken);
    }
    return tokens;
}
int check = 0;
set<string> sol;
void inspect_cycle(string a1, string startAcc, int k) {
    // cout << startAcc << " " << a1 << " " << k << endl;
    for (auto& nextAcc : adj[a1]) {
        if (sol.find(nextAcc) == sol.end()){
            // cout << startAcc << " " << a1 << " " << k << endl;
            sol.insert(nextAcc);
            if (k == 1) {
                if (nextAcc == startAcc) {
                    check = 1;
                    return;
                }
            } else {
                inspect_cycle(nextAcc, startAcc, k-1);
            }
            sol.erase(nextAcc);
        }
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("1.txt", "r", stdin);

    // // Initialize adjacency list for each node
    // for ( i = 1; i <= 1001; i++) {
    //     adj[i] = list<string>();
    // }

    while(true){
        string temp;
        getline(cin, temp);
        if(temp == "#"){
            break;
        } else {
            vector<string> tem = split(temp, " ");
            Transaction transactionData;
            transactionData.fromAcc = tem[0];
            transactionData.toAcc = tem[1];
            transactionData.money = stoi(tem[2]);
            transactionData.time = tem[3];
            transactionData.atm = tem[4];
            list_trans.push_back(transactionData);
            list_acc.insert(tem[0]);
            list_acc.insert(tem[1]);
            adj[transactionData.fromAcc].push_back(transactionData.toAcc);
            number_transactions += 1;
            total_money_transaction += transactionData.money;
            total_money_from[transactionData.fromAcc] += transactionData.money;

        }
    }
        while(true){
        string temp;
        cin >> temp;
        if(temp == "#"){
            break;
        } else if (temp == "?number_transactions") {
            cout << number_transactions << endl;
        } else if (temp == "?total_money_transaction") {
            cout << total_money_transaction << endl;            
        } else if (temp == "?list_sorted_accounts") {
            for (const auto& acc : list_acc) {
                cout << acc << " ";
            }
            cout << endl;
        } else if (temp == "?total_money_transaction_from") {
            string k; cin >> k;
            cout << total_money_from[k] << endl;
        } else if (temp == "?inspect_cycle") {
            check = 0;
            sol.clear();
            string a1; cin >> a1;
            int k; cin >> k;
            inspect_cycle(a1, a1, k);
            if(check == 0){
                cout << 0 << endl;
            } else {
                cout << 1 << endl;
            }
        } 
    }
}