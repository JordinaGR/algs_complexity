#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace chrono;

const int MOD = 1e9+7;
const int INF = 1 << 30;
using ll = long long;
using VI = vector<int>;

VI n1(11); VI n2(1e2+1); VI n3(1e3+1); VI n4(1e4+1); VI n40000(40001); VI n60000(60001); VI n80000(80001); VI n5(1e5+1);
map<string, vector<int>> vmap;
vector<string> name_v = {"n1", "n2", "n3", "n4", "n40000", "n60000", "n80000", "n5"};
int number_vectors = 4;
int start_vectors = 0;
vector<ll> times(number_vectors);

void create_vectors(){
    vmap["n1"] = n1;
    vmap["n2"] = n2;
    vmap["n3"] = n3;
    vmap["n4"] = n4;
    vmap["n40000"] = n40000;
    vmap["n60000"] = n60000;
    vmap["n80000"] = n80000;
    vmap["n5"] = n5;

    for (int i = start_vectors; i < number_vectors; i++){
        vector<int> x = vmap[name_v[i]];
        iota(x.begin(), x.end(), 0);
        shuffle(x.begin(), x.end(), random_device());
        vmap[name_v[i]] = x;
    }
}
void swap(int *a, int *b){
    int tmp =  *a;
    *a = *b;
    *b = tmp;
}
void bubble_sort(){
    times = vector<ll> (number_vectors);
    for (int k = start_vectors; k < number_vectors; k++){
        vector<int> data = vmap[name_v[k]];

        auto start = high_resolution_clock::now(); 
        for (int i = 0; i < data.size()-1; i++){
            for (int j = 0; j < data.size()-1; j++){
                if (data[j] > data[j+1]){
                    swap(&data[j], &data[j+1]);
                }
            }
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        times[k] += duration.count();
        //bubble << name_v[k] << "," << duration.count() << endl;
        //vmap[name_v[k]] = data;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++){
        create_vectors();
        bubble_sort();        
    }
    ofstream bubble; bubble.open("/home/jordina/Desktop/new_programming/algs_complexity/db/bubble_sort.csv", std::ios::app);
    for (auto x : times){
        bubble << x << ",";
    }bubble << endl;
}