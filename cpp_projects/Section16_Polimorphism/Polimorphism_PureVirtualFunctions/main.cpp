#include <iostream>
#include <vector>

using namespace std;

class Shape //!!! ABSTRACT BASE CLASS
{
private:
    //attributes common for all shapes
public:
    virtual void Draw() = 0; //!!! PURE VIRTUAL FUNCTION
    virtual void Rotate() = 0; //!!! PURE VIRTUAL FUNCTION
    virtual ~Shape() {}
};

class OpenShape : public Shape //!!! ABSTRACT CLASS
{
private:
    //attributes common only for open shapes
public:
    virtual ~OpenShape() {}
};

class ClosedShape : public Shape //!!! ABSTRACT CLASS
{
private:
    //attributes common only for closed shapes
public:
    virtual ~ClosedShape() {}
};
  
class Line : public OpenShape //!!! CONCREAT CLASS
{
private:
    //attributes common only for open shapes
public:
    virtual void Draw() override //!!! OVERRIDED VIRTUAL FUNCTION
    {
        cout << "Drawing: Line" << endl;
    }
    virtual void Rotate() override //!!! OVERRIDED VIRTUAL FUNCTION
    {
        cout << "Rotating: Line" << endl;
    }
    virtual ~Line() {}
};

class Circle : public ClosedShape //!!! CONCREAT CLASS
{
private:
    //attributes common only for open shapes
public:
    virtual void Draw() override //!!! OVERRIDED VIRTUAL FUNCTION
    {
        cout << "Drawing: Circle" << endl;
    }
    virtual void Rotate() override //!!! OVERRIDED VIRTUAL FUNCTION
    {
        cout << "Rotating: Circle" << endl;
    }
    virtual ~Circle() {}
};

class Square : public ClosedShape //!!! CONCREAT CLASS
{
private:
    //attributes common only for open shapes
public:
    virtual void Draw() override //!!! OVERRIDED VIRTUAL FUNCTION
    {
        cout << "Drawing: Square" << endl;
    }
    virtual void Rotate() override //!!! OVERRIDED VIRTUAL FUNCTION
    {
        cout << "Rotating: Square" << endl;
    }
    virtual ~Square() {}
};
  
void ScreenRefresh(const std::vector<Shape*> &pShapes)
{
    cout << "Refreshing" << endl;
    for (const auto pShape: pShapes)
        pShape->Draw();
}
  
int main()
{
    //Shape s;  //error
    //Shape* pShape = new Shape(); //error
    
    //Shape* pShapeLine = new Line();
    //pShapeLine->Draw();
    //pShapeLine->Rotate();
    
    Shape* pShapeLine = new Line();
    Shape* pShapeCircle = new Circle();
    Shape* pShapeSquare = new Square();
    
    std::vector<Shape*> pShapes {pShapeLine, pShapeCircle, pShapeSquare};
    
    /*for (const auto pShape: pShapes)
        pShape->Draw();
   
    for (const auto pShape: pShapes)
        pShape->Rotate();*/
        
    ScreenRefresh(pShapes);
   
    for (auto ptr: pShapes)
        delete ptr;
   
    /*delete pShapeLine;
    delete pShapeCircle;
    delete pShapeSquare;*/
    
	return 0;
}

