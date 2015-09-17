@echo off
call shell
if not exist ..\build mkdir ..\build
pushd ..\build
cl -Zi ..\src\win32_main.cpp
popd