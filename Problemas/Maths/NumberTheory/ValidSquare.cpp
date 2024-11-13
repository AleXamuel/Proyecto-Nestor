// https://leetcode.com/problems/valid-square/?envType=problem-list-v2&envId=geometry&difficulty=MEDIUM

#include <iostream>
#include <cmath>
#include <vector>
#include <set>

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<Point> points = {
        Point (p1[0], p1[1]),
        Point (p2[0], p2[1]),
        Point (p3[0], p3[1]),
        Point (p4[0], p4[1])
        };

        set<double> distances;
        for (size_t i = 0; i < points.size() - 1; i++){
            for (size_t j = i + 1; j < points.size(); j++){
                double distance = points[i].distanceTo(points[j]);
                distances.insert(distance);
            }
        }
        return distances.size() == 2 && (*distances.begin() != 0);
    }
    class Point{
        public:
            double x;
            double y;

            Point(double xCoord, double yCoord) : x(xCoord), y(yCoord){}
            double distanceTo(const Point& other) const{
                return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
            }
    };
};
