#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#define VECTOR2_LENGTH(v) \
	sqrt(VECTOR2_SQUARE_LENGTH)

#define VECTOR2_SQUARE_LENGTH(v) \
	(v->x * v->x + v->y * v->y)

#endif // MATH_UTILS_H
