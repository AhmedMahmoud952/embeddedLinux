import os
import shutil

if os.path.exists("project"):
    shutil.rmtree("project")
    print("Old folder deleted")

os.mkdir("project")
os.chdir("project")

with open("private.h", "w") as file:
    file.write("""
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define DDRA       *((volatile u8*)0x3a)
#define DDRB       *((volatile u8*)0x37)
#define DDRC       *((volatile u8*)0x34)
#define DDRD       *((volatile u8*)0x31)

#endif
    """)

with open("program.c","w") as file:
    file.write("""
#include \"private.h\"

void DIO_setPortsDirection(){
    """)

ports = ["DDRA", "DDRB", "DDRC", "DDRD"]
for port in ports:
    
    answer = input(f"Are you gonna use {port} (y/n)")
    
    if answer.lower() == "y":
       
        binary=""
        
        for i in range(0, 8):
            
            answer = input(f"do you want pin {i} to be (in/out)")
            if answer.lower() == "out":
                binary+= "1"
            else:
                binary +="0"

        with open("program.c","a") as file:
            file.write(f"\n    {port} = 0b{binary[::-1]};")

    else:
        continue

with open("program.c","a") as file:
    file.write("\n}")