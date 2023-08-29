--TEST--
Check if slerp(Vector2f, float) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);
$v2 = new \SW\Math\Vector2f(-2.5, 2.5);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);
$v4 = new \SW\Math\Vector2f(-3.564, -9.22);

$v1->slerp(new \SW\Math\Vector2f(0.0, 0.0), 0.5);
$v2->slerp(new \SW\Math\Vector2f(0.0, 0.0), 0.5);
$v3->slerp(new \SW\Math\Vector2f(0.0, 0.0), 0.5);
$v4->slerp(new \SW\Math\Vector2f(0.0, 0.0), 0.5);

var_dump($v1);
var_dump($v2);
var_dump($v3);
var_dump($v4);
?>


--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(1.237%d)
  ["y"]=>
  float(0.912%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-1.767%d)
  ["y"]=>
  float(1.767%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(2.520%d)
  ["y"]=>
  float(-6.519%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-2.520%d)
  ["y"]=>
  float(-6.519%d)
}
