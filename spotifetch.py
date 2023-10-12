import serial,time
from SwSpotify import spotify

arduino_uno = serial.Serial('COM9', 9600)  #communicate on port COM7
# Change this port to reflect where your Arduino is connected
fetched_song = " "

print("  ███████╗██████╗  ██████╗ ████████╗██╗███████╗███████╗████████╗ ██████╗██╗  ██╗   ")
print("  ██╔════╝██╔══██╗██╔═══██╗╚══██╔══╝██║██╔════╝██╔════╝╚══██╔══╝██╔════╝██║  ██║   ")
print("  ███████╗██████╔╝██║   ██║   ██║   ██║█████╗  █████╗     ██║   ██║     ███████║   ")
print("  ╚════██║██╔═══╝ ██║   ██║   ██║   ██║██╔══╝  ██╔══╝     ██║   ██║     ██╔══██║   ")
print("  ███████║██║     ╚██████╔╝   ██║   ██║██║     ███████╗   ██║   ╚██████╗██║  ██║   ")
print("  ╚══════╝╚═╝      ╚═════╝    ╚═╝   ╚═╝╚═╝     ╚══════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝   ")

print("\n\n")


def get_song():

    current_song = spotify.song()   # Fetch Song
    current_artist = spotify.artist()    # Fetch Artist
    global fetched_song

    title, artist = spotify.current()


    if current_song != fetched_song:   # Cleaning up terminal, only displays song and artist once
        print(current_song)
        print(current_artist)
        print("____________")
    datastream = current_song+"%"+current_artist # Combines Song and Artist into one string, to send it serially
    # data will be decoded at the arduino end

    arduino_uno.write(datastream.encode()) # using the pySerial's 'write()' function to write the song name with encoding to the arduino through the COM7 port.
    #update sent every 5 seconds
    fetched_song = current_song

while True:
    try:
        get_song() # Calls function
    except SpotifyPaused as e:
        print("error");
    time.sleep(2)
