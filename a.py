import threading
import time
from playsound import playsound

def play_audio(audio_file):
    playsound(audio_file)

audio_file = 'audio/537Welcome.mp3'
audio_thread = threading.Thread(target=play_audio, args=(audio_file,))
audio_thread.start()
audio_thread.join()