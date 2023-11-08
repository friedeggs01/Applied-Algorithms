#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

struct Order {
    string CustomerId;
    string ProductId;
    int price;
    string ShopId;
    string time;
};

int total_number_orders = 0;
int total_revenue = 0;
unordered_map<string, int> revenue_of_shop;
unordered_map<string, unordered_map<string, int>> total_consume_of_customer_shop;
map<string, int> price_before_time;

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
    freopen("2.txt", "r", stdin);
    while(true){
        string temp;
        getline(cin, temp);
        if(temp == "#"){
            break;
        } else {
            vector<string> t = split(temp, " ");
            Order OrderData;
            OrderData.CustomerId = t[0];
            OrderData.ProductId = t[1];
            OrderData.price = stoi(t[2]);
            OrderData.ShopId = t[3];
            OrderData.time = t[4];

            total_number_orders++;
            total_revenue += OrderData.price;
            revenue_of_shop[OrderData.ShopId] += OrderData.price;
            total_consume_of_customer_shop[OrderData.CustomerId][OrderData.ShopId] += OrderData.price;
            price_before_time[OrderData.time] += OrderData.price;
        }
    }
    for(auto it = next(price_before_time.begin()); it != price_before_time.end(); it++) {
        it->second += (prev(it))->second;
    } 
    while(true){
        string temp;
        cin >> temp;
        if(temp == "#"){
            break;
        } else if (temp == "?total_number_orders") {
            printf("%d\n", total_number_orders);
        } else if (temp == "?total_revenue") {
            printf("%d\n", total_revenue);
        } else if (temp == "?revenue_of_shop") {
            string k; cin >> k;
            printf("%d\n", revenue_of_shop[k]);
        } else if (temp == "?total_consume_of_customer_shop") {
            string cus, sh;
            cin >> cus >> sh;
            printf("%d\n", total_consume_of_customer_shop[cus][sh]);
        } else if (temp == "?total_revenue_in_period") {
            string t1, t2;
            cin >> t1 >> t2;
			auto lowerprice = price_before_time.lower_bound(t1);
			auto upperprice = price_before_time.upper_bound(t2);
			int lowerValue, upperValue;
			if(lowerprice == price_before_time.end()){
				cout << 0 << endl;
				continue;
			}
			else if(lowerprice == price_before_time.begin()) lowerValue = 0;
			else lowerValue = prev(lowerprice)->second;
			if(upperprice == price_before_time.end()) upperValue = price_before_time.rbegin()->second;
			else upperValue = prev(upperprice)->second;
            printf("%d\n", upperValue - lowerValue);
        }
    }
}
