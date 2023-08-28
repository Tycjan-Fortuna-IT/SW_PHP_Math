--TEST--
Check if Vector2f::equalVectors(Vector2f, Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);
$v2 = new \SW\Math\Vector2f(-2.5, 2.5);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);
$v4 = new \SW\Math\Vector2f(-3.564, -9.22);
$v5 = new \SW\Math\Vector2f(1.75, 1.2899);

var_dump(\SW\Math\Vector2f::equalVectors($v1, $v2));
var_dump(\SW\Math\Vector2f::equalVectors($v1, $v3));
var_dump(\SW\Math\Vector2f::equalVectors($v1, $v4));
var_dump(\SW\Math\Vector2f::equalVectors($v1, $v5));
?>

--EXPECT--
bool(false)
bool(false)
bool(false)
bool(true)
