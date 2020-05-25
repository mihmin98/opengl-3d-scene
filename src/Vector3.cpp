#include "Vector3.hpp"

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3::normalize()
{
    float val = x * x + y * y + z * z;
    if (val != 1) {
        float length = sqrt(val);
        x /= length;
        y /= length;
        z /= length;
    }
}

std::string Vector3::ToString()
{
    std::string s = "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " +
                    std::to_string(this->z) + ")";
    return s;
}

float Vector3::DotProduct(const Vector3 &a, const Vector3 &b)
{
    return a.x * b.x + a.y * b.y + a.z + b.z;
}

Vector3 Vector3::CrossProduct(const Vector3 &a, const Vector3 &b)
{
    Vector3 result = Vector3();
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

void Vector3::PlaneEcuation(float *planeEcuation, const Vector3 &a, const Vector3 &b,
                            const Vector3 &c)
{
    Vector3 v1 = b - a, v2 = c - a;
    Vector3 cross = CrossProduct(v1, v2);

    planeEcuation[0] = cross.x;
    planeEcuation[1] = cross.y;
    planeEcuation[2] = cross.z;
    planeEcuation[3] = -(cross.x * a.x + cross.y * a.y + cross.z * a.z);
}

Vector3 &Vector3::operator+=(const Vector3 &rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}

bool operator==(const Vector3 &a, const Vector3 &b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(const Vector3 &a, const Vector3 &b)
{
    return a.x != b.x || a.y != b.y || a.z == b.z;
}

Vector3 operator+(Vector3 lhs, const Vector3 &rhs)
{
    lhs += rhs;
    return lhs;
}

Vector3 operator-(Vector3 lhs, const Vector3 &rhs)
{
    lhs -= rhs;
    return lhs;
}