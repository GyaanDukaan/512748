#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class Circle {
public:
    // Type to represent a point
    using Point = std::pair<int, int>;

    Circle(int centerX, int centerY, int radius) : centerX(centerX), centerY(centerY), radius(radius) {}

    // Inline function to calculate the points
    inline void drawCircle(std::vector<Point> &points) {
        int x = 0;
        int y = radius;
        int p = 1 - radius; // Midpoint variable

        // Generate points in the eight octants
        while (x <= y) {
            // Add points using the eight-way symmetry of the circle
            addCirclePoints(points, x, y);
            ++x;

            // Decide whether to decrement y using the midpoint p
            if (p < 0) {
                p += 2 * x + 1; // Mid-point is inside the circle
            } else {
                --y;
                p += 2 * (x - y) + 1; // Mid-point is outside the circle
            }
        }
    }
    
    // Function to get circle points
    std::vector<Point> getPoints() {
        std::vector<Point> points;
        drawCircle(points);
        return points;
    }

private:
    int centerX, centerY, radius;

    // Inline function to add symmetrical points
    inline void addCirclePoints(std::vector<Point> &points, int x, int y) {
        points.emplace_back(centerX + x, centerY + y);
        points.emplace_back(centerX - x, centerY + y);
        points.emplace_back(centerX + x, centerY - y);
        points.emplace_back(centerX - x, centerY - y);
        points.emplace_back(centerX + y, centerY + x);
        points.emplace_back(centerX - y, centerY + x);
        points.emplace_back(centerX + y, centerY - x);
        points.emplace_back(centerX - y, centerY - x);
    }
};

int main() {
    int centerX = 0, centerY = 0, radius = 5;
    Circle circle(centerX, centerY, radius);
    
    // Get the points that make up the circle
    std::vector<Circle::Point> points = circle.getPoints();
    
    // Print the generated points
    std::cout << std::fixed << std::setprecision(2);
    for (const auto &point : points) {
        std::cout << "Point: (" << point.first << ", " << point.second << ")\n";
    }

    return 0;
}
