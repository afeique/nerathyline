@echo off
if not exist ..\build mkdir ..\build
pushd ..\build
cl -Zi ..\src\win32_main.cpp user32.lib
popd