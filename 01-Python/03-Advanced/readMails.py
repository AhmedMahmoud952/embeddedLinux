import pyautogui
import webbrowser
import time

# locate is used for finding the image provided and click on it if the isClicked flag equal true 
def locate(image, xShift, yShift, isClicked):
    location = pyautogui.locateOnScreen(image)
    time.sleep(3) 
    pyautogui.moveTo(location[0]+xShift,location[1]+yShift) # (x,y) shift depand on the given screenshots
    time.sleep(1)
    if isClicked:
        pyautogui.click()   
        time.sleep(1)

webbrowser.open_new_tab("https://mail.google.com/mail/u/0/#inbox")
time.sleep(8) #this sleep time depands on computer and internet speed
locate("selectAll.png",20,20,True)
locate("readAll.png",10,20,True)
