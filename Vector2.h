#pragma once
#include <cmath>
#include "Component.h"

class Vector2 : public Component{
private:
	double x, y;

public:	
	Vector2():x(0),y(0){};
	Vector2(const Vector2& v):x(v.x), y(v.y){};
	Vector2(double x, double y):x(x), y(y){};

	//���W
	double getX(){ return x; }
	double getY(){ return y; }

	//���
	Vector2& operator=(const Vector2& v){
		x = v.x;
		y = v.y;
		return *this;
	}
	//��r
	bool operator==(const Vector2& v) const{
		return (x == v.x && y == v.y);
	}
	bool operator!=(const Vector2& v) const{
		return (x != v.x || y != v.y);
	}

	//����
	const Vector2& operator+() const{
		return *this;
	}
	Vector2 operator-() const{
		return Vector2(-x, -y);
	}

	//�����Z
	Vector2 operator+(const Vector2& v) const{
		return Vector2(x + v.x, y + v.y);
	}
	Vector2& operator+=(const Vector2& v){
		x += v.x;
		y += v.y;
		return *this;
	}
	Vector2 operator-(const Vector2& v) const{
		return Vector2(x - v.x, y - v.y);
	}
	Vector2& operator-=(const Vector2& v){
		x -= v.x;
		y -= v.y;
		return *this;
	}
};
