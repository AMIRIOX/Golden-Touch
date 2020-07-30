
#!/bin/bash

SHELL_FOLDER=$(dirname $(readlink -f "$0"))

for file in `ls ${SHELL_FOLDER}`; do 
    if [ "$file" != "cmpl.sh" ]   
    then  
        out=${file%.*}
        g++ ${SHELL_FOLDER}/$file -o ${SHELL_FOLDER}/../bin/$out.exe -std=c++11 -L. D:/Windows" "Kits/10/Lib/10.0.18362.0/um/x64/ShLwApi.Lib
    fi
done
