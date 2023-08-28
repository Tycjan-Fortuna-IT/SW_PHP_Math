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
	sqrt(v->x * v->x + v->y * v->y)

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

#define PI 3.14159265358979323846

#define RAD_TO_DEG(rad) \
	(rad * 180.0 / PI)

#define DEG_TO_RAD(deg) \
	(deg * PI / 180.0)

#endif // MATH_UTILS_H
