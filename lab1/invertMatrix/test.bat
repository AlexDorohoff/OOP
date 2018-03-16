
rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

%PROGRAM% matrix.txt
if ERRORLEVEL 1 goto err

%PROGRAM% empty.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% not-exist.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% zeroDet.txt
if ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1