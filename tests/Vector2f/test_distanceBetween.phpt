--TEST--
Check if distanceBetween(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);

var_dump($v1->distanceBetween(new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump($v1->distanceBetween(new \SW\Math\Vector2f(3.564, -9.22)));
var_dump($v1->distanceBetween(new \SW\Math\Vector2f(-3.564, -9.22)));
?>

--EXPECTF--
float(4.418%d)
float(10.665%d)
float(11.776%d)
