#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    string id;
    int x, y;
    char direction;
    int speed;

    virtual void move() = 0;
};

class Rectangle : public Shape {
public:
    int LX, LY;

    void move() override {
        // Implement movement logic for Rectangle
    }
};

class Circle : public Shape {
public:
    int r;

    void move() override {
        // Implement movement logic for Circle
    }
};
vector<Shape*> shapes; // Use a vector of pointers to the base class Shape

bool check_collision() {
    for (const auto& shape1 : shapes) {
        for (const auto& shape2 : shapes) {

        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("2.txt", "r", stdin);

    while (true) {
        string t;
        cin >> t;

        if (t == "#") {
            break;
        } else if (t == "create") {
            string shape;
            cin >> shape;

            if (shape == "RECTANGLE") {
                Rectangle* rec = new Rectangle(); 
                cin >> rec->id >> rec->x >> rec->y >> rec->LX >> rec->LY >> rec->direction >> rec->speed;
                shapes.push_back(rec); 
            } else {
                Circle* circ = new Circle(); 
                cin >> circ->id >> circ->x >> circ->y >> circ->r >> circ->direction >> circ->speed;
                shapes.push_back(circ); 
            }

        } else if (t == "move") {
            if(check_collision()){
                for (auto shape : shapes) {
                    if(shape->direction == 'L'){
                        shape->x -= shape->speed;
                    } else if (shape->direction == 'R'){
                        shape->x += shape->speed;
                    } else if (shape->direction == 'U'){
                        shape->y += shape->speed;                        
                    } else {
                        shape->y -= shape->speed;
                    }
                }
            }
        } else if (t == "change_direction") {
            string id;
            char direction;
            int speed;
            cin >> id >> direction >> speed;
            bool found = false;
            for (auto shape : shapes) {
                if (shape->id == id) {
                    shape->direction = direction;
                    shape->speed = speed;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NULL" << endl;
            }
        } else if (t == "view_position") {
            string id;
            cin >> id;
            bool found = false;
            for (const auto shape : shapes) {
                if (shape->id == id) {
                    cout << shape->x << " " << shape->y << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NULL" << endl;
            }
        }
    }


    return 0;
}