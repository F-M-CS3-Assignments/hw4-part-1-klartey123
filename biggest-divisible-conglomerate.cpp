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

// Actual code implementation to find the conglomerate.
vector<int> biggest_divisible_conglomerate(vector<int> input){

// Step 1; I will first sort the values in ascending order
    sort(input.begin(), input.end() );

    // Edge cases empty set and only one input. 
    if (input.empty()){
        return {};
    }
    else if(input.size() == 1){
        return input;
    }
    
    // create a new vector to store conglomerate. 
    vector<int> conglomerate_poss;

    // step2. start with the biggest number and store those divisors in a vector. 
    for (int i = input.size() - 1; i >= 0; i--) {  
        vector<int> temp_conglomerate;
        // The biggest value is always added to the vector. 
        temp_conglomerate.push_back(input[i]); 

        // Step 3; Check if it is divisible by all smaller values. 
        for (int j = i - 1; j >= 0; j--) {
            if (temp_conglomerate.back() % input[j] == 0) {
                temp_conglomerate.push_back(input[j]);
            }
        }
        // Update best conglomerate found so far
        if (temp_conglomerate.size() > conglomerate_poss.size()) {
            conglomerate_poss = temp_conglomerate;
        }
    }

    return conglomerate_poss;
}



