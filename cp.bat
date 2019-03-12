@echo off

if %1 leq 1000 (
	goto hun
)

if %1 leq 10000 (
	goto tho
)

if %1 leq 100000 (
	goto mil
)

:hun
	pushd hundred
	goto run
:tho
	pushd thousand
	goto run
:mil
	pushd million
	goto run

:run
pushd uva%1

cls
echo COMPILING...
g++ -std=c++11 uva%1.cpp -o uva%1.exe -DDBG

echo FINISH
if %ERRORLEVEL% EQU 0 (
	uva%1.exe
)

popd
popd