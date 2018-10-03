@echo off

pushd uva%1
cls
echo COMPILING...
g++ uva%1.cpp -o uva%1.exe -DDBG

echo FINISH
if %ERRORLEVEL% EQU 0 (
	uva%1.exe
)
popd