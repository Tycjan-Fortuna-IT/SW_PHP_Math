--TEST--
test1() Basic test
--EXTENSIONS--
fastmath
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension fastmath is loaded and working!
NULL
