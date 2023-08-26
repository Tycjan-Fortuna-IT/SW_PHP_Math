<?php

namespace SW\Math {
    class Vector2f
    {
        /**
         * Creates a new instance of Vector2f.
         *
         * @param float $x X coordinate of the vector.
         * @param float $y Y coordinate of the vector.
         */
        public function __construct(public float $x = 0.0, public float $y = 0.0) {}

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
    }
}
