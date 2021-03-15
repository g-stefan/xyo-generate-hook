@echo off
rem Public domain
rem http://unlicense.org/
rem Created by Grigore Stefan <g_stefan@yahoo.com>

echo -^> sign xyo-generate-hook

pushd output
for /r %%i in (*.exe) do call grigore-stefan.sign "XYO generate hook" "%%i"
popd
