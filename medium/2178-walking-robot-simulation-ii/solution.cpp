#include <vector>
#include <string>

using namespace std;

class Robot {
private:
    int width;
    int height;
    int perimeter;
    int position;
    bool has_moved;

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->perimeter = 2 * (width - 1) + 2 * (height - 1);
        this->position = 0;
        this->has_moved = false;
    }
    
    void step(int num) {
        has_moved = true;
        position = (position + num) % perimeter;
    }
    
    vector<int> getPos() {
        if (position == 0) return {0, 0};
        if (position < width) {
            return {position, 0};
        }
        else if (position < width + height - 1) {
            return {width - 1, position - (width - 1)};
        }
        else if (position < 2 * width + height - 2) {
            return {(width - 1) - (position - (width + height - 2)), height - 1};
        }
        else {
            return {0, (height - 1) - (position - (2 * width + height - 3))};
        }
    }
    
    string getDir() {
        if (position == 0) return has_moved ? "South" : "East";
    
        if (position < width) return "East";
        if (position < width + height - 1) return "North";
        if (position < 2 * width + height - 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */