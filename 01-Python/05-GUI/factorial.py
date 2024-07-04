from tkinter import *
import math
def fac():
    global n_entry
    label_answer.config(text = f"the Factorial of {n_entry.get()} is {math.factorial(n_entry.get())}")

window = Tk()
window.title("Factorial")
window.geometry("300x120")
window.resizable(False,False)

n_entry = IntVar(window)

label_n = Label(window,text="Enter the Value of N",padx=10).grid(row=0,column=0)
entry_n = Entry(window,textvariable=n_entry,width=25).grid(row=0,column=1)

label_answer = Label(window,padx=10)
label_answer.grid(row=1,column=0,columnspan=2)

clac_btn = Button(window, text="Factorial",command=fac,width=30).grid(row=2,column=0,columnspan=2,)

window.mainloop()
