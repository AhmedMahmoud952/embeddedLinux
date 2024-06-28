import os
import shutil

if os.path.exists("project"):
    shutil.rmtree("project")
    print("Folder is deleted")

os.mkdir("project")
os.mkdir("project/src")
os.mkdir("project/tests")
os.mkdir("project/build")

with open("project/src/main.cpp", "w") as file1:
    file1.write("""#include <iostream>\n
    int main(){
        std::cout<<\"helloworld\"<<std::endl;
        return 0;
    }
    """)

with open("project/CMakeLists.txt", "w") as file2:
    file2.write("""cmake_minimum_required(VERSION 3.10)
    project(helloworld)
    add_executable(helloworld src/main.cpp)
    """)

os.chdir("project/build")
os.system("cmake .. && make -j && ./helloworld")

print("Done")