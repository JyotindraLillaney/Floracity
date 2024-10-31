# Floracity
An Automated Plant Terrarium optimizing Temperature, Humidity, Soil Moisture, and Lighting through IoT.

I use an Arduino microcontroller to automate the process of Plant growth.

A plant needs optimum levels of Temperature, Humidity, Soil Moisture and Lighting to grow sustainably. In Floraicty, if the humidity levels (as measured by the DHT11 sensor) go too low, the spray bottle automatically gets activated. If humidity gets too high, the window on top of the setup automatically opens up, equalising the humidity outside the inside the setup. Next, if the measured value of soil moisture is too low (as measured by the YL-69 sensor), the pump automatically gets activated and waters the plant through a tank. A concept called aquaponics has also been employed here, in which a fish is used in the tank and the fish waste provides nutrients for the plant's efficient growth. The lighting is measured using a Light Dependent Resistor. If the value is too low, the LEDs (red and blue LED strips since these replicate sunlight the best) automatically get activated and ensure optimum plant growth. All these systems can also be manually controlled using a bluetooth app which is already integrated with the system. By this setup, we can ensure optimum plant growth everywhere, but especially in places where plants don’t get optimum conditions for growth or regular human monitoring.
