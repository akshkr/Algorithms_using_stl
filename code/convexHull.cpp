#include <iostream> 
#include <stack> 
#include <stdlib.h> 

using namespace std;

struct Point
{
	int pointX, pointY;
};

Point pointOrigin;

// Find next to top in a stack 
Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	
	S.pop();
	
	Point res = S.top();
	
	S.push(p);
	
	return res;
}

// Switch two points 
int swap(Point &p1, Point &p2)
{
	Point temp = p1;
	
	p1 = p2;
	p2 = temp;

	return 0;
}

// Return square of distance 
int squareDistance(Point p1, Point p2)
{
	return (p1.pointX - p2.pointX)*(p1.pointX - p2.pointX) + (p1.pointY - p2.pointY)*(p1.pointY - p2.pointY);
}

// Find orientation
int orientation(Point point1, Point point2, Point point3)
{
	int value = (point2.pointY - point1.pointY) * (point3.pointX - point2.pointX) - (point2.pointX - point1.pointX) * (point3.pointY - point2.pointY);

	if (value == 0)
	{
		return 0;
	}

	return (value > 0) ? 1 : 2; 
}

// Sort Array of Points
int compare(const void *valuePoint1, const void *valuePoint2)
{
	Point *temp1 = (Point *)valuePoint1;
	Point *temp2 = (Point *)valuePoint2;

	int o = orientation(pointOrigin, *temp1, *temp2);
	
	if (o == 0)
	{
		return (squareDistance(pointOrigin, *temp2) >= squareDistance(pointOrigin, *temp1)) ? -1 : 1;
	}

	return (o == 2) ? -1 : 1;
}

// Convex hull
void convexHull(Point points[], int n)
{
	int yMinValue = points[0].pointY, min = 0;
	for (int i = 1; i < n; i++)
	{
		int y = points[i].pointY;

		if ((y < yMinValue) || (yMinValue == y && points[i].pointX < points[min].pointX))
		{
			yMinValue = points[i].pointY, min = i;
		}
	}

	swap(points[0], points[min]);

	pointOrigin = points[0];
	
	qsort(&points[1], n - 1, sizeof(Point), compare);

	int m = 1; 
	for (int i = 1; i < n; i++)
	{
		while (i < n - 1 && orientation(pointOrigin, points[i],
			points[i + 1]) == 0)
			i++;


		points[m] = points[i];
		m++;  
	}

	if (m < 3) return;
 
	stack<Point> S;
	
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	for (int i = 3; i < m; i++)
	{

		while (orientation(nextToTop(S), S.top(), points[i]) != 2)
			S.pop();
		S.push(points[i]);
	}

	while (!S.empty())
	{
		Point p = S.top();
		
		cout << "(" << p.pointX << ", " << p.pointY << ")" << endl;
		
		S.pop();
	}
}

int main()
{
	Point points[] = { {0, 0}, {3, 2}, {1, 8}, {2, 1},
					  {3, 1}, {8, 0}, {1, 4}, {9, 9} };
	
	int n = sizeof(points) / sizeof(points[0]);

	convexHull(points, n);

	return 0;
}
