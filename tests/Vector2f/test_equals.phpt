--TEST--
Check if equals(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);
$v2 = new \SW\Math\Vector2f(-2.5, 2.5);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);
$v4 = new \SW\Math\Vector2f(-3.564, -9.22);
$v5 = new \SW\Math\Vector2f(1.75, 1.2899);

var_dump($v1->equals($v2));
var_dump($v1->equals($v3));
var_dump($v1->equals($v4));
var_dump($v1->equals($v5));
?>

--EXPECT--
bool(false)
bool(false)
bool(false)
bool(true)
