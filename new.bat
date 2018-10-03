@echo off

cls
mkdir uva%1

type template > uva%1\uva%1.cpp
echo.>uva%1\uva%1.in
echo.>uva%1\uva%1.out


echo uva%1 Created