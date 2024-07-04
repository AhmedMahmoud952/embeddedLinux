from tkinter import *
import math

def degree_coord(anc_x,anc_y,rad,deg):
    # transform the degree coords to x,y coords
    return anc_x, anc_y, (anc_x +(rad*math.cos(math.radians(deg)))),(anc_y - (rad*math.sin(math.radians(deg))))

def slider(x):
    # x is arg passed by scale widget
    mapping = 360-int(x)*3.6
    c.coords(line_pointer,degree_coord(win_width/2,win_height/2,120,mapping))

win_width = 400
win_height = 400

window = Tk()
window.title("Gauge")
window.geometry(f"{win_width}x{win_height + 50}")
window.resizable(False,False)

c = Canvas(window, bg= "wheat3",width=win_width,height=win_height)

xy = win_width/10,win_height/10,win_width*9/10,win_height*9/10
c.create_oval(xy,fill="dark green")
c.create_arc(xy, start=30, extent=90, fill="orange2")
c.create_arc(xy, start=0, extent=30, fill="red4")

flag = 4
for i in range(0,361,5):
    if flag == 4:
        c.create_line(degree_coord(win_width/2,win_height/2,160,i))
        flag = 0
        continue
    c.create_line(degree_coord(win_width/2,win_height/2,145,i))
    flag +=1
    

xy = win_width*2/10,win_height*2/10,win_width*8/10,win_height*8/10
c.create_oval(xy,fill="dark green",outline="dark green")
c.create_arc(xy, start=30, extent=90, fill="orange2",outline = "orange2")
c.create_arc(xy, start=0, extent=30, fill="red4",outline = "red4")

for i in range(0,341,20):
    mapping = 360 - int(i)
    c.create_text(degree_coord(win_width/2,win_height/2,140,i)[2:],text=mapping,font=8,fill="white")



line_pointer = c.create_line(degree_coord(win_width/2,win_height/2,120,0),width=4,arrow="last",fill="black")
c.create_oval(win_width*0.48,win_height*0.48,win_width*0.52,win_height*0.52,fill="black")

c.pack()
scale_widget = Scale(window,from_=0,to=100,orient=HORIZONTAL,length=win_width-20,command=slider).pack()
window.mainloop()
