#include<bits/stdc++.h>
using namespace std;

struct Submission {
    string userID;
    string problemID;
    string time;
    string status;
    int point;
};

int total_number_submissions = 0;
int number_error_submission = 0;
unordered_map<string, int> number_error_submission_of_user;
unordered_map<string, unordered_map<string, int>> total_point_of_user;
map<string, int> submission_before_time;
unordered_map<string, int> total_point;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    freopen("2.txt", "r", stdin);
    string temp;
    while(true){
        Submission sub;
        cin >> sub.userID;
        if(sub.userID == "#") break;
        cin >> sub.problemID;
        cin >> sub.time;
        cin >> sub.status;
        cin >> sub.point;
        
        total_number_submissions += 1;
        if(sub.status == "ERR"){
            number_error_submission += 1;
            number_error_submission_of_user[sub.userID] += 1;
        } else {
            if(sub.point > total_point_of_user[sub.userID][sub.problemID]){
            total_point[sub.userID] -= total_point_of_user[sub.userID][sub.problemID];
            total_point[sub.userID] += sub.point;
            total_point_of_user[sub.userID][sub.problemID] = sub.point;
            }
        }
        submission_before_time[sub.time] += 1;
    }

    for(auto it = next(submission_before_time.begin()); it != submission_before_time.end(); it++) {
        it->second += (prev(it))->second;
    } 

    while(true){
        cin >> temp;
        if(temp == "#"){
            break;
        } else if (temp == "?total_number_submissions") {
            printf("%d\n", total_number_submissions);
        } else if (temp == "?number_error_submision") {
            printf("%d\n", number_error_submission);           
        } else if (temp == "?number_error_submision_of_user") {
            string k; cin >> k;
            printf("%d\n", number_error_submission_of_user[k]);
        } else if (temp == "?total_point_of_user") {
            string k; cin >> k;
            printf("%d\n", total_point[k]);
        } else if (temp == "?number_submission_period") {
            string t1, t2;
            cin >> t1 >> t2;
			auto lower = submission_before_time.lower_bound(t1);
			auto upper = submission_before_time.upper_bound(t2);
			int lowerValue, upperValue;
			if(lower == submission_before_time.begin()) lowerValue = 0;
			else lowerValue = prev(lower)->second;
			if(upper == submission_before_time.end()) upperValue = submission_before_time.rbegin()->second;
			else upperValue = prev(upper)->second;
            printf("%d\n", upperValue - lowerValue);
        } 
    }
    return 0;
}