@echo off

cls

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
if EXIST uva%1 (
	goto exist
)
mkdir uva%1
popd
type template > hundred\uva%1\uva%1.cpp
echo.>hundred\uva%1\uva%1.in
echo.>hundred\uva%1\uva%1.out
goto end

:tho
pushd thousand
if EXIST uva%1 (
	goto exist
)
mkdir uva%1
popd
type template > thousand\uva%1\uva%1.cpp
echo.>thousand\uva%1\uva%1.in
echo.>thousand\uva%1\uva%1.out
goto end

:mil
pushd million
if EXIST uva%1 (
	goto exist
)
mkdir uva%1
popd
type template > million\uva%1\uva%1.cpp
echo.>million\uva%1\uva%1.in
echo.>million\uva%1\uva%1.out
goto end

:exist
echo uva%1 already exist
popd
goto finish

:end
echo uva%1 Created

g++ add.cpp -o add.exe
if %ERRORLEVEL% EQU 0 (
	add.exe %1
)

echo finsh add to README.md

g++ arrange.cpp -o arrange.exe
if %ERRORLEVEL% EQU 0 (
	arrange.exe
)

echo finish

:finish