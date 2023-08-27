--TEST--
Check if Vector2f class toJSON() method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1, 1);
$v2 = new \SW\Math\Vector2f(-1, 1.2);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);

var_dump($v1->toJSON());
var_dump($v2->toJSON());
var_dump($v3->toJSON());

var_dump(json_decode($v1->toJSON()));
var_dump(json_decode($v2->toJSON()));
var_dump(json_decode($v3->toJSON()));
?>


--EXPECT--
string(22) "{ "x": 1.0, "y": 1.0 }"
string(23) "{ "x": -1.0, "y": 1.2 }"
string(26) "{ "x": 3.564, "y": -9.22 }"
object(stdClass)#4 (2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}
object(stdClass)#4 (2) {
  ["x"]=>
  float(-1)
  ["y"]=>
  float(1.2)
}
object(stdClass)#4 (2) {
  ["x"]=>
  float(3.564)
  ["y"]=>
  float(-9.22)
}
