// Author: Kelvin Lartey

#include <iostream>
#include "bdc.h"
#include <vector>
#include <string>

using namespace std;

// Writing a program to find the biggest conglomerate in a set of numbers. 
// Meaning, the numbers provided can all divide the biggest number. 

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

    // create a new vector to store divisible numbers
    vector<int> conglomerate_poss;
    sort(input.begin(), input.end() );

    if (input.empty()){
        return input;
    }
    else if(input.size() == 1){
        return input;
    }

    // step1. start with the biggest number and store those divisors in a vecotor.
    for (int i = input.size() - 1; i >= 0; i--) {  
        vector<int> temp_conglomerate;
        temp_conglomerate.push_back(input[i]); 

        // Check if it is divisible by all smaller values. 
        for (int j = 0; j < input.size(); j++) {
            // if the base number it reaches it's the same number then skip it. 
            if (i == j){
                continue; 
            } 
            if (input[i] % input[j] == 0) {
                temp_conglomerate.push_back(input[j]);
            }
        }
        // there are case, where the last number 
        if (temp_conglomerate.size() == input.size() - 1) {
            return temp_conglomerate;
        }

        // Update best conglomerate found so far
        if (temp_conglomerate.size() > conglomerate_poss.size()) {
            conglomerate_poss = temp_conglomerate;
        }
    }

    return conglomerate_poss;









    /*
    else {
        for (int i =0; i< input.size(); i ++){

            if(input.back() % input[i] == 0){
                conglomerate_poss.push_back(input[i]);

                if (conglomerate_poss.size() == input.size()){
                    return;
                }
                else{
                    for (int i =0; i< conglomerate_poss.size(); i ++){
                        if(conglomerate_poss.back() % conglomerate_poss[i] == 0){
                            conglomerate_poss.push_back(conglomerate_poss[i]);
                        }
                }

            }

        }
    }
}

    return conglomerate_poss;
*/
}



