--TEST--
Check if Vector2f::dotted(Vector2f, Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);
$v2 = new \SW\Math\Vector2f(-2.5, 2.5);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);
$v4 = new \SW\Math\Vector2f(-3.564, -9.22);

var_dump(\SW\Math\Vector2f::dotted(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump(\SW\Math\Vector2f::dotted(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(3.564, -9.22)));
var_dump(\SW\Math\Vector2f::dotted(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-3.564, -9.22)));
?>

--EXPECTF--
float(-1.150%d)
float(-5.655%d1)
float(-18.129%d)
