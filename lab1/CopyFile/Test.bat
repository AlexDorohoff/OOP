rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem копирование однострочного файла
%PROGRAM% one-line.txt %TEMP%/one-line-copied.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\one-line-copied.txt one-line.txt
if ERRORLEVEL 1 goto err

rem копирование многострочного файла
%PROGRAM% many-lines.txt %TEMP%/many-lines-copied.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\many-lines-copied.txt many-lines.txt
if ERRORLEVEL 1 goto err

rem копирование пустого файла
%PROGRAM% empty.txt %TEMP%/empty-copied.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty-copied.txt empty.txt
if ERRORLEVEL 1 goto err

rem копирование не существующиего файла
%PROGRAM% non-existent %TEMP%/non-existent-copied.txt.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\non-existent-copied.txt non-existent-copied.txt
if ERRORLEVEL 1 goto err

rem 
echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1