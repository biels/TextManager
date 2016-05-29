rd /S /Q package
mkdir package
for /R ../src %%f in (*.h) do copy %%f package\
for /R ../src %%f in (*.cpp) do copy %%f package\
for /R package %%f in (*.*) do sed -i -b -r 's/#include ".+\//#include "/g' %%f
cp makefile.txt package/Makefile
cd package\
ren *.cpp *.cc
ren TextManager.cc program.cc
tar -cvf ../practica.tar Makefile *.*