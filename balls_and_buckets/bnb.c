#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

/*
    Consider the following problem:
        There are m distinct buckets and n identical balls and each bucket can contain 0 or more balls.
        All balls are arranged into the buckets, and there several combinations to arrange them.
        For example, if there are 2 buckets and 3 balls, we can have the following arrangement:
        
               bucket 1  |  bucket 2 
               ---------------------
                   3     |     0
                   2     |     1
                   1     |     2
                   0     |     3

        Another example, where m=3 and n=3:
       
               bucket 1  |  bucket 2  |  bucket 3
               ----------------------------------
                   3     |     0      |     0
                   2     |     1      |     0
                   2     |     0      |     1
                   1     |     2      |     0
                   1     |     1      |     1
                   1     |     0      |     2
                   0     |     3      |     0
                   0     |     2      |     1
                   0     |     1      |     2
                   0     |     0      |     3

    Write a function that gets m (number of buckets) and n (number of balls) as arguments and prints out 
    all of the possible balls-in-buckets permutations. Please note that each permutation must be printed 
    out once. 

    ** Helper function/s are allowed and are encouraged.
*/


int balls_and_buckets (int n, int m, ostream& stream, vector<int>& v) {
    if (m == 0) {
        if (n != 0) { return 0; }

        copy (v.begin(), v.end(), ostream_iterator<int>(stream, " "));
        stream << endl;
        return 1;
    }

    int bkt = v.size() - m;
    int combinations = 0;

    for (int i = n; i >= 0; --i) {
        v[bkt] = i;
        combinations += balls_and_buckets (n - i, m - 1, stream, v);
    }

    return combinations;
}

int balls_and_buckets(int n, int m, ostream& stream) {
    vector<int> v (m, 0);
    return balls_and_buckets (n, m, stream, v);
}

int main(void) {
    unsigned int num_balls, num_buckets;
    cout << "Num balls: "; cin >> num_balls;
    cout << "Num buckets: "; cin >> num_buckets;
    cout << "Num combinations: " << balls_and_buckets (num_balls, num_buckets, cout) << endl;

    return 0;
}
