import os
import time

while True :
    os.system("cat 63 > test")
    print("mylemin")
    os.system("./lem-in < test | wc -l")
    print("vifonne lemin")
    os.system("../vifonne/lem-in < test | wc -l")
    print("---")
    time.sleep(3)
