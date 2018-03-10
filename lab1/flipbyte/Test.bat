rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

%PROGRAM% 6
if ERRORLEVEL 1 goto err

rem символ на вход
%PROGRAM% e
if NOT ERRORLEVEL 1 goto err

%PROGRAM% 
if NOT ERRORLEVEL 1 goto err

%PROGRAM% 6 ""
if NOT ERRORLEVEL 1 goto err

%PROGRAM% 6.123
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1