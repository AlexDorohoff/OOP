rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ����������� ������������� �����
%PROGRAM% one-line.txt %TEMP%/one-line-copied.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\one-line-copied.txt one-line.txt
if ERRORLEVEL 1 goto err

rem ����������� �������������� �����
%PROGRAM% many-lines.txt %TEMP%/many-lines-copied.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\many-lines-copied.txt many-lines.txt
if ERRORLEVEL 1 goto err

rem ����������� ������� �����
%PROGRAM% empty.txt %TEMP%/empty-copied.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty-copied.txt empty.txt
if ERRORLEVEL 1 goto err

rem ����������� �� �������������� �����
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