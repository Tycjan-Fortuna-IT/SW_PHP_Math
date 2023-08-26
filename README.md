# SW_PHP_MATH

## Description
This is a simple and fast math library for PHP made in C with the usage of C ZEND API. Build as an extension. It contains some useful functions and classes for math operations.

# Documentation

- ## Classes

    - ## `Vector2f`
    ```php
    \SW\Math\Vector2f::class
    ```
    This class represents a 2D vector. It contains two properties: `x` and `y`. It also contains some useful methods for vector operations. It can be used as an array. Both integer and float values are supported.

    ### Null constructor
    This constructor creates a vector with both properties set to 0.
    ```php
    $vector = new \SW\Math\Vector2f(); // (x: 0, y: 0)
    ```

    ### Single value constructor
    This constructor creates a vector with both properties set to the same value.
    ```php
    $vector = new \SW\Math\Vector2f(9.23); // (x: 9.23, y: 9.23)
    ```

    ### Two values constructor
    This constructor creates a vector with both properties set to the given values. The first value is assigned to the `x` property and the second value is assigned to the `y` property.
    ```php
    $vector = new \SW\Math\Vector2f(-1, 2.3445667); // (x: -1, y: 2.3445667)
    ```

    ### Accessing properties
    Vector2f class can be used as an array or as an object. The `x` property can be accessed by using the `x` property or the `[0]` offset. The `y` property can be accessed by using the `y` property or the `[1]` offset.
    ```php
    $vector = new \SW\Math\Vector2f(-1, 2.3445667); // (x: -1, y: 2.3445667)
    $vector->x; // -1
    $vector->y; // 2.3445667

    $vector[0]; // -1
    $vector[1]; // 2.3445667
    ```

    ### Setting properties
    Vector2f class can be used as an array or as an object. The `x` property can be set by using the `x` property or the `[0]` offset. The `y` property can be set by using the `y` property or the `[1]` offset.
    ```php
    $vector = new \SW\Math\Vector2f(-1, 2.3445667); // (x: -1, y: 2.3445667)
    $vector->x = 9.23; // (x: 9.23, y: 2.3445667)
    $vector->y = 0; // (x: 9.23, y: 0)

    $vector[0] = 0; // (x: 0, y: 0)
    $vector[1] = 9.23; // (x: 0, y: 9.23)
    ```

    ### Vector methods

    - `toString(?int precision = 5): string` - Returns a string representation of the vector. The precision parameter is optional and it's default value is 5.
        ```php
        $v = new \SW\Math\Vector2f(-1.789, 2.3445667); // (x: -1.789, y: 2.3445667)

        $vector->toString(); // (-1.789, 2.34457)
        $vector->toString(0); // (-2.0, 2.0)
        $vector->toString(1); // (-1.8, 2.3)
        $vector->toString(2); // (-1.79, 2.34)
        $vector->toString(-1); // throws an exception (\Throwable) if precision is less than 0
        ```
    - `length(): float` - Returns the length of the vector.
        ```php
        $v =  new \SW\Math\Vector2f(3.564, -9.22); // (x: 3.564, y: -9.22)

        $vector->length(); // 9.9999999999999982 ...
        ```

    - `lengthSquared(): float` - Returns the squared length of the vector.
        ```php
        $v = new \SW\Math\Vector2f(-1, 2.3445667); // (x: -1, y: 2.3445667)

        $vector->lengthSquared(); // 5.498
        ```

    <!-- ### Vector operations
    ```php
    $vector = new \SW\Math\Vector2f(-1, 2.3445667); // (x: -1, y: 2.3445667)
    $vector->add(new \SW\Math\Vector2f(9.23, 0)); // (x: 8.23, y: 2.3445667)
    $vector->sub(new \SW\Math\Vector2f(9.23, 0)); // (x: -10.23, y: 2.3445667)
    $vector->mul(new \SW\Math\Vector2f(9.23, 0)); // (x: -9.23, y: 0)
    $vector->div(new \SW\Math\Vector2f(9.23, 0)); // (x: -0.1085, y: INF)
    $vector->dot(new \SW\Math\Vector2f(9.23, 0)); // -9.23
    $vector->cross(new \SW\Math\Vector2f(9.23, 0)); // 0
    $vector->lengthSquared(); // 5.498
    $vector->normalize(); // (x: -0.427, y: 0.904)
    $vector->negate(); // (x: 0.427, y: -0.904)
    $vector->equals(new \SW\Math\Vector2f(9.23, 0)); // false
    $vector->equals(new \SW\Math\Vector2f(0.427, -0.904)); // true
    $vector->toArray(); // [0.427, -0.904]
    $vector->toString(); // (x: 0.427, y: -0.904)
    $vector->toJSON(); // {"x":0.427,"y":-0.904}
    $vector->toObject(); // (object) ["x" => 0.427, "y" => -0.904]
    $vector->toStdClass(); // (object) ["x" => 0.427, "y" => -0.904]
    ``` -->

    ### Illegal moves
    Performing illegal moves will throw a runtime exception (\Throwable).
    ```php
    $vector[-1]; // throws an exception
    $vector[2]; // throws an exception
    $vector->z; // throws an exception

    $vector[0] = 'a'; // throws an exception
    $vector->x = 'c'; // throws an exception
    ```
