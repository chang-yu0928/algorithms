#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point>& points) {
        if(points.empty()) return 0;
        int res = 1, base = 0;
        double slope;
        for(int i = 0;i < points.size() - 1;i ++) {
            unordered_map<double, int> mp;
            base = 0;
            for(int j = i + 1;j < points.size();j ++) {
                if(points[j].y == points[i].y && points[j].x == points[i].x) base ++;
            }
            for(int j = i + 1;j < points.size();j ++) {
                if(points[j].y == points[i].y && points[j].x == points[i].x) continue;
                if(points[j].x == points[i].x) slope = INT_MAX;
                else slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                mp[slope] ++;
                res = max(mp[slope] + base + 1, res);
            }
            res = max(res, base + 1);
        }
        return res;
    }
    
int main(){
	vector<Point> points;
    points.push_back(Point(3,10));
    points.push_back(Point(1,1));
    points.push_back(Point(1,1));
    points.push_back(Point(3,10));
    cout<<maxPoints(points)<<endl;
}