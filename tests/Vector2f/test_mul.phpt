--TEST--
Check if mul(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);
$v2 = new \SW\Math\Vector2f(-2.5, 2.5);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);
$v4 = new \SW\Math\Vector2f(-3.564, -9.22);

$v1->mul($v2);
$v1->mul($v3);
$v1->mul($v4);

var_dump($v1);
var_dump($v2);
var_dump($v3);
?>

--EXPECTF--
object(SW\Math\Vector2f)#1 (2) {
  ["x"]=>
  float(55.571%d)
  ["y"]=>
  float(274.130%d)
}
object(SW\Math\Vector2f)#2 (2) {
  ["x"]=>
  float(-2.5)
  ["y"]=>
  float(2.5)
}
object(SW\Math\Vector2f)#3 (2) {
  ["x"]=>
  float(3.564)
  ["y"]=>
  float(-9.22)
}
