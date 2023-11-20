#include<bits/stdc++.h>
using namespace std;

struct Infor {
    string code;
    string dob;
    string dad;
    string mom;
    string alive;
    string region;
};

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

int number_people = 0;
map<string, int> number_people_born_at;
map<string, int> most_alive_ancestor;
map<string, int> born_before_time;
set<string> set_unrelated_people;
int find_most_alive_ancestor(Infor infor) {
    if(infor.dad == "0000000" && infor.mom == "0000000"){
        return 0;
    } else {
        return max(most_alive_ancestor[infor.dad] + 1, most_alive_ancestor[infor.mom] + 1);
    }
}


int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("1.txt", "r", stdin);

    while(true){
        string temp;
        getline(cin, temp);
        if(temp == "*"){
            break;
        } else {
            vector<string> tem = split(temp, " ");
            Infor infor;
            infor.code = tem[0];
            infor.dob = tem[1];
            infor.dad= tem[2];
            infor.mom = tem[3];
            infor.alive = tem[4];
            infor.region = tem[5];

            number_people += 1;
            number_people_born_at[infor.dob] += 1;
            born_before_time[infor.dob] += 1;
            most_alive_ancestor[infor.code] = find_most_alive_ancestor(infor);
            if(infor.dad == "0000000" && infor.mom == "0000000") {
                set_unrelated_people.insert(infor.code);
            } else {
                if (set_unrelated_people.find(infor.dad) == set_unrelated_people.end() &&
                    set_unrelated_people.find(infor.mom) == set_unrelated_people.end()){
                    set_unrelated_people.insert(infor.code);
                }
            }

        }
    }
    for(auto it = next(born_before_time.begin()); it != born_before_time.end(); it++) {
        it->second += (prev(it))->second;
    } 
    while(true){
        string temp;
        cin >> temp;
        if(temp == "***"){
            break;
        } else if (temp == "NUMBER_PEOPLE") {
            printf("%d\n", number_people);

        } else if (temp == "NUMBER_PEOPLE_BORN_AT") {
            string k; cin >> k;
            printf("%d\n", number_people_born_at[k]); 

        } else if (temp == "MOST_ALIVE_ANCESTOR") {
            string k; cin >> k;
            printf("%d\n", most_alive_ancestor[k]);

        } else if (temp == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string t1, t2;
            cin >> t1 >> t2;
			auto lowerborn = born_before_time.lower_bound(t1);
			auto upperborn = born_before_time.upper_bound(t2);
			int lowerValue, upperValue;
			if(lowerborn == born_before_time.end()){
				cout << 0 << endl;
				continue;
			}
			else if(lowerborn == born_before_time.begin()) lowerValue = 0;
			else lowerValue = prev(lowerborn)->second;
			if(upperborn == born_before_time.end()) upperValue = born_before_time.rbegin()->second;
			else upperValue = prev(upperborn)->second;
            printf("%d\n", upperValue - lowerValue);

        } else if (temp == "MAX_UNRELATED_PEOPLE") {
            printf("%d\n", set_unrelated_people.size());
        } 
    }
}