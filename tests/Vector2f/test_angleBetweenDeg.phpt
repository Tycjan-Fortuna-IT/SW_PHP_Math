--TEST--
Check if angleBetweenDeg(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);

var_dump($v1->angleBetweenDeg(new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump($v1->angleBetweenDeg(new \SW\Math\Vector2f(3.564, -9.22)));
var_dump($v1->angleBetweenDeg(new \SW\Math\Vector2f(-3.564, -9.22)));
?>

--EXPECTF--
float(98.606%d)
float(105.259%d)
float(147.527%d)
