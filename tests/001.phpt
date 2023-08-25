--TEST--
Check if fastmath is loaded
--EXTENSIONS--
fastmath
--FILE--
<?php
echo 'The extension "fastmath" is available';
?>
--EXPECT--
The extension "fastmath" is available
