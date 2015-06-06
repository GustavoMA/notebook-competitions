//BUGGED
//CAN'T BE USED IN MAPS RIGHT NOW
struct Point {
    double x, y, z;
    Point() {
        x = y = z = 0;
    }
    Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    Point(double _x, double _y) : x(_x), y(_y), z(0) {}
    bool operator<(const Point &p) const {
        if (x != p.x) return x < p.x;
        if (y != p.y) return y < p.y;
        if (z != p.z) return z < p.z;
    }
};

inline double hypot(double dx, double dy) {
    return sqrt(dx*dx + dy*dy);
}
double dist_2d(Point p1, Point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
