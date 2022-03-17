//
//  main.cpp
//  cpp1
//
//  Created by Samsonov Vladimir on 05.02.2022.
//
#include <iostream>
#include <vector>
// quick sort
int a = 0;
std::vector<uint16_t> data;

std::vector<uint16_t> quick(std::vector<uint16_t> arr){
    if (arr.size()<=1) {
        return arr;
    } else {
        std::vector<uint16_t> left;
        std::vector<uint16_t> right;
        std::vector<uint16_t> pivot;
        
        pivot.push_back(arr.back());
        for (int i = 0; i < arr.size()-1; ++i){
            if (arr[i]<= pivot.back()){
                left.push_back(arr[i]);
            } else {
                right.push_back(arr[i]);
            }
        }
        std::vector<uint16_t> sorted_left = quick(left);
        std::vector<uint16_t> sorted_right = quick(right);
        sorted_left.insert(sorted_left.end(), pivot.begin(), pivot.end());
        sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());
        return sorted_left;
    }
}

int main() {
    for (int j = 0; j < 1000000; j++) {
        std::vector<uint16_t> input;
            uint16_t size = 100;
            for (uint i = 0; i < size; i++) {
                uint16_t a = rand();
                input.push_back(a);
            }
            std::vector<uint16_t> output = quick(input);
            for (uint i = 0; i < size; i++) {
                std::cout << output.at(i) << " ";
            }
            std::cout << ": " << a << std::endl;
        data.push_back(a);
        a = 0;
    }
    uint64_t sum = 0;
    for (int i = 0; i < data.size(); i++) {
        
        sum += data.at(i);
    }
    std::cout << " Middle value is : " << sum/data.size();
    return 0;
}
