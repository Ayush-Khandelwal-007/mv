#!/bin/sh

checkSOURCE(){                                                                  #Function to check if source to be moved exist.
    if [[ -f $1 ]] || [[ -d $1 ]]                                               #To check if it's file or directory
    then
    echo "Yes,$1 exist!\n"
    else
        echo "No,$1 don't exist.Please Enter valid file or directory\n"
        exit 1                                                                  #Exiting if the source file dose not exist.
    fi

}

checkDESTINATION(){                                                             #Function to check if Deatination where sources are to be moved exist.
    if [ -d $1 ]                                                                #To check if it's a directory
    then
    echo "Yes,$1 directory exist!\n"

    elif [ -f $1 ]                                                              #To check if it's file and hence exiting with appropriate message.
    then
    echo "$1 is not a directory.\nPlease enter a valid directory\n"
    exit 1 

    else                                                                        #If destination directory dose not exist then exit with appropriate message.
    echo "No,$1 don't exist .Please Enter valid file or directory\n"
    exit 1 
fi
}

echo "\n-------------------------------------------------------------\n\n"

echo "Enter Absolute paths of the files/directories to be moved(Space Seprated).\n";
read IN                                                                         #Taking input the Absolute path of the source files.
 
echo "\n-------------------------------------------------------------"
echo "Enter Absolute paths of the destination.\n"
read destination                                                                #Taking input the Absolute path of the Destination Directory.

ADDR=$(echo $IN | tr " " "\n")                                                  #Making list of the input Absolute paths of the source files.

echo "\n\n"

for addr in $ADDR
do
    echo "Checking Existance of $addr..."
    checkSOURCE $addr
done

echo "Checking Existance of destination directory"
checkDESTINATION $destination

./mymv $IN $destination                                                          #Calling the self made move file from question 1 to transfer the files.
echo "All files moved sucessfully\n\n"
