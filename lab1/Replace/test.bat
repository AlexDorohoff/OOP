rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
rem if NOT ERRORLEVEL 1 goto err

rem ������ �� ������������ ���������
%PROGRAM% replace-lion.txt %TEMP%\replace-lion.txt lion cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\replace-lion.txt replace-lion.txt
if ERRORLEVEL 1 goto err

rem ������ ������������ ���������
%PROGRAM% fox.txt %TEMP%\fox.txt dog cat
if ERRORLEVEL 1 goto err
fc.exe  %TEMP%\fox.txt fox.txt
if NOT ERRORLEVEL 1 goto err

rem ������ ���� ���������
%PROGRAM% fox-with-fox.txt %TEMP%\fox-with-fox.txt fox cat
if ERRORLEVEL 1 goto err
fc.exe  %TEMP%\fox-with-fox.txt fox-with-fox.txt
if NOT ERRORLEVEL 1 goto err

rem ����������� � ������� ������� �����
%PROGRAM% empty.txt %TEMP%\empty.txt fox cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty.txt empty.txt
if ERRORLEVEL 1 goto err

rem ����������� � ������� ��� ����������
%PROGRAM% fox-witout-param.txt %TEMP%\fox-witout-param.txt
if NOT ERRORLEVEL 1 goto err
fc.exe  %TEMP%\fox-witout-param.txt fox-witout-param.txt
if NOT ERRORLEVEL 1 goto err

rem ������ ������� ������
%PROGRAM% EmptySearch.txt %TEMP%\EmptySearch.txt "" cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\EmptySearch.txt EmptySearch.txt
if ERRORLEVEL 1 goto err

rem ������ ������ ������
%PROGRAM% EmptyReplace.txt %TEMP%\EmptyReplace.txt fox ""
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\EmptyReplace.txt EmptyReplace.txt
if NOT ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1