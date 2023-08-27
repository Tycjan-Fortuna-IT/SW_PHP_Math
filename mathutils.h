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

#endif // MATH_UTILS_H
