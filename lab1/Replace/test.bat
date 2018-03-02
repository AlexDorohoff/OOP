rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem замена не существующей подстроки
%PROGRAM% "replace-lion.txt" "%TEMP%\replace-lion.txt" lion cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\replace-lion.txt" "replace-lion.txt"
if ERRORLEVEL 1 goto err

rem замена существующей подстроки
rem %PROGRAM% fox.txt %TEMP%\fox.txt dog cat
rem if ERRORLEVEL 1 goto err
rem fc.exe  %TEMP%\fox.txt fox.txt
rem if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
rem %PROGRAM% fox-dog-with-cat.txt %TEMP%\fox-dog-with-cat.txt fox cat
rem if ERRORLEVEL 1 goto err
rem fc.exe  %TEMP%\fox-dog-with-cat.txt fox-dog-with-cat.txt
rem if ERRORLEVEL 1 goto err

rem копирование пустого файла
%PROGRAM% empty.txt %TEMP%\empty.txt fox cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty.txt empty.txt
if ERRORLEVEL 1 goto err

%PROGRAM% fox-witout-param.txt %TEMP%\fox-witout-param.txt fox cat
if ERRORLEVEL 1 goto err
fc.exe  %TEMP%\fox-witout-param.txt fox-witout-param.txt
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1