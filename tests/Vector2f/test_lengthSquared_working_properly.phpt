--TEST--
Check if Vector2f class lengthSquared() method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1, 1);
$v2 = new \SW\Math\Vector2f(-1, 1.2);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);

var_dump($v1->lengthSquared());
var_dump($v2->lengthSquared());
var_dump($v3->lengthSquared());
?>


--EXPECT--
float(2)
float(2.44)
float(97.710496)
