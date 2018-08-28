if [ ! -d /usr/share/cmake ]; then
    echo "Installing cmake 3.12.1\n"
    wget http://www.cmake.org/files/v3.12/cmake-3.12.1.tar.gz
    tar xzf cmake-3.12.1.tar.gz
    cd cmake-3.12.1
    ./bootstrap && make && make install
    cd ..
    rm -rf cmake-3.12.1
    rm -f cmake-3.12.1.tar.gz
else
    echo "cmake 3.12.1 already installed"
fi

echo "\n\nInstalling SFML\n"
apt-get install libsfml-dev

if [ ! -e /usr/share/cmake/Modules/FindSFML.cmake ]; then
    echo "\n\nCopying FindSFML.cmake\n"
    set "curr=%cd%"
    mkdir /usr/share/cmake/Modules
    cd /usr/share/cmake/Modules
    wget https://files.zirk.eu/SFML/FindSFML.cmake
    cd -
else
    echo "\n\nFindSFML.cmake already here"
fi

echo "\n\nExecuting cmake\n"
cmake CMakeLists.txt

echo "\n\nExecuting Makefile\n"
make

echo "\n\nDone! You can now do ./feg.out to play."
echo "If an error occured during the installation make sure you run the script with sudo.\n\n"