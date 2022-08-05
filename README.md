# Social Distancing Mask Clip

During this new age of COVID-19, I thought it would be helpful to
remind people about maintaining social distancing. My idea was
to have a simple device that attaches onto any mask, eventually
landing on alligator clips (label 2).
Distance readings are primarily drawn from the ultrasonic sensor
(label 1), but a humidity sensor is also used (label 6) for additional
accuracy.
Wearers are alerted of standing too close to someone through a
piezo buzzer's soft beeping (label 7). Additionally, the blue LED
(label 3) signals to others that they are too close for safety.

Users interact with this device by setting grace periods.
Otherwise, the device would always be looking for distances less
than 6 feet. Flicking the switch (label 8) will turn the device
completely off, serving as a bypass switch for long grace periods.
The tactile switch (label 4) starts a grace period of only 60
seconds.
Lastly, I used an Arduino Nano (label 5) to keep the device as
compact and light-weight as possible.

