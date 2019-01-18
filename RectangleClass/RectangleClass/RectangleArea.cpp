#include<iostream>
#include<vector>
using namespace std;

class Rectangle
{
	float Width;
	float Length;
	float Area;
	
	public:	
		Rectangle(float W, float L)
		{
			Width = W;
			Length = L;
			Area = W*L; //Area
		}

	float getWidth()//W

	{
		return Width;
	}

	float getLength()//L
	{
		return Length;
	}

	float getArea()//Area
	{
		return Area;
	}
};

void main()
{
	Rectangle *rec; 
	float area = 0, width, length; //Largest
	vector<Rectangle> rectangle;
	vector<Rectangle>::iterator i; 

	//Creating hardcoded rectangles
	rec = new Rectangle(12, 5);
	rectangle.push_back(*rec);
	rec = new Rectangle(10, 5);
	rectangle.push_back(*rec);
	rec = new Rectangle(50, 5);
	rectangle.push_back(*rec);
	rec = new Rectangle(20, 5);
	rectangle.push_back(*rec);
	
	//Iterate through
	for (i = rectangle.begin(); i != rectangle.end(); ++i)
	{
		//Checking each area to see if it's larger
		if (area < i->getArea())
		{
			length = i->getLength();
			width = i->getWidth();
			area = i->getArea();
		}
	}
	cout << "Largest Rectangle: ";
	cout << "\nArea: " << area <<"\n";
	system("pause");
}