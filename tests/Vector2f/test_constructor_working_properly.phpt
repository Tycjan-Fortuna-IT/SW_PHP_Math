--TEST--
Check if Vector2f class constructor is working as it should.
For the following cases:
    - No arguments
    - One argument (int)
    - One argument (float)
    - Two arguments (int, int)
    - Two arguments (float, float)
    - Two arguments (int, float)


--EXTENSIONS--
fastmath


--FILE--
<?php
// Case 1 - No arguments
$v1 = new \SW\Math\Vector2f();
var_dump($v1);

// Case 2 - One argument (int)
$v2 = new \SW\Math\Vector2f(1);
var_dump($v2);

// Case 3 - One argument (float)
$v3 = new \SW\Math\Vector2f(12.35677);
var_dump($v3);

// Case 4 - Two arguments (int, int)
$v4 = new \SW\Math\Vector2f(1, 1);
var_dump($v4);

// Case 5 - Two arguments (float, float)
$v5 = new \SW\Math\Vector2f(12.35677, 12.35677);
var_dump($v5);

// Case 6 - Two arguments (int, float)
$v6 = new \SW\Math\Vector2f(1, 12.35677);
var_dump($v6);
?>


--EXPECT--
object(SW\Math\Vector2f)#1 (2) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
}
object(SW\Math\Vector2f)#2 (2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}
object(SW\Math\Vector2f)#3 (2) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(12.35677)
}
object(SW\Math\Vector2f)#4 (2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}
object(SW\Math\Vector2f)#5 (2) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(12.35677)
}
object(SW\Math\Vector2f)#6 (2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(12.35677)
}
