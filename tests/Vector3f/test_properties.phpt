--TEST--
Check if property assigment is working as it should.
Check if property reading is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
// Case 1 - x, y and z as int
$v1 = new \SW\Math\Vector3f();
$v1->x = 1;
$v1->y = 1;
$v1->z = 1;
var_dump($v1);

// Case 2 - x, y and z as float
$v2 = new \SW\Math\Vector3f();
$v2->x = 12.35677;
$v2->y = 12.35677;
$v2->z = 12.35677;
var_dump($v2);

// Case 3 - reading x, y and z as int
$v3 = new \SW\Math\Vector3f(1, 1, 1);
var_dump($v3->x);
var_dump($v3->y);
var_dump($v3->z);

// Case 4 - reading x, y and z as float
$v4 = new \SW\Math\Vector3f(12.35677, 12.35677, 12.35677);
var_dump($v4->x);
var_dump($v4->y);
var_dump($v4->z);

// Case 5 - x as int and y as int but array offset
$v5 = new \SW\Math\Vector3f();
$v5[0] = 1;
$v5[1] = 1;
$v5[2] = 1;

var_dump($v5);

// Case 6 - x as float and y as float but array offset
$v6 = new \SW\Math\Vector3f();
$v6[0] = 12.35677;
$v6[1] = 12.35677;
$v6[2] = 12.35677;

var_dump($v6);

// Case 7 - reading x, y and z as int but array offset
$v7 = new \SW\Math\Vector3f(1, 1, 1);
var_dump($v7[0]);
var_dump($v7[1]);
var_dump($v7[2]);

// Case 8 - reading x, y and z as float but array offset
$v8 = new \SW\Math\Vector3f(12.35677, 12.35677, 12.35677);
var_dump($v8[0]);
var_dump($v8[1]);
var_dump($v8[2]);
?>


--EXPECTF--
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
float(1)
float(1)
float(1)
float(12.35677)
float(12.35677)
float(12.35677)
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
float(1)
float(1)
float(1)
float(12.35677)
float(12.35677)
float(12.35677)
