#pragma once
class Vector3
{
public:
	Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}

	Vector3 operator+(const Vector3& other) { return Vector3(X + other.X, Y + other.Y, Z + other.Z); }

	bool operator == (const Vector3& other) { return X == other.X && Y == other.Y && Z == other.Z; }

public:
	float X, Y, Z;
};

