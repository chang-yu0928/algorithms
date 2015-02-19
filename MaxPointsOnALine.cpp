#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
struct line {
    double slope;
    double shift;
    
    line(double x, double y){
    	slope = x;
    	shift = y;
    }
     
};
bool operator < (const line & line1, const line & line2){
    if(line1.slope != line2.slope){
    	if(line1.slope < line2.slope){
            return true;
        }
    }else{
        if(line1.shift < line2.shift){
            return true;
        }
    }
    return false;
}

struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
};

bool operator < (const Point & Point1, const Point & Point2){
    if(Point1.x != Point2.x){
        if(Point1.x < Point2.x){
            return true;
        }
    }else{
        if(Point1.y < Point2.y){
            return true;
        }
    }
    return false;
}

int maxPoints(vector<Point> &points) {
    if(points.size() == 0)
            return 0;
        if(points.size() == 1)
            return 1;
        map<line, set<Point*> > temp;
        map<double, set<Point*> > special;
        for(int i = 0;i < points.size();i ++){
            for(int j = i;j < points.size();j ++){
                Point* point1 = &points[i];
                Point* point2 = &points[j];
                double slope = 0.0;
                if(point2->x - point1->x == 0){
                    double shift = point1->y - point1->x * slope;
                    if(special[shift].count(point1) == 0){
                        special[shift].insert(point1);
                    }
                    if(special[shift].count(point2) == 0){
                        special[shift].insert(point2);
                    }
                    continue;
                }
                slope = (double)(point2->y - point1->y)/(double)(point2->x - point1->x);
                double shift = (double)point1->y - ((double)point1->x * slope);
                cout<<"slope:"<<slope<<" shift:"<<shift<<endl;
                line key(slope, shift);
                if(temp[key].count(point1) == 0){
                    temp[key].insert(point1);
                }
                if(temp[key].count(point2) == 0){
                    temp[key].insert(point2);
                }
            }
        }
        map<line,set<Point*> >::iterator it = temp.begin();
        int max = 0;
        for(;it!=temp.end();++it){
            if(it->second.size() > max){
                max = it->second.size();
            }
        }
        map<double, set<Point*> >::iterator it2 = special.begin();
        for(;it2!=special.end();++it2){
            if(it2->second.size() > max){
                max = it2->second.size();
            }
        }
        return max;
}
int main(){
	vector<Point> points;
    points.push_back(Point(3,10));
    points.push_back(Point(0,2));
    points.push_back(Point(0,2));
    points.push_back(Point(3,10));
    cout<<maxPoints(points)<<endl;
}