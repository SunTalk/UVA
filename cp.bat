@echo off

if %1 leq 1000 (
	cls
	echo COMPILING...
	g++ -std=c++11 hundred\uva%1\uva%1.cpp -o hundred\uva%1\uva%1.exe

	echo FINISH
	if %ERRORLEVEL% EQU 0 (
		hundred\uva%1\uva%1.exe < hundred\uva%1\uva%1.in > hundred\uva%1\uva%1.out
	)
	goto end
)

if %1 leq 10000 (
	cls
	echo COMPILING...
	g++ -std=c++11 thousand\uva%1\uva%1.cpp -o thousand\uva%1\uva%1.exe

	echo FINISH
	if %ERRORLEVEL% EQU 0 (
		thousand\uva%1\uva%1.exe < thousand\uva%1\uva%1.in > thousand\uva%1\uva%1.out
	)
	goto end
)

if %1 leq 100000 (
	cls
	echo COMPILING...
	g++ -std=c++11 million\uva%1\uva%1.cpp -o million\uva%1\uva%1.exe

	echo FINISH
	if %ERRORLEVEL% EQU 0 (
		million\uva%1\uva%1.exe < million\uva%1\uva%1.in > million\uva%1\uva%1.out
	)
	goto end
)

:end