#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
double bubble_sort(vector<int> data){
    auto start = high_resolution_clock::now(); 
    for (int i = 0; i < data.size()-1; i++){
        for (int j = 0; j < data.size()-1; j++){
            if (data[j] > data[j+1]){
                swap(data[j], data[j+1]);
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
void mergeSort(int *array, int l, int m, int r){
    int i, j, k, nl, nr;
    nl = m-l+1; nr = r-m;
    int larr[nl], rarr[nr];

    for(i = 0; i < nl; i++)
        larr[i] = array[l+i];
    for(j = 0; j < nr; j++)
        rarr[j] = array[m+1+j];
    
    i = 0; j = 0; k = l;

    while(i < nl and j<nr) {
      if(larr[i] <= rarr[j]) {
        array[k] = larr[i];
        i++;
      } else{
        array[k] = rarr[j];
        j++;
      }
        k++;
   }
   while(i < nl) {
      array[k] = larr[i];
      i++; k++;
   }
   while(j < nr) {
      array[k] = rarr[j];
      j++; k++;
   }
}
void merge_sort(int *array, int l, int r){
    int m;
    if (l < r){
        int m = (l+r)/2;
        merge_sort(array, l, m);
        merge_sort(array, m+1, r);
        mergeSort(array, l, m, r);
    }
}
int main(){
    string alg; cin >> alg;
    
    if (alg == "b"){
        ofstream bubble; bubble.open("/home/jordina/Desktop/new_programming/algs_complexity/v2/bubble.csv", std::ofstream::out | std::ofstream::app);
        vector<int> nVector = {200000};
        int timesPV = 1;

        for (int i = 0; i < nVector.size(); i++){
            for (int j = 0; j < timesPV; j++){
                vector<int> tmpV = createVector(nVector[i]);
                double timee = bubble_sort(tmpV);
                bubble << nVector[i] << ',' << timee << endl;

            }
        }

    } else if (alg == "c") {
        ofstream cppalg; cppalg.open("/home/jordina/Desktop/new_programming/algs_complexity/v2/cppalg.csv", std::ofstream::out | std::ofstream::app);
        vector<int> nVector = {10, 1000, 20000, 40000, 60000, 80000, 100000, 500000, 1000000, 10000000};
        int timesPV = 3;

        for (int i = 0; i < nVector.size(); i++){
            for (int j = 0; j < timesPV; j++){
                vector<int> tmpV = createVector(nVector[i]);
                auto start = high_resolution_clock::now(); 
                sort(tmpV.begin(), tmpV.end());
                auto stop = high_resolution_clock::now();
                std::chrono::duration<double> diff = stop-start;

                cppalg << nVector[i] << ',' << diff.count() << endl;
            }
        }
    } else if (alg == "m"){
        ofstream merge; merge.open("/home/jordina/Desktop/new_programming/algs_complexity/v2/merge.csv", std::ofstream::out | std::ofstream::app);
        vector<int> nVector = {5000000};
        int timesPV = 1;

        for (int i = 0; i < nVector.size(); i++){
            for (int j = 0; j < timesPV; j++){
                vector<int> tmpV = createVector(nVector[i]);
                int* arr = &tmpV[0];

                auto start = high_resolution_clock::now(); 
                merge_sort(arr, 0, nVector[i]-1);
                auto stop = high_resolution_clock::now();
                std::chrono::duration<double> diff = stop-start;

                merge << nVector[i] << ',' << diff.count() << endl;
            }
        }
    } else if(alg == "l"){
        ofstream linear; linear.open("/home/jordina/Desktop/new_programming/algs_complexity/v2/linear.csv", std::ofstream::out | std::ofstream::app);
        vector<int> nVector = {100000, 1000000, 1000000, 50000000, 100000000};
        int timesPV = 3;

        for (int i = 0; i < nVector.size(); i++){
            for (int j = 0; j < timesPV; j++){
                vector<int> tmpV = createVector(nVector[i]);
                auto start = high_resolution_clock::now(); 

                for (int k = 0; k < tmpV.size(); k++){
                    int x = tmpV[k];
                }

                auto stop = high_resolution_clock::now();
                std::chrono::duration<double> diff = stop-start;

                linear << nVector[i] << ',' << diff.count() << endl;
            }
        }
    }
    return 0;
}

// vector<int> nVector = {10, 1000, 20000, 40000, 60000, 80000, 10000};
