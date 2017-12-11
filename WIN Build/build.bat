@echo off
title Joonaksen paska ohjelma Build
@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64   
set sources= main.cpp interpreter.cpp floor.cpp bareground.cpp  
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:game.exe
cl.exe %compilerflags% %sources% /link %linkerflags%