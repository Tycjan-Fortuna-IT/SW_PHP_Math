--TEST--
Check if Vector2f class property assigment is working as it should.
For the following cases:
    - x and y as int
    - x and y as float
    - x as int and y as float
    - x as float and y as int
    - [0] and [1] as int
    - [0] and [1] as float
    - [0] as int and [1] as float
    - [0] as float and [1] as int

--EXTENSIONS--
fastmath


--FILE--
<?php
// Case 1 - x and y as int
$v1 = new \SW\Math\Vector2f();
$v1->x = 1;
$v1->y = 1;
var_dump($v1);

// Case 2 - x and y as float
$v2 = new \SW\Math\Vector2f();
$v2->x = 12.35677;
$v2->y = 12.35677;
var_dump($v2);

// Case 3 - x as int and y as float
$v3 = new \SW\Math\Vector2f();
$v3->x = 1;
$v3->y = 12.35677;
var_dump($v3);

// Case 4 - x as float and y as int
$v4 = new \SW\Math\Vector2f();
$v4->x = 12.35677;
$v4->y = 1;
var_dump($v4);

// Case 5 - [0] and [1] as int
$v5 = new \SW\Math\Vector2f();
$v5[0] = 1;
$v5[1] = 1;
var_dump($v5);

// Case 6 - [0] and [1] as float
$v6 = new \SW\Math\Vector2f();
$v6[0] = 12.35677;
$v6[1] = 12.35677;
var_dump($v6);

// Case 7 - [0] as int and [1] as float
$v7 = new \SW\Math\Vector2f();
$v7[0] = 1;
$v7[1] = 12.35677;
var_dump($v7);

// Case 8 - [0] as float and [1] as int
$v8 = new \SW\Math\Vector2f();
$v8[0] = 12.35677;
$v8[1] = 1;
var_dump($v8);
?>


--EXPECT--
object(SW\Math\Vector2f)#1 (2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}
object(SW\Math\Vector2f)#2 (2) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(12.35677)
}
object(SW\Math\Vector2f)#3 (2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(12.35677)
}
object(SW\Math\Vector2f)#4 (2) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(1)
}
object(SW\Math\Vector2f)#5 (2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}
object(SW\Math\Vector2f)#6 (2) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(12.35677)
}
object(SW\Math\Vector2f)#7 (2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(12.35677)
}
object(SW\Math\Vector2f)#8 (2) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(1)
}
