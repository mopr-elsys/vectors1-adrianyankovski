#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
	
	Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};

class Vector {
    double x, y;

public:
    Vector() : x(0), y(0) {}
    Vector(double x, double y) : x(x), y(y) {}
    // if we denote p1 and p2 as points A and B, their radius-vectors would be OA and OB
    Vector(Point p1, Point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {}

    // this function should return the sum of the current vector and another "other" as a new Vector
    Vector sum(const Vector& other) const {
        return Vector(x+other.x,y+other.y);
    }

    // this function should return the difference of the current vector and another "other" as a new Vector
    Vector difference(const Vector& other) const {
        return Vector(x-other.x,y-other.y);
    }

    // this function should return a boolean value, answering the question whether the current vector and another "other" are collinear
    bool is_colinear(const Vector& other) const {
        
        if((x*other.y)-(y*other.x) == 0){
            return true;
        }else{
            return false;
        }
        /*if(x/other.x==y/other.y){
            return true;
        }else{
            return false;
        }*/
    }

    // this function should return the length of the current vector
    double length(const Vector& other) const {

        return (sqrt ( ((other.x-x)*2)+((other.y - y)*2) ) );
    }

    // this function should return the angle between the current vector and another "other"
    double angle(const Vector& other) const {
        //return (acos(x * (y * sqrt(other.y) ) ) );
        return  atan2(y - other.y, x - other.x);
        //((x * other.x + y * other.y) / (sqrt(x*x + y*y) * sqrt(other.x*other.x + other.y*other.y)));
    
    }

    // this is for printing the vector
    friend ostream& operator<<(ostream& os, const Vector& c);
    // this is for entering the vector
    friend istream& operator>>(istream& in, Vector& v);
    
};


// this function should find the area of the triangle made up of the three points p1, p2, p3
double area(const Point& p1, const Point& p2, const Point& p3) {
    double  A=sqrt(((p2.x-p1.x)*(p2.x-p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));
    double B=sqrt(((p3.x-p2.x)*(p3.x-p2.x))+((p3.y-p2.y)*(p3.y-p2.y)));
    double C=sqrt(((p1.x-p3.x)*(p1.x-p3.x))+((p1.y-p3.y)*(p1.y-p3.y)));
    return ((A+B+C)/2);

}

// this function should find the area of the figure made up of up to 50 points
double area(const Point points[50], int size) {
    return 0;
}

void vectors();
void triangleArea();
void area();

ostream& operator<<(ostream& os, const Vector& c);
istream& operator>>(istream& in, Vector& v);
istream& operator>>(istream& in, Point& p);

int main() {
    char input;
    cin >> input;

    switch (input) {
        case 'v':
            vectors();
            break;
        case 't': 
            triangleArea();
            break;
        case 's': 
            area();
            break;
        default:
            cout << "Invalid input" << endl;
    }

    return 0;
}

void vectors() {
    Vector v1, v2;
    cin >> v1 >> v2;
	
    cout << v1 << " + " << v2 << " = " << v1.sum(v2) << endl;
    cout << v1 << " - " << v2 << " = " << v1.difference(v2) << endl;
    cout << "Colinear: " << v1.is_colinear(v2) << endl;
    cout << "Length: " << v1.length(v2) << endl;
    cout << "Angle: " << v1.angle(v2) * 180 / 3.1415926536 << "°" << endl;
}

void triangleArea() {
    Point p1, p2, p3;
    cin >> p1 >> p2 >> p3;
	
    cout << "Area triangle: " << area(p1, p2, p3) << endl;
}

void area() {
    int size;
    cin >> size;
	
    Point *points = new Point[size];
    for (int i = 0; i < size; i++) {
        cin >> points[i];
    }

    cout << "Area polygon: " << area(points, size) << endl;
    delete[] points;
}

// this is for printing the vector
ostream& operator<<(ostream& out, const Vector& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

// this is for inputing a vector
istream& operator>>(istream& in, Vector& v) {
    in >> v.x;
    in >> v.y;
	
    return in;
}

// this is for inputing a point
istream& operator>>(istream& in, Point& p) {
    in >> p.x;
    in >> p.y;
	
    return in;
}
