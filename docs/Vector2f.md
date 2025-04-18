- # `Vector2f`
    ```php
    Vector2f::class
    ```
    This class represents a 2D vector. It contains two properties: `x` and `y` (can be also accessed using `[0]` and `[1]` offset). It also contains some useful methods for vector operations. It can be used as an array. Both integer and float values are supported.

    ### Null constructor
    This constructor creates a vector with both properties set to 0.
    ```php
    $vector = new Vector2f(); // (0, 0)
    ```

    ### Single value constructor
    This constructor creates a vector with both properties set to the same value.
    ```php
    $vector = new Vector2f(9.23); // (9.23, 9.23)
    ```

    ### Two values constructor
    This constructor creates a vector with both properties set to the given values. The first value is assigned to the `x` property and the second value is assigned to the `y` property.
    ```php
    $vector = new Vector2f(-1, 2.3445667); // (-1, 2.3445667)
    ```

    ### Accessing properties
    Vector2f class can be used as an array or as an object. The `x` property can be accessed by using the `x` property or the `[0]` offset. The `y` property can be accessed by using the `y` property or the `[1]` offset.
    ```php
    $vector = new Vector2f(-1, 2.3445667); // (-1, 2.3445667)
    $vector->x; // -1
    $vector->y; // 2.3445667

    $vector[0]; // -1
    $vector[1]; // 2.3445667
    ```

    ### Setting properties
    Vector2f class can be used as an array or as an object. The `x` property can be set by using the `x` property or the `[0]` offset. The `y` property can be set by using the `y` property or the `[1]` offset.
    ```php
    $vector = new Vector2f(-1, 2.3445667); // (-1, 2.3445667)
    $vector->x = 9.23; // (9.23, 2.3445667)
    $vector->y = 0; // (9.23, 0)

    $vector[0] = 0; // (0, 0)
    $vector[1] = 9.23; // (0, 9.23)
    ```

    ### Vector2f methods

    - `toString(?int precision = 5): string` - Returns a string representation of the vector. The precision parameter is optional and it's default value is 5.
        ```php
        $v = new Vector2f(-1.789, 2.3445667); // (-1.789, 2.3445667)

        $vector->toString(); // (-1.789, 2.34457)
        $vector->toString(0); // (-2.0, 2.0)
        $vector->toString(1); // (-1.8, 2.3)
        $vector->toString(2); // (-1.79, 2.34)
        $vector->toString(-1); // throws an exception (\Throwable) if precision is less than 0
        ```

    - `length(): float` - Returns the length of the vector.
        ```php
        $v =  new Vector2f(3.564, -9.22); // (3.564, -9.22)

        $l = $vector->length(); // 9.9999999999999982 ...
        ```

    - `lengthSquared(): float` - Returns the squared length of the vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $lq = $vector->lengthSquared(); // 2.44
        ```

    - `toArray(): array` - Returns an array representation of the vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $a = $vector->toArray(); // [0 => -1, 1 => 1.2]
        ```

    - `toJSON(): string` - Returns a JSON string representation of the vector. The precision parameter is optional and it's default value is 5.
        ```php
        $v = new Vector2f(-1.789, 2.3445667); // (-1.789, 2.3445667)

        $j = $vector->toJSON(); // { "x" :-1.789, "y": 2.34457 }
        $j = $vector->toJSON(0); // { "x" :-2.0, "y": 2.0 }
        $j = $vector->toJSON(1); // { "x" :-1.8, "y": 2.3 }
        $j = $vector->toJSON(2); // { "x" :-1.79, "y": 2.34 }
        $j = $vector->toJSON(-1); // throws an exception (\Throwable) if precision is less than 0
        ```

    - `negate(): Vector2f` - Negates the given vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->negate(); // (1, -1.2)
        ```

    - `Vector2f::negated(Vector2f $vector): Vector2f` - Returns new vector that is negated.
        ```php
        $v = Vector2f::negated(new Vector2f(-1, 1.2)); // (1, -1.2)
        ```

    - `normalize(): void` - Normalizes the given vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->normalize(); // (-0.427, 0.904)
        ```

    - `Vector2f::normalized(Vector2f $vector): Vector2f` - Returns new vector that is normalized.
        ```php
        $v = Vector2f::normalized(new Vector2f(-1, 1.2)); // (-0.427, 0.904)
        ```

    - `absolute(): void` - Converts all the vector properties to their absolute values.
        ```php
        $v = new Vector2f(-1, -1.2); // (-1, -1.2)

        $v->absolute(); // (1, 1.2)
        ```

    - `Vector2f::absoluted(Vector2f $vector): Vector2f` - Returns new vector that has all the properties converted to their absolute values.
        ```php
        $v = Vector2f::absoluted(new Vector2f(-1, -1.2)); // (1, 1.2)
        ```

    - `dot(Vector2f $vector): float` - Returns the dot product of the given vectors.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $f = $v->dot(new Vector2f(9.23, 0)); // -9.23
        ```

    - `Vector2f::dotted(Vector2f $vector1, Vector2f $vector2): float` - Returns the dot product of the given vectors.
        ```php
        $f = Vector2f::dotted(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // -9.23
        ```

    - `angleBetween(Vector2f $vector): float` - Returns the angle between the given vectors. Returns the angle in radians.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $f = $v->angleBetween(new Vector2f(9.23, 0)); // 3.1415926535897931 ...
        ```

    - `Vector2f::angleBetweenVectors(Vector2f $vector1, Vector2f $vector2): float` - Returns the angle between the given vectors. Returns the angle in radians.
        ```php
        $f = Vector2f::angleBetweenVectors(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // 3.1415926535897931 ...
        ```

    - `angleBetweenDeg(Vector2f $vector): float` - Returns the angle between the given vectors. Returns the angle in degrees.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $f = $v->angleBetweenDeg(new Vector2f(9.23, 0)); // 180
        ```

    - `Vector2f::angleBetweenVectorsDeg(Vector2f $vector1, Vector2f $vector2): float` - Returns the angle between the given vectors. Returns the angle in degrees.
        ```php
        $f = Vector2f::angleBetweenVectorsDeg(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // 180
        ```

    - `equals(Vector2f $vector): bool` - Returns true if the given vector is equal to the current vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->equals(new Vector2f(9.23, 0)); // false
        $v->equals(new Vector2f(0.427, -0.904)); // true
        ```

    - `Vector2f::equalVectors(Vector2f $vector1, Vector2f $vector2): bool` - Returns true if the given vectors are equal.
        ```php
        $v = Vector2f::equalVectors(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // false
        $v = Vector2f::equalVectors(new Vector2f(0.427, -0.904), new Vector2f(0.427, -0.904)); // true
        ```

    - `distanceBetween(Vector2f $vector): float` - Returns the distance between the given vectors.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $f = $v->distanceBetween(new Vector2f(9.23, 0)); // 10.23
        ```

    - `Vector2f::distanceBetweenVectors(Vector2f $vector1, Vector2f $vector2): float` - Returns the distance between the given vectors.
        ```php
        $f = Vector2f::distanceBetweenVectors(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // 10.23
        ```

    - `distanceBetweenSquared(Vector2f $vector): float` - Returns the squared distance between the given vectors.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $f = $v->distanceBetweenSquared(new Vector2f(9.23, 0)); // 104.6529
        ```

    - `Vector2f::distanceBetweenVectorsSquared(Vector2f $vector1, Vector2f $vector2): float` - Returns the squared distance between the given vectors.
        ```php
        $f = Vector2f::distanceBetweenVectorsSquared(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // 104.6529
        ```

    - `scale(float $scale): void` - Scales the vector by the given scale.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->scale(2); // (-2, 2.4)
        ```

    - `Vector2f::scaled(Vector2f $vector, float $scale): Vector2f` - Returns new vector that is scaled by the given scale.
        ```php
        $v = Vector2f::scaled(new Vector2f(-1, 1.2), 2); // (-2, 2.4)
        ```

    - `lerp(Vector2f $vector, float $t): void` - Linearly interpolates between the current vector and the given vector by the given t value. Factor t is clamped to the range [0, 1].
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->lerp(new Vector2f(9.23, 0), 0.5); // (4.115, 0.6)
        ```

    - `Vector2f::lerped(Vector2f $vector1, Vector2f $vector2, float $t): Vector2f` - Returns new vector that is linearly interpolated between the given vectors by the given t value. Factor t is clamped to the range [0, 1].
        ```php
        $v = Vector2f::lerped(new Vector2f(-1, 1.2), new Vector2f(9.23, 0), 0.5); // (4.115, 0.6)
        ```

    - `slerp(Vector2f $vector, float $t): void` - Spherically interpolates between the current vector and the given vector by the given t value. Factor t is clamped to the range [0, 1].
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->slerp(new Vector2f(9.23, 0), 0.5); // (0.427, -0.904)
        ```

    - `Vector2f::slerped(Vector2f $vector1, Vector2f $vector2, float $t): Vector2f` - Returns new vector that is spherically interpolated between the given vectors by the given t value. Factor t is clamped to the range [0, 1].
        ```php
        $v = Vector2f::slerped(new Vector2f(-1, 1.2), new Vector2f(9.23, 0), 0.5); // (0.427, -0.904)
        ```

    - `add(Vector2f $vector): void` - Adds the given vector to the current vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->add(new Vector2f(9.23, 0)); // (8.23, 1.2)
        ```

    - `Vector2f::added(Vector2f $vector1, Vector2f $vector2): Vector2f` - Returns new vector that is the sum of the given vectors.
        ```php
        $v = Vector2f::added(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // (8.23, 1.2)
        ```

    - `sub(Vector2f $vector): void` - Subtracts the given vector from the current vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->sub(new Vector2f(9.23, 0)); // (-10.23, 1.2)
        ```

    - `Vector2f::subtracted(Vector2f $vector1, Vector2f $vector2): Vector2f` - Returns new vector that is the difference of the given vectors.
        ```php
        $v = Vector2f::subtracted(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // (-10.23, 1.2)
        ```

    - `mul(Vector2f $vector): void` - Multiplies the given vector with the current vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->mul(new Vector2f(9.23, 0)); // (-9.23, 0)
        ```

    - `Vector2f::multiplied(Vector2f $vector1, Vector2f $vector2): Vector2f` - Returns new vector that is the product of the given vectors.
        ```php
        $v = Vector2f::multiplied(new Vector2f(-1, 1.2), new Vector2f(9.23, 0)); // (-9.23, 0)
        ```

    - `div(Vector2f $vector): void` - Divides the current vector by the given vector.
        ```php
        $v = new Vector2f(-1, 1.2); // (-1, 1.2)

        $v->div(new Vector2f(9.23, 0)); // (-0.1085, INF)
        ```

    - `Vector2f::divided(Vector2f $vector1, Vector2f $vector2): Vector2f` - Returns new vector that is the quotient of the given vectors.
        ```php
        $v = Vector2f::divided(new Vector2f(-1, 1.2), new Vector2f(9.23, 1)); // (-0.1085, 1.2)
        ```
