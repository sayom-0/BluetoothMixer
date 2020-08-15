cmake_minimum_required(VERSION 3.18)
project(BluetoothMixer)

set(CMAKE_CXX_STANDARD 11)

add_executable(BluetoothMixer main.cpp UIObjs/GenericUi.cpp UIObjs/GenericUi.h Utils.cpp Utils.h ShellExec.cpp ShellExec.h)
