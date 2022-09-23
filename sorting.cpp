#include <bits/stdc++.h>
using namespace std;

const int ITERATIONS = 100;
const int ARR_SIZE = 1000000;
const int MAX_VAL = 1000;

// Implementation of Counting Sort
// Complexity O(k+2n)
//   n = size of array
//   k = size of the range of values
//      (Slower than STL with k > 10,000,000)
//
void counting_sort(vector<int> A) {
    int L = *min_element(A.begin(), A.end());
    int R = *max_element(A.begin(), A.end());
    int K = R-L+1;

    vector<int> f(K, 0);
    for(const int &i:A)
        ++f[i-L];

    for(int i=1; i<K; ++i)
        f[i] += f[i-1];

    vector<int> temp = A;
    for(int i=A.size()-1; i>=0; --i) {
        A[f[temp[i]-L]-1] = temp[i];
        --f[temp[i]-L];
    }
}

// Standard STL Sort
//
void stl_sort(vector<int> A) {
    sort(A.begin(), A.end());
}

// Generate array with random values
//
vector<int> gen_array(int n, int max) {
    random_device rnd_device;
    mt19937 mersenne_engine {rnd_device()};
    uniform_int_distribution<int> dist {0, max};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    vector<int> vec(n);
    generate(begin(vec), end(vec), gen);
    return vec;
}

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60
void printProgress(double percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

int main() {
    printf("SORTING TEST ======================================================\n");
    printf("Array Size: %d\n", ARR_SIZE);
    printf("Maximum Value: %d\n", MAX_VAL);
    printf("Iterations: %d\n", ITERATIONS);
    printf("===================================================================\n\n");    

    printf("Generating Arrays..\n");
    vector<vector<int>> arrays;
    for(int i=0; i<ITERATIONS; ++i) {
        printProgress((double)(i+1)/ITERATIONS);
        arrays.push_back(gen_array(ARR_SIZE, MAX_VAL));
    }
    printf("\n\n");

    // STL Sort
    printf("Running STL Sort...\n");
    auto stl_start = clock();
    for(int i=0; i<ITERATIONS; ++i) {
        printProgress((double)(i+1)/ITERATIONS);
        stl_sort(arrays[i]);
    }
    printf("\n\n");
    auto stl_time = (clock() - stl_start) / (double)CLOCKS_PER_SEC;

    // Counting Sort
    printf("Running Counting Sort...\n");
    auto counting_start = clock();
    for(int i=0; i<ITERATIONS; ++i) {
        printProgress((double)(i+1)/ITERATIONS);
        counting_sort(arrays[i]);
    }
    printf("\n\n");
    auto counting_time = (clock() - counting_start) / (double)CLOCKS_PER_SEC;

    printf("RESULTS ===========================================================\n");
    printf("STL Sort:              %fs\n", stl_time);
    printf("Counting Sort:         %fs\n", counting_time);
    printf("===================================================================\n");
}