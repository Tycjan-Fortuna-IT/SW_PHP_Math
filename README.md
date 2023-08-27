# SW_PHP_MATH

## Description
This is a simple and fast math library for PHP made in C with the usage of C ZEND API. Build as an extension. It contains some useful functions and classes for math operations.

## PHP Stubs file
The PHP stubs file is located in the `fastmath_stubs.php` file. It contains all the functions and classes that are available in this library. It can be used for code completion in IDEs. Link: [STUBS](fastmath_stubs.php)

# Documentation

- # Classes

    - ## `Vector2f`
    ```php
    \SW\Math\Vector2f::class
    ```
    This class represents a 2D vector. It contains two properties: `x` and `y` (can be also accessed using `[0]` and `[1]` offset). It also contains some useful methods for vector operations. It can be used as an array. Both integer and float values are supported.

    ### Null constructor
    This constructor creates a vector with both properties set to 0.
    ```php
    $vector = new \SW\Math\Vector2f(); // (0, 0)
    ```

    ### Single value constructor
    This constructor creates a vector with both properties set to the same value.
    ```php
    $vector = new \SW\Math\Vector2f(9.23); // (9.23, 9.23)
    ```

    ### Two values constructor
    This constructor creates a vector with both properties set to the given values. The first value is assigned to the `x` property and the second value is assigned to the `y` property.
    ```php
    $vector = new \SW\Math\Vector2f(-1, 2.3445667); // (-1, 2.3445667)
    ```

    ### Accessing properties
    Vector2f class can be used as an array or as an object. The `x` property can be accessed by using the `x` property or the `[0]` offset. The `y` property can be accessed by using the `y` property or the `[1]` offset.
    ```php
    $vector = new \SW\Math\Vector2f(-1, 2.3445667); // (-1, 2.3445667)
    $vector->x; // -1
    $vector->y; // 2.3445667

    $vector[0]; // -1
    $vector[1]; // 2.3445667
    ```

    ### Setting properties
    Vector2f class can be used as an array or as an object. The `x` property can be set by using the `x` property or the `[0]` offset. The `y` property can be set by using the `y` property or the `[1]` offset.
    ```php
    $vector = new \SW\Math\Vector2f(-1, 2.3445667); // (-1, 2.3445667)
    $vector->x = 9.23; // (9.23, 2.3445667)
    $vector->y = 0; // (9.23, 0)

    $vector[0] = 0; // (0, 0)
    $vector[1] = 9.23; // (0, 9.23)
    ```

    ### Vector methods

    - `toString(?int precision = 5): string` - Returns a string representation of the vector. The precision parameter is optional and it's default value is 5.
        ```php
        $v = new \SW\Math\Vector2f(-1.789, 2.3445667); // (-1.789, 2.3445667)

        $vector->toString(); // (-1.789, 2.34457)
        $vector->toString(0); // (-2.0, 2.0)
        $vector->toString(1); // (-1.8, 2.3)
        $vector->toString(2); // (-1.79, 2.34)
        $vector->toString(-1); // throws an exception (\Throwable) if precision is less than 0
        ```

    - `length(): float` - Returns the length of the vector.
        ```php
        $v =  new \SW\Math\Vector2f(3.564, -9.22); // (3.564, -9.22)

        $l = $vector->length(); // 9.9999999999999982 ...
        ```

    - `lengthSquared(): float` - Returns the squared length of the vector.
        ```php
        $v = new \SW\Math\Vector2f(-1, 1.2); // (-1, 1.2)

        $lq = $vector->lengthSquared(); // 2.44
        ```

    - `toArray(): array` - Returns an array representation of the vector.
        ```php
        $v = new \SW\Math\Vector2f(-1, 1.2); // (-1, 1.2)

        $a = $vector->toArray(); // [0 => -1, 1 => 1.2]
        ```

    - `toJSON(): string` - Returns a JSON string representation of the vector. The precision parameter is optional and it's default value is 5.
        ```php
        $v = new \SW\Math\Vector2f(-1.789, 2.3445667); // (-1.789, 2.3445667)

        $j = $vector->toJSON(); // { "x" :-1.789, "y": 2.34457 }
        $j = $vector->toJSON(0); // { "x" :-2.0, "y": 2.0 }
        $j = $vector->toJSON(1); // { "x" :-1.8, "y": 2.3 }
        $j = $vector->toJSON(2); // { "x" :-1.79, "y": 2.34 }
        $j = $vector->toJSON(-1); // throws an exception (\Throwable) if precision is less than 0
        ```

    <!-- ### Vector operations
    ```php
    $vector = new \SW\Math\Vector2f(-1, 2.3445667); // (-1, 2.3445667)
    $vector->add(new \SW\Math\Vector2f(9.23, 0)); // (8.23, 2.3445667)
    $vector->sub(new \SW\Math\Vector2f(9.23, 0)); // (-10.23, 2.3445667)
    $vector->mul(new \SW\Math\Vector2f(9.23, 0)); // (-9.23, 0)
    $vector->div(new \SW\Math\Vector2f(9.23, 0)); // (-0.1085, INF)
    $vector->dot(new \SW\Math\Vector2f(9.23, 0)); // -9.23
    $vector->cross(new \SW\Math\Vector2f(9.23, 0)); // 0
    $vector->normalize(); // (-0.427, 0.904)
    $vector->negate(); // (0.427, -0.904)
    $vector->equals(new \SW\Math\Vector2f(9.23, 0)); // false
    $vector->equals(new \SW\Math\Vector2f(0.427, -0.904)); // true
    $vector->toJSON(); // {"x":0.427,"y":-0.904}
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
