
import speech_recognition as sr 
from gtts import gTTS 
import playsound
def speak(text):
    try:
        tts = gTTS(text=text, lang='ko') 
        filename='voice.mp3' 
        tts.save(filename)
        playsound.playsound(filename)
    except:
        print("재생완료")
speak("햄버거 피자 파이썬 자바 주세요")

