#include<bits/stdc++.h>
using namespace std;

int n, k;
int w[1001], l[1001];
int W[1001], L[1001], c[1001];

struct box {
    int h;
    int w;
    bool rotate;
};
bool comparebyh(const box& a, const box& b){
    return a.h > b.h;
}
struct container {
    int id;
    int h;
    int w;
    int c;
};
bool comparebyarea(const container& a, const container& b){
    return a.h*a.w/a.c > b.h*b.w/b.c;
}
vector<box> boxs;
vector<container> containers;
int x[1001] = {0}, y[1001] = {0}, max_x[1001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("1.txt", "r", stdin);
    cin >> n >> k;
    boxs.resize(n);
    containers.resize(k);
    for(int i=0; i<n; i++) {
        cin >> boxs[i].w >> boxs[i].h;
        if (boxs[i].w < boxs[i].h){ // make sure h < w and sort in decreasing order of height
            int temp = boxs[i].w;
            boxs[i].w = boxs[i].h;
            boxs[i].h = temp;
            boxs[i].rotate = 1;
        } else {
            boxs[i].rotate = 0;
        }
        // cout << boxs[i].w << boxs[i].h << boxs[i].rotate << endl;
    }
    // sort(boxs.begin(), boxs.end(), comparebyh);

    for(int i=0; i<k; i++){
        containers[i].id = i+1;
        cin >> containers[i].w >> containers[i].h >> containers[i].c;
    }
    sort(containers.begin(), containers.end(), comparebyarea);
    for(int i=0; i<k; i++){
        // cout << containers[i].id << " " << containers[i].w << " " << containers[i].h << " " << containers[i].c << endl;
    }
    for(int i=0; i<n; i++) {
        // cout << i << endl;
        for(int j=0; j<k; j++) {
            // cout << i << " " << boxs[i].w << " " << containers[j].id << " " << containers[j].w << " " << boxs[i].h << " " << containers[j].h << endl;
            if(boxs[i].w <= containers[j].w && (boxs[i].h + y[j]) <= containers[j].h){
                cout << i+1 << " " << containers[j].id << " " << "0" << " " << y[j] << " " << boxs[i].rotate << endl;
                y[j] += boxs[i].h;
                x[j] = max(boxs[i].w, x[j]);
                // cout << x[j] << " " << y[j] << endl;
                break;
            }
            int temp = boxs[i].w;
            boxs[i].w = boxs[i].h;
            boxs[i].h = temp;
            boxs[i].rotate = !boxs[i].rotate;

            if((boxs[i].w + x[j]) <= (containers[j].w) && boxs[i].h <= containers[j].h){
                cout << i+1 << " " << containers[j].id << " " << x[j] << " " << "0" << " " << boxs[i].rotate << endl;
                y[j] = max(boxs[i].h, y[j]);
                x[j] += boxs[i].w;
                break;
            }
            temp = boxs[i].w;
            boxs[i].w = boxs[i].h;
            boxs[i].h = temp;
            boxs[i].rotate = !boxs[i].rotate;
        }
    }

}
