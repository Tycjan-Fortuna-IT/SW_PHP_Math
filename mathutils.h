/**
 * @file mathutils.h
 * @author Tycjan Fortuna
 * @brief Provides some useful math macros and functions.
 * @version 0.1
 * @date 2023-08-28
 * @copyright Copyright (c) 2023
 */

#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#define VECTOR2_SQUARE_LENGTH(v) \
	(v->x * v->x + v->y * v->y)

#define VECTOR2_LENGTH(v) \
	sqrt(VECTOR2_SQUARE_LENGTH(v))

#define VECTOR2_NORMALIZE(v)              \
	{                                     \
		float length = VECTOR2_LENGTH(v); \
		v->x /= length;                   \
		v->y /= length;                   \
	}

#define VECTOR2_ABSOLUTE(v) \
	{                       \
		v->x = fabs(v->x);  \
		v->y = fabs(v->y);  \
	}

#define VECTOR2_NEGATE(v) \
	{                     \
		v->x = -v->x;     \
		v->y = -v->y;     \
	}

#define VECTOR2_EQUALS(v1, v2) \
	(v1->x == v2->x && v1->y == v2->y)

#define VECTOR2_DOT(v1, v2) \
	(v1->x * v2->x + v1->y * v2->y)

#define VECTOR2_ANGLE_BETWEEN(v1, v2) \
	acos(VECTOR2_DOT(v1, v2) / (VECTOR2_LENGTH(v1) * VECTOR2_LENGTH(v2)))

#define VECTOR2_DISTANCE_BETWEEN_SQUARED(v1, v2) \
	((v1->x - v2->x) * (v1->x - v2->x) + (v1->y - v2->y) * (v1->y - v2->y))

#define VECTOR2_DISTANCE_BETWEEN(v1, v2) \
    sqrt(VECTOR2_DISTANCE_BETWEEN_SQUARED(v1, v2))

#define VECTOR2_SCALE(v, s) \
	{                       \
		v->x *= s;          \
		v->y *= s;          \
	}

#define VECTOR2_ADD(v1, v2) \
	{                       \
		v1->x += v2->x;     \
		v1->y += v2->y;     \
	}

#define VECTOR2_SUBTRACT(v1, v2) \
	{                            \
		v1->x -= v2->x;          \
		v1->y -= v2->y;          \
	}

#define VECTOR2_MULTIPLY(v1, v2) \
	{                            \
		v1->x *= v2->x;          \
		v1->y *= v2->y;          \
	}

#define VECTOR2_DIVIDE(v1, v2) \
	{                          \
		v1->x /= v2->x;        \
		v1->y /= v2->y;        \
	}

#define VECTOR2_LERP(v1, v2, t) \
	{                           \
		v1->x += (v2->x - v1->x) * t; \
		v1->y += (v2->y - v1->y) * t; \
	}

#define VECTOR2_SLERP(v1, v2, t) \
	{                           \
		float dot = v1->x * v2->x + v1->y * v2->y; \
		float angle = acos(dot); \
		if (angle < 0.000001) { \
			v1->x = v1->x + t * (v2->x - v1->x); \
			v1->y = v1->y + t * (v2->y - v1->y); \
		} else { \
			float sinAngle = sin(angle); \
			float sinAngle1 = sin(angle * (1 - t)); \
			float sinAngle2 = sin(angle * t); \
			v1->x = (sinAngle1 * v1->x + sinAngle2 * v2->x) / sinAngle; \
			v1->y = (sinAngle1 * v1->y + sinAngle2 * v2->y) / sinAngle; \
		} \
	}

#define PI 3.14159265358979323846

#define RAD_TO_DEG(rad) \
	(rad * 180.0 / PI)

#define DEG_TO_RAD(deg) \
	(deg * PI / 180.0)

#define CLAMP(value, min, max) \
	(value < min ? min : (value > max ? max : value))

#endif // MATH_UTILS_H
