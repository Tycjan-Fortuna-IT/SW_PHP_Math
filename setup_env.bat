@echo off

SET "PHP_SDK_DIR=C:\Users\tycja\Desktop\Libs\php-sdk"
SET "PHP_SDK_BAT_FILE=phpsdk-vs16-x64.bat"
SET "ORIGINAL_DIR=%CD%"

CD /d "%PHP_SDK_DIR%"

CALL "%PHP_SDK_BAT_FILE%"

CD /d "%ORIGINAL_DIR%"

@REM C:\Users\tycja\Desktop\Libs\php-sdk\php-8.2.9\vs16\x64\php-src\ext\fastmath
