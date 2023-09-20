# project proposal

## customer problem

### group

1. People who have heart problems
2. Athletes and seniors who needs to measure their heartrate

### problem the group has

1. As study showned by WHO[1, Para 2], cardiovascular diseases has became a serious problem and has caused 32% of all global deaths
2. Athletes and seniors needs to keep track their cardiovascolar efficiency to measure their health condition[2, Para 8]
3. People with heart problems need to keep track of their heart rate to detect irregular heartbeats[3, Para 4]

## Initial requirement

### Functional Requirements: 

- Use the pulse sensor to measure the infrared light (~<780nm) emitted by human body from heartbeat [6]
- A single-color 128*160 display for displaying information [10]
- Sound alarm with buzzer since people are more sensitive to sound stimulus [8]
- abnormal heartrate indicator with red LED since people are more sensitive to red light than lights of other color[11]

### Technical Requirements: 

- battery with 5V output
- GUI with 128*160 single-color bitmap display
- buzzer that generate sound louder than 70db
- red led indicator

### Safety Requirements: 

- The maxium voltage this project will carry is no more than 5V [9]
- The alarm must generate a sound of at least 70dB but not exceed 85dB.

## Principles

- photoplethysmography (PPG) principle:

photoplethysmography (PPG) is a non-invasive optical technology used to detect changes in blood volume in micro vessels on the surface of tissues. It measures changes in the absorption or reflection of light as blood pulses in capillaries, thereby determining heart rate[4].

- hysteresis  

hysteresis is used to prevent frequent triggering of the heart rate detection when the signal fluctuates around a threshold.[5]

- running average

Calculates a running average of the Inter-Beat Intervals (IBI) to determine the Beats Per Minute (BPM). A running average helps in smoothing out fluctuations and provides a more stable and reliable measure. [7]

## References

[1] “Cardiovascular diseases (CVDs),” World Health Organization. [Online]. Available: https://www.who.int/news-room/fact-sheets/detail/cardiovascular-diseases-(cvds). [Accessed: Sep 19, 2023]

[2] “The Importance of Measuring Your Resting Heart Rate,” Biostrap. [Online]. Available: https://biostrap.com/academy/the-importance-of-measuring-your-resting-heart-rate/. [Accessed: Sep 19, 2023]

[3] “Aftercare Information,” MyHealth.Alberta.ca. [Online]. Available: https://myhealth.alberta.ca/Health/aftercareinformation/pages/conditions.aspx?hwid=abs1713. [Accessed: Sep 19, 2023]

[4] “Physiological Measurement,” IOPscience. [Online]. Available: https://iopscience.iop.org/article/10.1088/0967-3334/28/3/R01/meta. [Accessed: Sep 19, 2023]

[5] “Hysteresis,” Wikipedia. [Online]. Available: https://en.wikipedia.org/wiki/Hysteresis. [Accessed: Sep 19, 2023]

[6] “Pulse Sensor,” ROHM Semiconductor. [Online]. Available: https://www.rohm.com/electronics-basics/sensor/pulse-sensor. [Accessed: Sep 19, 2023]

[7] “Moving average,” Wikipedia. [Online]. Available: https://en.wikipedia.org/wiki/Moving_average. [Accessed: Sep 19, 2023]

[8] “Do We Respond Faster to Visual or Auditory Stimuli?,” Science Oxygen. [Online]. Available: https://scienceoxygen.com/do-we-respond-faster-to-visual-or-auditory-stimuli/. [Accessed: Sep 19, 2023]

[9] “Pulse Sensor Working Principle and Its Applications,” Elprocus. [Online]. Available: https://www.elprocus.com/pulse-sensor-working-principle-and-its-applications/#:~:text=This%20sensor%20can%20be%20used,is%20%2B5V%20or%203.3V. [Accessed: Sep 19, 2023]

[10] “Display Module ST7735 128x160 for STM32,” Amazon.ca. [Online]. Available: https://www.amazon.ca/Display-Module-ST7735-128x160-STM32/dp/B07BFV69DZ/ref=sr_1_5?crid=PPGK4P60DFAR&keywords=display+STM32&qid=1695173472&sprefix=display+stm32%2Caps%2C109&sr=8-5. [Accessed: Sep 19, 2023]

[11] “Does Colour Really Affect Our Brain and Body? A Professor of Colour Science Explains,” ScienceAlert. [Online]. Available: https://www.sciencealert.com/does-colour-really-affect-our-brain-and-body-a-professor-of-colour-science-explains. [Accessed: Sep 19, 2023]
