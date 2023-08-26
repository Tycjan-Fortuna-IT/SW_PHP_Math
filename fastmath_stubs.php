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
    }
}