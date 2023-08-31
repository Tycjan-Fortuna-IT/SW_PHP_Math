--TEST--
Check if constructor is working as it should.
For the following cases:
    - No arguments
    - One argument (int)
    - One argument (float)
    - Three arguments (int, int, int)
    - Three arguments (float, float, float)
    - Three arguments (int, float, float)
    - Three arguments (float, int, float)
    - Three arguments (float, float, int)


--EXTENSIONS--
fastmath


--FILE--
<?php
// Case 1 - No arguments
$v1 = new \SW\Math\Vector3f();
var_dump($v1);

// Case 2 - One argument (int)
$v2 = new \SW\Math\Vector3f(1);
var_dump($v2);

// Case 3 - One argument (float)
$v3 = new \SW\Math\Vector3f(12.35677);
var_dump($v3);

// Case 4 - Three arguments (int, int, int)
$v4 = new \SW\Math\Vector3f(1, 1, 1);
var_dump($v4);

// Case 5 - Three arguments (float, float, float)
$v5 = new \SW\Math\Vector3f(12.35677, 12.35677, 12.35677);
var_dump($v5);

// Case 6 - Three arguments (int, float, float)
$v6 = new \SW\Math\Vector3f(1, 12.35677, 12.35677);
var_dump($v6);

// Case 7 - Three arguments (float, int, float)
$v7 = new \SW\Math\Vector3f(12.35677, 1, 12.35677);
var_dump($v7);

// Case 8 - Three arguments (float, float, int)
$v8 = new \SW\Math\Vector3f(12.35677, 12.35677, 1);
var_dump($v8);
?>


--EXPECTF--
object(SW\Math\Vector3f)#%d (3) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
  ["z"]=>
  float(0)
}
object(SW\Math\Vector3f)#%d (3) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
  ["z"]=>
  float(1)
}
object(SW\Math\Vector3f)#%d (3) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(12.35677)
  ["z"]=>
  float(12.35677)
}
object(SW\Math\Vector3f)#%d (3) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
  ["z"]=>
  float(1)
}
object(SW\Math\Vector3f)#%d (3) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(12.35677)
  ["z"]=>
  float(12.35677)
}
object(SW\Math\Vector3f)#%d (3) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(12.35677)
  ["z"]=>
  float(12.35677)
}
object(SW\Math\Vector3f)#%d (3) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(1)
  ["z"]=>
  float(12.35677)
}
object(SW\Math\Vector3f)#%d (3) {
  ["x"]=>
  float(12.35677)
  ["y"]=>
  float(12.35677)
  ["z"]=>
  float(1)
}
