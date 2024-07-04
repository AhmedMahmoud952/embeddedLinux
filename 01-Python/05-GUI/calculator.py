from tkinter import *

def calc():
    global m_entry,n_entry,op_entry
    if op_entry.get():
        ans = m_entry.get() + n_entry.get()
        label_answer.config(text = f"the sum of {m_entry.get()} + {n_entry.get()} : {ans}")
    else:
        ans = m_entry.get() - n_entry.get()
        label_answer.config(text = f"the sub of {m_entry.get()} - {n_entry.get()} : {ans}")

window = Tk()
window.title("Calculator")
window.geometry("300x120")
window.resizable(False,False)

m_entry = IntVar(window)
n_entry = IntVar(window)
op_entry = IntVar()

label_m = Label(window,text="Enter the Value of M",padx=10).grid(row=0,column=0)
entry_m = Entry(window,textvariable=m_entry,width=25).grid(row=0,column=1)
label_n = Label(window,text="Enter the Value of N",padx=10).grid(row=1,column=0)
entry_n = Entry(window,textvariable=n_entry,width=25).grid(row=1,column=1)

Radiobutton(window,text="Sub",variable=op_entry,value=0).grid(row=2,column=1)
Radiobutton(window,text="Sum",variable=op_entry,value=1).grid(row=2,column=0)

label_answer = Label(window,padx=10)
label_answer.grid(row=3,column=0,columnspan=2)


clac_btn = Button(window, text="Calculate",command=calc,width=30).grid(row=4,column=0,columnspan=2,)

window.mainloop()
