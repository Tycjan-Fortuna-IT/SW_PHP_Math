--TEST--
Check if div(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);
$v2 = new \SW\Math\Vector2f(-2.5, 2.5);

$v1->div($v2);

var_dump($v1);

?>

--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-0.7)
  ["y"]=>
  float(0.515%d)
}
