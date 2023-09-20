import serial

flag_end = False
arduino = serial.Serial("COM4",baudrate= 9600, timeout=1.5)
f = open("Optima_Battery_8004_250vhhh.txt", "a")

def read_data():
    data = arduino.readline()
    if data.decode('utf-8') == "\n" :
        data = ""
    return data

while flag_end==False:
    val = read_data().decode('utf-8').rstrip("\r\n")
    print(val)
    f.write(val+"\n")
    if(str(val) == 'end'):
        flag_end = True
        
print("End!")
f.close()
arduino.close()