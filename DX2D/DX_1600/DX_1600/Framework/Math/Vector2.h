#pragma once

class Vector2
{
public:
    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2(int x, int y) : x((float)x), y((float)y) {}
    ~Vector2() {}

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(this->x + other.x, this->y + other.y);
    }
    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(this->x - other.x, this->y - other.y);
    }
    Vector2 operator*(const float& other) const
    {
        return Vector2(this->x * other, this->y * other);
    }
    Vector2 operator+=(const Vector2& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Vector2 operator-=(const Vector2& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }
 
    float Dot(const Vector2& other) const
    {
        return (this->x * other.x + this->y * other.y);
    }
    float Cross(const Vector2& other) const
    {
        return (this->x * other.y - this->y * other.x);
    }
    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;
    bool operator<(const Vector2& other) const // 프림 알고리즘 용 임시 비교
    {
        if (y != other.y)
        {
            return y < other.y;
        }

        return x < other.x;
    }
    bool operator>(const Vector2& other) const // 프림 알고리즘 용 임시 비교
    {
        if (y != other.y)
        {
            return y > other.y;
        }

        return x > other.x;
    }
    float Length() const
    {
        return sqrtf(powf(x, 2) + powf(y, 2));
    }
    float Distance(const Vector2& other) const
    {
        float resultX = x - other.x;
        float resultY = y - other.y;

        return sqrtf(powf(resultX, 2) + powf(resultY, 2));
    }
    float Angle() const { return atan2f(y, x); }
    int MahattanDistance(const Vector2& other) const;
    void Normallize()
    {
        this->x /= Length();
        this->y /= Length();
    }
    Vector2 NormalVector2() const
    {
        Vector2 result;
        result.x = this->x / Length();
        result.y = this->y / Length();

        return result;
    }


    bool IsBetween(Vector2 v1, Vector2 v2);

    float x;
    float y;
};
