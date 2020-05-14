#  Raspberry Pi Master for Arduino Slave
#  i2c_master_pi.py
#  Connects to Arduino via I2C
  
#  DroneBot Workshop 2019
#  https://dronebotworkshop.com

from smbus import SMBus

addr = 0x8 # bus address
bus = SMBus(1) # indicates /dev/ic2-1

print ("Enter 1-5, press 0 to quit")
while True:
    try:
        message = int(input(">>>>   "))
        if message not in range(1,6):
            break

        bus.write_byte(addr, message)
    except:
        print("You must enter a valid number from 1-5")


