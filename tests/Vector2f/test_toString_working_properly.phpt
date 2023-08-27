--TEST--
Check if toString() method is working as it should.
For the following cases:
    - Pure method call
    - With 0 precision param
    - With 1 precision param
    - With 2 precision param
    - With -1 precision param

--EXTENSIONS--
fastmath


--FILE--
<?php
$v = new \SW\Math\Vector2f(-1.789, 2.3445667);

// Case 1 Pure method call
var_dump($v->toString());

// Case 2 With 0 precision param
var_dump($v->toString(0));

// Case 3 With 1 precision param
var_dump($v->toString(1));

// Case 4 With 2 precision param
var_dump($v->toString(2));

// Case 5 With -1 precision param
try {
    var_dump($v->toString(-1));
} catch (\Throwable $e) {
    echo "Exception caught: " . $e->getMessage() . PHP_EOL;
}
?>


--EXPECT--
string(17) "(-1.789, 2.34457)"
string(11) "(-2.0, 2.0)"
string(11) "(-1.8, 2.3)"
string(13) "(-1.79, 2.34)"
Exception caught: Precision must be a positive integer!
