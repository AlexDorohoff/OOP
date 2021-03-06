// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
/*
Интерфейс объектов, способных сохранять (SaveTo) и
восстанавливать (RestoreFrom) своё состояние из/в стандартных потоков чтения/записи
В случае ошибки выбрасывают исключения runtime_error
*/

class CPoint
{
public:
	double x;
	double y;
};

class ISerializable
{
	/* Написать недостающий код */
};

class ICanvas
{
public:
	virtual void DrawTheLine(const CPoint& pointOne, const CPoint& pointTwo) = 0;
	virtual void DrawTheEllips(const CPoint& center, const int& radius) = 0;
};

/* Интерфейс объектов, которые могут быть нарисованы (Draw) на холсте (canvas) */
class ICanvasDrawable
{
public:
	virtual void Draw(ICanvas& canvas) = 0;
};

/* Интерфейс объектов, умеющих говорить (Speak). */
class ISpeakable
{
};

class CoutCanvas : public ICanvas
{
public:
	virtual void DrawTheLine(const CPoint& pointOne, const CPoint& pointTwo) override
	{
		std::cout << "Draw the line at " << pointOne.x << "." << pointOne.y << " to " << pointTwo.x << "." << pointTwo.y << "\n";
	}

	virtual void DrawTheEllips(const CPoint& center, const int& radius) override
	{
		std::cout << "Draw ellips whith center at: " << center.x << " " << center.y << " and radius" << radius << "\n";
	}

private:
};

/* Прямоугольник. Может быть нарисован на холсте, а также является сериализуемым */
class Rectangle : public virtual ICanvasDrawable
{
public:
	Rectangle(const CPoint& leftTop, const CPoint& rigthBottom)
		: m_leftTop(leftTop)
		, m_rightBottom(rigthBottom)){};

	void Draw(ICanvas& canvas) override
	{
		CPoint rigthTop = { m_rightBottom.x m_leftTop.y };
		canvas.DrawTheLine(m_leftTop, rightTop);
		canvas.DrawTheLine(rightTop, m_rightBottom);
		CPoint leftBottom = { m_leftTop.x, m_rightBottom.y };
		canvas.DrawTheLine(m_rightBottom, leftBottom);
		canvas.DrawTheLine(leftBottom, m_leftTop);
	}

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};

/* Эллипс. Может быть нарисован на холсте, а также является сериализуемым */
class Ellipse : public virtual ICanvasDrawable /* Написать недостающий код */
{
public:
	Ellipse(CPoint const& center, double radius)
		: m_center(center)
		, m_radius(radius){};
	void Draw(ICanvas& canvas)
	{
		canvas.DrawTheEllips(m_center, m_radius);
	}

private:
	CPoint m_center;
	int m_radius = 1;
};

/* Треугольник. Может быть нарисован на холсте, а также является сериализуемым */
class Triangle : public virtual ICanvasDrawable /* Написать недостающий код */
{
public:
	Triangle(const CPoint& pointOne, const CPoint& pointTwo, const CPoint& pointThree)
		: m_pointOne(pointOne)
		, m_pointTwo(pointTwo)
		, m_pointThree(pointThree){};

	void Draw(ICanvas& canvas) override
	{
		canvas.DrawTheLine(m_pointOne, m_pointTwo);
		canvas.DrawTheLine(m_pointTwo, m_pointThree);
		canvas.DrawTheLine(m_pointThree, m_pointOne);
	}

private:
	CPoint m_pointOne;
	CPoint m_pointTwo;
	CPoint m_pointThree;
};

/* Холст. Вместо фактического рисования выводит в cout команды рисования и их параметры */

/* Кот. Обладает координатами (в центре головы). Может быть нарисован на холсте
может говорить (мяукая) */
class Cat : public virtual ICanvasDrawable /* Написать недостающий код */
{
public:
	Cat(const CPoint& head, int radius, const CPoint& oneLeg, const CPoint& twoLeg, const CPoint& threeLeg, const CPoint& fourLeg, const CPoint& back)
		: m_hed(head)
		, m_radius(radius)
		, m_oneLeg(oneLeg)
		, m_twoLeg(twoLeg)
		, m_threeLeg(threeLeg)
		, m_fourLeg(fourLeg)
		, m_back(back){};
	void Draw(ICanvas& canvas)
	{
		canvas.DrawTheEllips(m_hed, m_radius);
		canvas.DrawTheLine(m_back, m_oneLeg);
		canvas.DrawTheLine(m_back, m_twoLeg);
		canvas.DrawTheLine(m_back, m_threeLeg);
		canvas.DrawTheLine(m_back, m_fourLeg);
	}

private:
	CPoint m_hed;
	int m_radius;
	CPoint m_oneLeg;
	CPoint m_twoLeg;
	CPoint m_threeLeg;
	CPoint m_fourLeg;
	CPoint m_back;
};

/* Человек. Обладает именем и годом рождения.
может говорить (называет своё имя и год рождения) */
class Person
{
};

/* Ведёт разговор с набором объектов, с которыми можно побеседовать */
void SmallTalk(/* Написать недостающий код */)
{
	/* Написать недостающий код, заставляющий беседовать с объектами */
}

/* Рисует набор объектов, которые можно нарисовать на переданном холсте (принимает объекты и холст) */
void Draw(/* Написать недостающий код */)
{
	/* Написать недостающий код */
}

/* Копирует состояние из одного сериализуемого объекта в другой */
void CopyState(const ISerializable& from, ISerializable& to)
{
	/* Написать недостающий код */
}

int main()
{
	Rectangle rec({ 1, 4 }, { 4, 4 }, { 4, 1 }, { 1, 1 });
	CoutCanvas canvas;
	rec.Draw(canvas);

	Triangle tri({ 1, 4 }, { 2, 6 }, { 4, 4 });
	tri.Draw(canvas);

	Cat cat({ 6, 4 }, 1, { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 6, 5 });
	cat.Draw(canvas);
	/*
	Нарисовать при помощи функции Draw домик с котиком рядом с ним:
	/\
	/  \
	/ O  \
	--------
	|    |
	|    |
	------
	до 8 баллов (8-6-4)
	*/

	/* Создать прямоугольник.
	Скопировать в него при помощи Copy состояние из прямоугольника,
	задающего стены дома
	до 7 баллов (7-5-3)
	*/

	/*
	Создать человека по имени Ivanov Ivan 1980 года рождения.
	При помощи SmallTalk побеседовать с этим человеом и вышесозданным котом
	до 7 баллов (7-5-3)
	*/

	return 0;
}
