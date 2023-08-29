--TEST--
Check if Vector2f::distanceBetweenVectorsSquared(Vector2f, Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
var_dump(\SW\Math\Vector2f::distanceBetweenVectorsSquared(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump(\SW\Math\Vector2f::distanceBetweenVectorsSquared(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(3.564, -9.22)));
var_dump(\SW\Math\Vector2f::distanceBetweenVectorsSquared(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-3.564, -9.22)));
?>

--EXPECTF--
float(19.526%d)
float(113.748%d)
float(138.696%d)

