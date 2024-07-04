from tkinter import *

def on_led():
    c.itemconfig(led_oval,fill ="red")
    label_answer.config(text="LED is ON")

def off_led():
    c.itemconfig(led_oval,fill ="white")
    label_answer.config(text="LED is OFF")

win_width = 300
win_height = win_width

window = Tk()
window.title("Gauge")
window.geometry(f"{win_width}x{win_height+60}")
window.resizable(False,False)

c = Canvas(window,width=win_width,height=win_height)

xy = win_width /10, win_height/10, win_width*9/10, win_height*9/10
led_oval = c.create_oval(xy, fill="white")

c.grid(row=0,column=0, columnspan=2)

on_btn = Button(window, text="ON",width=18,command=on_led,relief="groove").grid(row=1,column=0)
off_btn = Button(window, text="OFF",width=18,command=off_led,relief="groove").grid(row=1,column=1)

label_answer = Label(window,padx=10,text="LED is OFF",pady=5)
label_answer.grid(row=2,column=0,columnspan=2)

window.mainloop()
