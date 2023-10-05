#include <iostream>
#include <cstring>
using namespace std;

bool check(string date) {
    //correct format YYYY-MM-DD

    if(date.size() > 10) return false;
    if(date[4] != '-' || date[7] != '-') return false;
    int month = (date[5] - '0')*10 + (date[6]-'0');
    if(month>12 || month<1) return false;
    int day  = (date[8] - '0')*10 + (date[9]-'0');
    if(day>31 || day<1) return false;
    cout <<  date.substr(0,4) << " " << month << " " << day;
    return true;
    
}

int main() {
    string date;
    getline(cin, date);
    if(!check(date)) cout << "INCORRECT";
    return 0;
}