/**
* Copyright (C) 2007-2010 SlimDX Group
*
* Permission is hereby granted, free  of charge, to any person obtaining a copy of this software  and
* associated  documentation  files (the  "Software"), to deal  in the Software  without  restriction,
* including  without  limitation  the  rights  to use,  copy,  modify,  merge,  publish,  distribute,
* sublicense, and/or sell  copies of the  Software,  and to permit  persons to whom  the Software  is
* furnished to do so, subject to the following conditions:
*
* The  above  copyright  notice  and this  permission  notice shall  be included  in  all  copies  or
* substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS",  WITHOUT WARRANTY OF  ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
* NOT  LIMITED  TO  THE  WARRANTIES  OF  MERCHANTABILITY,  FITNESS  FOR  A   PARTICULAR  PURPOSE  AND
* NONINFRINGEMENT.  IN  NO  EVENT SHALL THE  AUTHORS  OR COPYRIGHT HOLDERS  BE LIABLE FOR  ANY CLAIM,
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  OUT
* OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Vector2.hpp"

namespace GTA
{
	namespace Math
	{
		using namespace System;
		using namespace System::Globalization;

		Vector2::Vector2(float x, float y)
		{
			X = x;
			Y = y;
		}

		float Vector2::Length()
		{
			return static_cast<float>(System::Math::Sqrt((X*X) + (Y*Y)));
		}
		float Vector2::LengthSquared()
		{
			return (X * X) + (Y * Y);
		}
		void Vector2::Normalize()
		{
			float length = Length();
			if (length == 0) return;
			float num = 1 / length;
			X *= num;
			Y *= num;
		}
		float Vector2::DistanceTo(Vector2 position)
		{
			return (position - *this).Length();
		}

		Vector2 Vector2::Add(Vector2 left, Vector2 right)
		{
			return Vector2(left.X + right.X, left.Y + right.Y);
		}
		Vector2 Vector2::Subtract(Vector2 left, Vector2 right)
		{
			return Vector2(left.X - right.X, left.Y - right.Y);
		}
		Vector2 Vector2::Modulate(Vector2 left, Vector2 right)
		{
			return Vector2(left.X * right.X, left.Y * right.Y);
		}
		Vector2 Vector2::Multiply(Vector2 value, float scale)
		{
			return Vector2(value.X * scale, value.Y * scale);
		}
		Vector2 Vector2::Divide(Vector2 value, float scale)
		{
			return Vector2(value.X / scale, value.Y / scale);
		}
		Vector2 Vector2::Negate(Vector2 value)
		{
			return Vector2(-value.X, -value.Y);
		}
		Vector2 Vector2::Clamp(Vector2 value, Vector2 min, Vector2 max)
		{
			float x = value.X;
			x = (x > max.X) ? max.X : x;
			x = (x < min.X) ? min.X : x;

			float y = value.Y;
			y = (y > max.Y) ? max.Y : y;
			y = (y < min.Y) ? min.Y : y;

			return Vector2(x, y);
		}
		Vector2 Vector2::Lerp(Vector2 start, Vector2 end, float factor)
		{
			Vector2 vector;

			vector.X = start.X + ((end.X - start.X) * factor);
			vector.Y = start.Y + ((end.Y - start.Y) * factor);

			return vector;
		}
		float Vector2::Dot(Vector2 left, Vector2 right)
		{
			return (left.X * right.X + left.Y * right.Y);
		}
		Vector2 Vector2::Reflect(Vector2 vector, Vector2 normal)
		{
			Vector2 result;
			float dot = ((vector.X * normal.X) + (vector.Y * normal.Y));

			result.X = vector.X - ((2.0f * dot) * normal.X);
			result.Y = vector.Y - ((2.0f * dot) * normal.Y);

			return result;
		}
		Vector2 Vector2::Normalize(Vector2 vector)
		{
			vector.Normalize();
			return vector;
		}
		Vector2 Vector2::Minimize(Vector2 left, Vector2 right)
		{
			Vector2 vector;
			vector.X = (left.X < right.X) ? left.X : right.X;
			vector.Y = (left.Y < right.Y) ? left.Y : right.Y;
			return vector;
		}
		Vector2 Vector2::Maximize(Vector2 left, Vector2 right)
		{
			Vector2 vector;
			vector.X = (left.X > right.X) ? left.X : right.X;
			vector.Y = (left.Y > right.Y) ? left.Y : right.Y;
			return vector;
		}

		Vector2 Vector2::operator + (Vector2 left, Vector2 right)
		{
			return Vector2(left.X + right.X, left.Y + right.Y);
		}
		Vector2 Vector2::operator - (Vector2 left, Vector2 right)
		{
			return Vector2(left.X - right.X, left.Y - right.Y);
		}
		Vector2 Vector2::operator - (Vector2 value)
		{
			return Vector2(-value.X, -value.Y);
		}
		Vector2 Vector2::operator * (Vector2 value, float scale)
		{
			return Vector2(value.X * scale, value.Y * scale);
		}
		Vector2 Vector2::operator * (float scale, Vector2 vec)
		{
			return vec * scale;
		}
		Vector2 Vector2::operator / (Vector2 value, float scale)
		{
			return Vector2(value.X / scale, value.Y / scale);
		}
		bool Vector2::operator == (Vector2 left, Vector2 right)
		{
			return Vector2::Equals(left, right);
		}
		bool Vector2::operator != (Vector2 left, Vector2 right)
		{
			return !Vector2::Equals(left, right);
		}

		String ^Vector2::ToString()
		{
			return String::Format(CultureInfo::InvariantCulture, "X:{0} Y:{1}", X.ToString(), Y.ToString());
		}
		int Vector2::GetHashCode()
		{
			return X.GetHashCode() + Y.GetHashCode();
		}
		bool Vector2::Equals(Object ^value)
		{
			if (value == nullptr)
				return false;

			if (value->GetType() != GetType())
				return false;

			return Equals(safe_cast<Vector2>(value));
		}
		bool Vector2::Equals(Vector2 value)
		{
			return (X == value.X && Y == value.Y);
		}
		bool Vector2::Equals(Vector2 %value1, Vector2 %value2)
		{
			return (value1.X == value2.X && value1.Y == value2.Y);
		}
	}
}