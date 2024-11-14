// https://leetcode.com/problems/mirror-reflection/?envType=problem-list-v2&envId=geometry&difficulty=MEDIUM

#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int mirrorReflection(int p, int q) {
        // Calcular el Mínimo Común Múltiplo (MCM) 
        int l = lcm(p, q); 

        // Calcular el número de reflexiones
        int x = l / p; // Reflexiones verticales
        int y = l / q; // Reflexiones horizontales

        // Determinar el receptor
        if (x % 2 == 0 && y % 2 == 1) return 0; 
        if (x % 2 == 1 && y % 2 == 1) return 1; 
        if (x % 2 == 1 && y % 2 == 0) return 2; 

        return -1;
    }
};
