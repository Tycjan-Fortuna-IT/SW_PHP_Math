--TEST--
Check if angleBetween(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);

var_dump($v1->angleBetween(new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump($v1->angleBetween(new \SW\Math\Vector2f(3.564, -9.22)));
var_dump($v1->angleBetween(new \SW\Math\Vector2f(-3.564, -9.22)));
?>

--EXPECTF--
float(1.7210%d)
float(1.8371%d)
float(2.5748%d)
