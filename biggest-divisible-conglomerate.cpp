// Author: Kelvin Lartey

#include <iostream>
#include "bdc.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Writing a program to find the biggest conglomerate in a set of numbers. 
// So that means that the biggest number can be divided evenly by atleast one of the smaller numbers
// But then from the first set of numbers divisible by the largest numbers you make sure
// The second largest number will be divisible by those smaller numbers
// You do that till the first number. 

 
// Convert to string
string vec_to_string(vector<int> v){
    string s;
    s = "[";
    for (int i =0; i < v.size(); i++){
        s+= to_string(v[i]);
        if (i < v.size()-1){
            s += ", ";
              
        }   
    }
    s += "]";
    return s;
}
// is the num can be added to the vector.
bool is_divisible(vector<int>& conglomerate, int num) {
    for (int i = 0; i < conglomerate.size(); i++) {
        if (conglomerate[i] % num != 0 && num % conglomerate[i] != 0) {
            return false;  
        }
    }
    return true;  
}

// instead of writing the recurcive call in the biggest_cong function, having a helper function makes
// it easier. 
vector <int> right_cong(vector<int>& sorted_list, int i, vector<int> current_conglomerate){
    if (i < 0 ){
        return current_conglomerate;
    }

    // have to exclude the current number from the vector
    vector<int> exclude_vec = right_cong(sorted_list, i - 1, current_conglomerate);

    vector<int> include_vec;
    if (is_divisible(current_conglomerate, sorted_list[i])) {
        vector<int> new_conglomerate = current_conglomerate;
        new_conglomerate.push_back(sorted_list[i]);
        include_vec = right_cong (sorted_list, i - 1, new_conglomerate);
    }
    if (include_vec.size() > exclude_vec.size()) {
        return include_vec;   
    } else {
        return exclude_vec;   
    }

}
// Actual code implementation to find the conglomerate.
vector<int> biggest_divisible_conglomerate(vector<int> input){

    // Edge cases empty set and only one input. 
    if (input.empty()){
        return input;
    }
    else if(input.size() == 1){
        return input;
    }


// Step 1; I will first sort the values in ascending order
    sort(input.begin(), input.end() );
    // start with an empty vector. 
    vector<int> empty_conglomerate;

    // recursive call. 
    return right_cong(input, input.size() - 1, empty_conglomerate);

}
