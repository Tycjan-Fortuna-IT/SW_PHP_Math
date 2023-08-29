<?php

namespace SW\Math {
    class Vector2f
    {
        /**
         * Creates a new instance of Vector2f.
         *
         * @param ?float $x X coordinate of the vector.
         * @param ?float $y Y coordinate of the vector.
         */
        public function __construct(public ?float $x = 0.0, public ?float $y = 0.0) {}

        /**
         * Returns a string representation of the vector.
         * If precision is not specified, the default precision is 5 digits.
         *
         * @param ?int $precision Number of digits after the decimal point.
         *
         * @return string
         */
        public function toString(?int $precision = 0): string {}

        /**
         * Returns the length of the vector.
         *
         *
         * @return float
         */
        public function length(): float {}

        /**
         * Returns the squared length of the vector.
         *
         * @return float
         */
        public function lengthSquared(): float {}

        /**
         * Returns converted Vector2f object as an array.
         * The array representation is [0 => x, 1 => y].
         *
         * @return array
         */
        public function toArray(): array {}

        /**
         * Returns converted Vector2f object as a JSON string.
         * If precision is not specified, the default precision is 5 digits.
         *
         * @param ?int $precision Number of digits after the decimal point.
         *
         * @return string
         */
        public function toJSON(?int $precision = 0): string {}

        /**
         * Negates the vector.
         *
         * @return void
         */
        public function negate(): void {}

        /**
         * Returns the negated vector.
         *
         * @param Vector2f $vector Vector to negate.
         *
         * @return Vector2f
         */
        public static function negated(Vector2f $vector): Vector2f {}

        /**
         * Normalizes the vector.
         *
         * @return void
         */
        public function normalize(): void {}

        /**
         * Returns the normalized vector.
         *
         * @param Vector2f $vector Vector to normalize.
         *
         * @return Vector2f
         */
        public static function normalized(Vector2f $vector): Vector2f {}

        /**
         * Absolute the vector.
         *
         * @return void
         */
        public function absolute(): void {}

        /**
         * Returns the absolute vector.
         *
         * @param Vector2f $vector Vector to absolute.
         *
         * @return Vector2f
         */
        public static function absoluted(Vector2f $vector): Vector2f {}

        /**
         * Dot product of two vectors.
         *
         * @param Vector2f $vector Vector to dot.
         *
         * @return float
         */
        public function dot(Vector2f $vector): float {}

        /**
         * Returns the dot product of two vectors.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         *
         * @return float
         */
        public static function dotted(Vector2f $vector1, Vector2f $vector2): float {}

        /**
         * Returns the angle between this vector and another vector.
         * The angle is in radians.
         *
         * @param Vector2f $vector Vector to get the angle.
         *
         * @return float
         */
        public function angleBetween(Vector2f $vector): float {}

        /**
         * Returns the angle between two vectors. The angle is in radians.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         *
         * @return float
         */
        public static function angleBetweenVectors(Vector2f $vector1, Vector2f $vector2): float {}

        /**
         * Returns the angle between this vector and another vector.
         * The angle is in degrees.
         *
         * @param Vector2f $vector Vector to get the angle.
         *
         * @return float
         */
        public function angleBetweenDeg(Vector2f $vector): float {}

        /**
         * Returns the angle between two vectors. The angle is in degrees.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         *
         * @return float
         */
        public static function angleBetweenVectorsDeg(Vector2f $vector1, Vector2f $vector2): float {}

        /**
         * Check if both vectors are equal. Casual == operator is not recommended.
         *
         * @param Vector2f $vector Vector to check.
         *
         * @return bool
         */
        public function equals(Vector2f $vector): bool {}

        /**
         * Check if two vectors are equal. Casual == operator is not recommended.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         *
         * @return bool
         */
        public static function equalVectors(Vector2f $vector1, Vector2f $vector2): bool {}

        /**
         * Returns the distance between this vector and another vector.
         *
         * @param Vector2f $vector Vector to get the distance.
         *
         * @return float
         */
        public function distanceBetween(Vector2f $vector): float {}

        /**
         * Returns the distance between two vectors.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         *
         * @return float
         */
        public static function distanceBetweenVectors(Vector2f $vector1, Vector2f $vector2): float {}

        /**
         * Returns the squared distance between this vector and another vector.
         *
         * @param Vector2f $vector Vector to get the distance.
         *
         * @return float
         */
        public function distanceBetweenSquared(Vector2f $vector): float {}

        /**
         * Returns the squared distance between two vectors.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         *
         * @return float
         */
        public static function distanceBetweenVectorsSquared(Vector2f $vector1, Vector2f $vector2): float {}

        /**
         * Scale the vector.
         *
         * @param float $scale Scale factor.
         *
         * @return void
         */
        public function scale(float $scale): void {}

        /**
         * Returns the scaled vector.
         *
         * @param Vector2f $vector Vector to scale.
         * @param float $scale Scale factor.
         *
         * @return Vector2f
         */
        public static function scaled(Vector2f $vector, float $scale): Vector2f {}

        /**
         * Linear interpolation between this and passed vector.
         * The interpolation parameter $t is clamped to the range [0, 1].
         * If $t = 0, the method returns $vector1.
         * If $t = 1, the method returns $vector2.
         * If $t = 0.5, the method returns the midpoint of the line segment between $vector1 and $vector2.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         * @param float $t Interpolation parameter.
         */
        public function lerp(Vector2f $vector, float $t): void {}

        /**
         * Returns the linear interpolation between two vectors.
         * The interpolation parameter $t is clamped to the range [0, 1].
         * If $t = 0, the method returns $vector1.
         * If $t = 1, the method returns $vector2.
         * If $t = 0.5, the method returns the midpoint of the line segment between $vector1 and $vector2.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         * @param float $t Interpolation parameter.
         *
         * @return Vector2f
         */
        public static function lerped(Vector2f $vector1, Vector2f $vector2, float $t): Vector2f {}

        /**
         * Spherical linear interpolation between this and passed vector.
         * The interpolation parameter $t is clamped to the range [0, 1].
         * If $t = 0, the method returns $vector1.
         * If $t = 1, the method returns $vector2.
         * If $t = 0.5, the method returns the midpoint of the line segment between $vector1 and $vector2.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         * @param float $t Interpolation parameter.
         */
        public function slerp(Vector2f $vector, float $t): void {}

        /**
         * Returns the spherical linear interpolation between two vectors.
         * The interpolation parameter $t is clamped to the range [0, 1].
         * If $t = 0, the method returns $vector1.
         * If $t = 1, the method returns $vector2.
         * If $t = 0.5, the method returns the midpoint of the line segment between $vector1 and $vector2.
         *
         * @param Vector2f $vector1 First vector.
         * @param Vector2f $vector2 Second vector.
         * @param float $t Interpolation parameter.
         *
         * @return Vector2f
         */
        public static function slerped(Vector2f $vector1, Vector2f $vector2, float $t): Vector2f {}
    }
}
