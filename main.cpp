#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace chrono;

const int MOD = 1e9+7;
const int INF = 1 << 30;
using ll = long long;
using VI = vector<int>;

VI n1(11); VI n3(1e3+1); VI n4(1e4+1); VI n6(1e6+1); VI n9(1e9+1);
map<string, vector<int>> vmap;
vector<string> name_v = {"n1", "n3", "n4", "n6", "n9"};
int number_vectors = 4;

void create_vectors(){
    vmap["n1"] = n1;
    vmap["n3"] = n3;
    vmap["n4"] = n4;
    vmap["n6"] = n6;
    vmap["n9"] = n9;

    for (int i = 0; i < number_vectors; i++){
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
    ofstream bubble; bubble.open("bubble_sort.csv");
    for (int k = 0; k < number_vectors; k++){
        cout << "here " << k << endl;
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

        bubble << name_v[k] << "," << duration.count() << endl;
        vmap[name_v[k]] = data;

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //data.csv contindrà les mitjanes aritmètiques de tots els algs amb les mateixes n's


    create_vectors();
    bubble_sort();

    
}