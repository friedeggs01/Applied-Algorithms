#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("1.txt","r", stdin);
    // ios_base::sync_with_stdio(false); // cannot use those statements when used scanf
    // cin.tie(NULL);
    map <string, int> call_from;
    map <string, int> call_time_map;
    int total_call = 0;
    bool check = true;
    while(true){
        string temp;
        cin >> temp;
        if(temp == "#") {
            break;
        } else {
            char sdt1_ch[15], sdt2_ch[15];
            int y1, mt1, d1, h1, m1, s1, h2, m2, s2;
            scanf("%s %s %d-%d-%d %d:%d:%d %d:%d:%d", &sdt1_ch, &sdt2_ch, &y1, &mt1, &d1, &h1, &m1, &s1, &h2, &m2, &s2);
            string sdt1 = sdt1_ch;
            string sdt2 = sdt2_ch;
            call_from[sdt1] += 1;
            total_call += 1;
            if(sdt1.size() != 10 && sdt2.size() != 10) check = false;
            int call_time = (h2-h1)*3600 + (m2-m1)*60 + (s2-s1);
            call_time_map[sdt1] += call_time;
            
        }
        
    }
    
    while(true){
        string query;
        cin >> query;
        if(query == "#") {
            break;
        } else if (query == "?check_phone_number") {
            if (check == true) {
                cout << 1 << endl;
            }
        } else if (query == "?number_calls_from") {
            string temp;
            cin >> temp;
            cout << call_from[temp] << endl;
        } else if (query == "?number_total_calls") {
            cout << total_call << endl;
        } else {
            string temp;
            cin >> temp;
            cout << call_time_map[temp] << endl;
        }
    }
}