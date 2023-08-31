- # `Vector3f`
    ```php
    Vector3f::class
    ```
    This class represents a 3D vector. It contains three properties: `x`, `y` and `z` (can be also accessed using `[0]`, `[1]` and `[2]` offset). It also contains some useful methods for vector operations. It can be used as an array. Both integer and float values are supported.

    ### Null constructor
    This constructor creates a vector with all properties set to 0.
    ```php
    $vector = new Vector3f(); // (0, 0, 0)
    ```

    ### Single value constructor
    This constructor creates a vector with all properties set to the same value.
    ```php
    $vector = new Vector3f(9.23); // (9.23, 9.23, 9.23)
    ```

    ### Three values constructor
    This constructor creates a vector with all properties set to the given values. The first value is assigned to the `x` property, the second value is assigned to the `y` property and the third value is assigned to the `z` property.
    ```php
    $vector = new Vector3f(-1, 2.3445667, 0); // (-1, 2.3445667, 0)
    ```

    ### Accessing properties
    Vector3f class can be used as an array or as an object. The `x` property can be accessed by using the `x` property or the `[0]` offset. The `y` property can be accessed by using the `y` property or the `[1]` offset. The `z` property can be accessed by using the `z` property or the `[2]` offset.
    ```php
    $vector = new Vector3f(-1, 2.3445667, 0); // (-1, 2.3445667, 0)
    $vector->x; // -1
    $vector->y; // 2.3445667
    $vector->z; // 0

    $vector[0]; // -1
    $vector[1]; // 2.3445667
    $vector[2]; // 0
    ```

    ### Setting properties
    Vector3f class can be used as an array or as an object. The `x` property can be set by using the `x` property or the `[0]` offset. The `y` property can be set by using the `y` property or the `[1]` offset. The `z` property can be set by using the `z` property or the `[2]` offset.
    ```php
    $vector = new Vector3f(-1, 2.3445667, 0); // (-1, 2.3445667, 0)
    $vector->x = 9.23; // (9.23, 2.3445667, 0)
    $vector->y = 0; // (9.23, 0, 0)
    $vector->z = 1.2; // (9.23, 0, 1.2)

    $vector[0] = 0; // (0, 0, 1.2)
    $vector[1] = 9.23; // (0, 9.23, 1.2)
    $vector[2] = -1; // (0, 9.23, -1)
    ```

    ### Vector3f methods

    - `toString(?int precision = 5): string` - Returns a string representation of the vector. The precision parameter is optional and it's default value is 5.
        ```php
        $v = new Vector3f(-1.789, 2.3445667, 0); // (-1.789, 2.3445667, 0)

        $vector->toString(); // (-1.789, 2.34457, 0)
        $vector->toString(0); // (-2.0, 2.0, 0)
        $vector->toString(1); // (-1.8, 2.3, 0)
        $vector->toString(2); // (-1.79, 2.34, 0)
        $vector->toString(-1); // throws an exception (\Throwable) if precision is less than 0
        ```

    - `length(): float` - Returns the length of the vector.
        ```php
        $v =  new Vector3f(3.564, -9.22, 0); // (3.564, -9.22, 0)

        $l = $vector->length(); // 9.9999999999999982 ...
        ```

    - `lengthSquared(): float` - Returns the squared length of the vector.
        ```php
        $v = new Vector3f(-1, 1.2, 0); // (-1, 1.2, 0)

        $lq = $vector->lengthSquared(); // 2.44
        ```
