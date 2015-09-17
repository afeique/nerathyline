@echo off
call shell
pushd ..\build
cl -Zi ..\src\win32_main.cpp
popd