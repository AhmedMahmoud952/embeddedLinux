import speech_recognition as sr
import pyaudio
import gtts
from playsound import playsound
import re
import webbrowser
import time
import os

r = sr.Recognizer()
def recordAudioAsString():
    with sr.Microphone() as source:
        try:
            playsound("listening.mp3")
        except:
            print("Listening...")
        r.adjust_for_ambient_noise(source)
        audio_text = r.listen(source)
        print("Finsished listening.")
        
        try:
            text = r.recognize_google(audio_text, language = "ar-EG")
            print("You said: " + text)
            return text
        except sr.UnknownValueError:
            print("Sorry, I did not get that")
        except sr.RequestError:
            print("Request Error")
        return ""

def speak(text):
    try:
        audio = gtts.gTTS(text=text, lang="ar")
        audio.save("alexaResponse.mp3")
        playsound("alexaResponse.mp3")
        os.remove("alexaResponse.mp3") #a fix for gtts not working the second time
    except :
        print("Faild to generate audio")

def findWord(input_string,words): #you should pass the selected words as list always 
    pattern = r'[\u0600-\u06FF\u0750-\u077F]+'
    matches = re.findall(pattern, input_string)
    for word in words:
        if matches.count(word):
            return True
    return False
    


close = ['قفل','اقفل','اغلاق']
name = ['اسمي','اسم','الاسم']
google = ["جوجل"]
youtube = ['يوتيوب', 'اليوتيوب']
facebook = ['الفيسبوك', 'فيسبوك', 'الفيس', 'فيس']
while True:
    text = recordAudioAsString()
    if text == "":
        continue
    speak(text)

    if findWord(text, google):
        webbrowser.open_new("https://www.google.com")
    if findWord(text, youtube):
        webbrowser.open_new("https://www.youtube.com")
    if findWord(text, facebook):
        webbrowser.open_new("https://www.fb.com")
    if findWord(text,name):
        speak('اسمك احمد محمود يا كبير')
    if findWord(text,close):
        break