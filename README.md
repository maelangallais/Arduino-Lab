A collection of personal Arduino utilities, mini-projects, and hardware experiments. Each `.ino` sketch is stored in its own matching folder so it can be opened and compiled directly in the Arduino IDE.

# 🛠️ Tools

## RFID UID Reader (`tools/rfid_uid_reader/`) *(Created November 29, 2023)*
Reads MFRC522 RFID tags and prints their decimal UID to the Serial Monitor formatted as a ready-to-use C++ `const byte` array (`bonUID[...]`). Useful for retrieving tag identifiers before configuring access-control sketches such as [Home-Security-System](https://github.com/maelangallais/Home-Security-System).

---

# 🎮 Mini Projects

## Dino Chrome Bot (`mini_projects/dino_chrome_bot/`) *(Created November 28, 2023)*
Automates the Chrome Dino game physically using a photoresistor (`A0`) placed in front of the screen and a servo motor (`pin 8`) that presses the spacebar whenever an obstacle darkens the sensor (`luminosity < 120`).

## Keypad LED Matrix (`mini_projects/keypad_led_matrix/`) *(Created November 27, 2023)*
Interactive 4×4 grid toggle on an 8×8 MAX7219 LED matrix controlled by a 4×4 membrane keypad. Each key toggles a dedicated 2×2 LED block on the display.

## Sound Relay Switch (`mini_projects/sound_relay_switch/`) *(Created November 27, 2023)*
Clap/noise-activated toggle switch using a digital sound sensor (`pin 8`) to control a relay (`pin 7`) — ideal for switching an RGB LED strip or external load on and off.

## IR Door Closer (`mini_projects/ir_door_closer/`) *(Created February 18, 2024)*
Uses an infrared receiver (`pin 7`) and a stepper motor (`pins 8–11`) to wind or unwind a cable remotely in order to pull a door shut. Note: mechanically limited by cable attachment and door weight.

## Humidity LCD Display (`mini_projects/humidity_lcd_display/`) *(Created February 17, 2024)*
Reads ambient humidity from a DHT11 sensor (`pin 4`, using `dht_nonblocking`) and displays the percentage on a 16×2 LCD screen.

---

# 🧪 Experiments

## Keypad PIN Lock (`experiments/keypad_pin_lock/`) *(Created November 27, 2023)*
Prompts the user to enter a 4-digit passcode on a 4×4 membrane keypad and displays validation feedback on a 16×2 LCD. Served as a standalone prototype for `Home-Security-System`.

## PIR Motion Alarm (`experiments/pir_motion_alarm/`) *(Created February 04, 2024)*
Monitors a PIR motion sensor (`pin 7`) after a 10-second calibration delay and triggers a blinking LED (`pin 8`) alongside an active buzzer (`pin 9`) when movement is detected.

## 74HC595 Shift Register (`experiments/shift_register_74hc595/`) *(Created November 29, 2023)*
Controls 8 LEDs using only 3 digital pins (`latchPin`, `clockPin`, `dataPin`) via a 74HC595 shift register, allowing individual LEDs (`1–8`) to be toggled or all LEDs (`0`) to be turned off from the Serial Monitor.

## RGB Strip Fade (`experiments/rgb_strip_fade/`) *(Created November 27, 2023)*
Cycles an RGB LED strip (`pins 12, 10, 8`) through smooth PWM color transitions without external input.

## Joystick Servo (`experiments/joystick_servo/`) *(Created November 27, 2023)*
Maps the analog value of a joystick axis (`A0`, `0–1023`) directly to a servo motor angle (`0°–180°` on `pin 9`).

## Loop Benchmark (`experiments/loop_benchmark/`) *(Created December 03, 2023)*
Measures how many iterations the Arduino `loop()` can execute within one second and prints the count to the Serial Monitor.
