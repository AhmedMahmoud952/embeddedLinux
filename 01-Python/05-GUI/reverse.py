from tkinter import *

def reverse_function():
    text = text_entry.get()
    label_reverse.config(text=f"Reverse : {text[::-1]}")

window = Tk()
window.title("Reverse")
window.geometry("300x100")
window.resizable(False,False)

text_entry = StringVar(window)

label_text = Label(window,text="Enter a word",padx=20).grid(row=0,column=0)
entry_word = Entry(window,textvariable=text_entry,width=27).grid(row=0,column=1)
label_reverse = Label(window)
label_reverse.grid(row=1,column=0,columnspan=2)
reverse_btn = Button(window, text="Reverse",command=reverse_function).grid(row=2,column=0,columnspan=2,)


window.mainloop()
