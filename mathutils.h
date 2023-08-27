#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#define VECTOR2_SQUARE_LENGTH(v) \
	(v->x * v->x + v->y * v->y)

#define VECTOR2_LENGTH(v) \
	sqrt(v->x * v->x + v->y * v->y)

#define VECTOR2_NORMALIZE(v) \
	{ \
		float length = VECTOR2_LENGTH(v); \
		v->x /= length; \
		v->y /= length; \
	}

#define VECTOR2_ABSOLUTE(v) \
	{ \
		v->x = fabs(v->x); \
		v->y = fabs(v->y); \
	}

#define VECTOR2_DOT(v1, v2) \
	(v1->x * v2->x + v1->y * v2->y)

#endif // MATH_UTILS_H
