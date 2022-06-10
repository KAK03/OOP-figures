#include <iostream>

using namespace std;

class Figure//абстрактный класс предок
{
	int Height, Weight;//инкапсуляция
public:
	Figure(int Height, int Weight)
	{
		this->Height = Height;
		this->Weight = Weight;
	}
	virtual void ShowMsg()=0;
};

class Square : public Figure//наследование
{

public:
	Square(int Height, int Weight) : Figure(Height, Weight)
	{
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Weight; j++)
			{
				cout << '*'<<' ';
			}
			cout << endl;
		}
	}
	void ShowMsg() override//полиморфизм
	{
		cout << "Квадрат";
	}
};

class Rectangle : public Figure
{

public:
	Rectangle(int Height, int Weight) : Figure(Height, Weight)
	{
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Weight; j++)
			{
				cout << '*' << ' ';
			}
			cout << endl;
		}
	}
	void ShowMsg() override
	{
		cout << "Прямоугольник";
	}
};

class Triangle : public Figure
{

public:
	Triangle(int Height, int Weight) : Figure(Height, Weight)
	{
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Weight; j++)
			{
				if (j <= i)
				{
					cout << '*' << ' ';
				}
			}
			cout << endl;
		}
	}
	void ShowMsg() override
	{
		cout << "Прямоугольный треугольгик";
	}
};

class Romb :public Figure
{

public:
	Romb(int Height, int Weight) : Figure(Height, Weight)
	{
		int position=0;
		for (int i = 1; i <= Height; i++)
		{
			for (int j = 1; j <= Weight; j++)
			{
				(j <= Weight / 2 + 1 + position) && (j >= Weight / 2 + 1 - position) ? cout << '*' << ' ' : cout << ' ' << ' ';
			}
			cout << endl;
			i < Height / 2 + 1 ? position++ : position--;
		}
	}
	void ShowMsg() override
	{
		cout << "Ромб";
	}
};

class RTriangle : public Figure
{

public:
	RTriangle(int Height, int Weight) : Figure(Height, Weight)
	{
		int position = 0;
		for (int i = 1; i <= Height; i++)
		{
			for (int j = 1; j <= Height * (Height + Height - 1); j++)
			{
				if ((j >= (Height - position)) && (j <= (Height + position)))
				{
					cout << "*"<<' ';
				}
				else
				{
					cout << " "<<' ';
				}
			}
			position++;
			cout << endl;
		}
	}
	void ShowMsg() override
	{
		cout << "Равнобедренный треугольник";
	}
};
	

int main()
{
	setlocale(LC_ALL, "ru");
	int H, W;
	cout << "Введите высоту:";
	cin >> H;
	cout << "Введите ширину:";
	cin >> W;
	/*
	(H==W)? Square s(H, W): Rectangle r(H, W);
	*/
	if (H == W)
	{
		Square s(H, W);
		s.ShowMsg();
		cout << endl<<endl;
		Triangle t(H, W);
		t.ShowMsg();
		cout << endl << endl;
		if (H % 2 == 1)
		{
			Romb R(H, W);
			R.ShowMsg();
			cout << endl << endl;
		}
	}
	else
	{
		Rectangle r(H, W);
		r.ShowMsg();
		cout << endl << endl;
		RTriangle rt(H, W);
		rt.ShowMsg();
		cout << endl << endl;
	}
	cout << endl;
	
}