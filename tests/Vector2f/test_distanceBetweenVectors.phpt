--TEST--
Check if Vector2f::distanceBetweenVectors(Vector2f, Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
var_dump(\SW\Math\Vector2f::distanceBetweenVectors(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump(\SW\Math\Vector2f::distanceBetweenVectors(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(3.564, -9.22)));
var_dump(\SW\Math\Vector2f::distanceBetweenVectors(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-3.564, -9.22)));
?>

--EXPECTF--
float(4.418%d)
float(10.665%d)
float(11.776%d)
