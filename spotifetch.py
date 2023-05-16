import serial,time
from SwSpotify import spotify

arduino_uno = serial.Serial('COM7', 9600)
fetched_song = " "



print("  ███████╗██████╗  ██████╗ ████████╗██╗███████╗███████╗████████╗ ██████╗██╗  ██╗   ")
print("  ██╔════╝██╔══██╗██╔═══██╗╚══██╔══╝██║██╔════╝██╔════╝╚══██╔══╝██╔════╝██║  ██║   ")
print("  ███████╗██████╔╝██║   ██║   ██║   ██║█████╗  █████╗     ██║   ██║     ███████║   ")
print("  ╚════██║██╔═══╝ ██║   ██║   ██║   ██║██╔══╝  ██╔══╝     ██║   ██║     ██╔══██║   ")
print("  ███████║██║     ╚██████╔╝   ██║   ██║██║     ███████╗   ██║   ╚██████╗██║  ██║   ")
print("  ╚══════╝╚═╝      ╚═════╝    ╚═╝   ╚═╝╚═╝     ╚══════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝   ")

print("\n\n")



def get_song():

    # creating a variable to continuously update the current song that is playing. This variable is crucial for song detection.
    current_song = spotify.song()
    current_artist = spotify.artist()
    global fetched_song

    # creating a nested if-statement to send the arduino the song name if the previous song and the current song are different.
    if current_song != fetched_song:
        print(current_song)
        print(current_artist)
        print("____________")
    datastream = current_song+"%"+current_artist
    # using the pySerial's 'write()' function to write the song name with encoding to the arduino through the COM7 port.
    arduino_uno.write(datastream.encode())

    # code to tie/update the old song to the current song.
    fetched_song = current_song

while True:
    # calling the function to get the song name from the SwSpotify module and send it to the Arudino for display.
    get_song()
    time.sleep(5)
