#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct point{
    float x;
    float y;
};

bool pointCmp(const point& a, const point& b){ //compares 2 points by y, then by x value
    if(a.y<b.y){
        return true;
    }
    else if(a.y>b.y){
        return false;
    }
    return a.x<b.x;
}

float distSq(const point& a, const point& b){ //squared distance between two points
    return (a.x - b.x)*(a.x - b.x) +
           (a.y - b.y)*(a.y - b.y);
}

int orientation(const point& a, const point& b, const point& c){
    float result = (b.y - a.y) * (c.x - b.x) -
                   (b.x - a.x) * (c.y - b.y);
    
    if(result == 0.0f){
        return 0; //colinear
    }
    return (result>0) ? 1 : 2; //clock- / anti clockwise
}

bool angleCmp(const point& a, const point& b, const point& ref){//compares the angle between two points with respect to a reference
    int ori=orientation(ref, a, b);
    if(ori==0){
        return (distSq(ref, a) < distSq(ref, b));
    }
    return (ori==2);
}

point top2(std::stack<point>& s){ //returns the second element on a stack
    auto tmp=s.top();
    s.pop();
    auto res=s.top();
    s.push(tmp);
    return res;
}

int main(){
    std::vector<point> points={ {0.2f, 2.3f}, {4.4f, 13.6f}, 
                                {-3.2f, -41.3f}, {12.8f, 13.6f}, 
                                {-17.4f, 8.7f}, {11.1f, 0.4f}, 
                                {-5.2f, 17.0f},{ 0.3f, -16.4f} }; //test data
    
    auto smallest = std::min_element(points.begin(), points.end(), pointCmp);
    std::iter_swap(points.begin(), smallest);
    
    std::sort(points.begin()+1, points.end(), [&](point& a, point& b)
                                        {return angleCmp(a,b,points[0]);});
    
    
    int last = 1;
    for (int i=1; i<points.size(); i++)
    {
        // Keep removing i while angle of i and i+1 is same
        while(i < points.size()-1 && orientation(points[0], points[i], points[i+1]) == 0)
          i++;
        points[last] = points[i];
        last++;  // Update size of modified array
    }
    
    if(last<3){
        //no convex hull possible....
        return -1;
    }
    std::stack<point> stack;
    stack.push(points[0]);
    stack.push(points[1]);
    stack.push(points[2]);
    
    for(size_t i=3; i<last; ++i){
        while(orientation(top2(stack), stack.top(), points[i]) != 2){
            stack.pop();
        }
        stack.push(points[i]);
    }
    
    while(!stack.empty()){
        auto tmp=stack.top();
        stack.pop();
        std::cout<<tmp.x<<" "<<tmp.y<<"\n";
    }
    std::cout<<std::endl;
    return 0;
}
