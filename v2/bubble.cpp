#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(int *a, int *b){
    int tmp =  *a;
    *a = *b;
    *b = tmp;
}

double bubble_sort(vector<int> data){
    auto start = high_resolution_clock::now(); 
    for (int i = 0; i < data.size()-1; i++){
        for (int j = 0; j < data.size()-1; j++){
            if (data[j] > data[j+1]){
                swap(&data[j], &data[j+1]);
            }
        }
    }
    auto stop = high_resolution_clock::now();
    std::chrono::duration<double> diff = stop-start;
    return diff.count();
}

vector<int> createVector(int n){
    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 0);
    shuffle(vec.begin(), vec.end(), random_device());
    return vec;
}

int main(){
    string alg; cin >> alg;

    if (alg == "b"){
        ofstream bubble; bubble.open("/home/jordina/Desktop/new_programming/algs_complexity/v2/bubble.csv", std::ofstream::out | std::ofstream::app);
        vector<int> nVector = {10, 2000, 30000, 50000, 70000, 80000};

        int timesPV = 1;
        for (int i = 0; i < nVector.size(); i++){
            for (int j = 0; j < timesPV; j++){
                vector<int> tmpV = createVector(nVector[i]);
                double timee = bubble_sort(tmpV);
                bubble << nVector[i] << ',' << timee << endl;
            }
        }

    } else if (alg == "q") {
        return 0;
    } else if (alg == "m"){
        return 0;
    }
    return 0;
}

