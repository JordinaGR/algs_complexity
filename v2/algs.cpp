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
vector<int> createOrderedVector(int n){
    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 0);
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
    srand (time(NULL));
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
        vector<int> nVector = {10}; //100, 1000, 10000, 100000, 1000000, 1000000
        int timesPV = 1;

        for (int i = 0; i < nVector.size(); i++){
            for (int j = 0; j < timesPV; j++){
                vector<int> tmpV = createVector(nVector[i]);
                int k = rand() % nVector[i];
                int index = -1;

                auto start = high_resolution_clock::now();
                for (int q = 0; q < tmpV.size(); q++){
                    if (tmpV[q] == k) {index = q; break;}
                }
                auto stop = high_resolution_clock::now();
                std::chrono::duration<double> diff = stop-start;
                linear << nVector[i] << ',' << diff.count() << endl;
                
            }
        }
    } else if(alg == "y"){
        ofstream binary; binary.open("/home/jordina/Desktop/new_programming/algs_complexity/v2/binary.csv", std::ofstream::out | std::ofstream::app);
        vector<int> nVector = {1000000000, 105000000, 150000000, 200000000}; //100, 1000, 10000, 100000, 1000000, 1000000
        int timesPV = 5;

        for (int i = 0; i < nVector.size(); i++){
            for (int j = 0; j < timesPV; j++){
                vector<int> tmpV = createOrderedVector(nVector[i]);
                int k = rand() % nVector[i];
                int index = -1;

                auto start = high_resolution_clock::now();

                int left = 0; int right = nVector[i]-1;

                while (left <= right){
                    int mid = (left+right) / 2;

                    if (tmpV[mid] == k) {index = mid; break;}
                    if (tmpV[mid] > k) {right = mid-1;}
                    if (tmpV[mid] < k) {left = mid+1;} 
                }

                auto stop = high_resolution_clock::now();
                std::chrono::duration<double> diff = stop-start;
                binary << nVector[i] << ',' << diff.count() << endl;
            }
        }
    }
    return 0;
}

// vector<int> nVector = {10, 1000, 20000, 40000, 60000, 80000, 10000};
//10, 100, 1000, 10000, 100000, 1000000, 1000000, 5000000, 10000000, 50000000, 100000000, 500000000