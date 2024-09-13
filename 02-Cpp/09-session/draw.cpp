#include <iostream>

class shape{
    public:
        virtual void draw() = 0;
};

class circle : public shape{
    public:
        void draw() override {
            std::cout << "Drawing a circle" << std::endl;
        }
};

class rectangle : public shape{
    public:
        void draw() override{
            std::cout << "Drawing a rectangle" << std::endl;
        }
};

int main()
{
    shape* shape1 = new circle();
    shape* shape2 = new rectangle();
    shape1->draw();
    shape2->draw();
    delete shape1;
    delete shape2;
  return 0;
}