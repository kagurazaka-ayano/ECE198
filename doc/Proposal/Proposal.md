# project proposal

## customer problem

### group

Regular monitoring is essential for the health of the elderly because they are more prone to heart diseases. It's probable that many older people don't have the means or awareness to regularly monitor their heart rates. Arrhythmias and other cardiovascular conditions are serious problems for elderly persons, according to [12]. The ability to detect irregular heartbeats early and administer treatment right away thanks to continuous monitoring has the potential to save lives. This is mostly brought on by a dearth of user-friendly technology, issues with cost, and a general ignorance of the importance of periodic monitoring.

Therefore, developing an easy-to-use heart rate monitor tailored for the elderly can address this gap and provide a much-needed solution. Our client will be aimed towards the elderly over the age of 65 in the Waterloo region, which is around 89,705 people[13]. It is important to note that approximately 80% of heart disease deaths occurs in people who are age 65 or older. [14]

### problem the group has

1. As study showned by WHO[1, Para 2], cardiovascular diseases has became a serious problem and has caused 32% of all global deaths
2. Seniors needs to keep track their cardiovascolar efficiency to measure their health condition[2, Para 8]
3. People with heart problems need to keep track of their heart rate to detect irregular heartbeats[3, Para 4]

### stakeholders

1. Seniors over the age of 65 in the Waterloo region
    They are the main users of the product. They will be able to use the product to monitor their heart rate and detect irregular heartbeats.
2. Family members of seniors over the age of 65 in the Waterloo region
    They are the secondary users of the product. They will be able to use the product to monitor the heart rate of their family members and detect irregular heartbeats.
3. Doctors
    They will be able to recommend the product to the users after they verified the reliability of the product since they are the experts in the field of heart diseases.

## Initial Requirement

### Functional Requirements:

- **Pulse Sensor**: 
  - Measure the infrared light (~<780nm) emitted by the human body from heartbeat [6].
  - Display the heart rate in BPM (Beats Per Minute) on the screen.
   
- **Display**:
  - A single-color 128x160 display for displaying the heart rate and any alerts or notifications [10].
  - The display should show real-time heart rate, abnormal heart rate warnings, and battery status.
   
- **Sound Alarm**:
  - Emit an audible alarm when abnormal heart rates are detected.
  - The alarm should have a volume range between 70dB to 85dB, ensuring it's loud enough to alert the user but not too loud to cause discomfort [8].
   
- **LED Indicator**:
  - Illuminate a red LED when abnormal heart rates are detected, serving as a visual alert [11].
  - The LED should blink at a frequency of 1Hz during alerts.

### Technical Requirements:

- **Pulse Sensor**:
  - Response time: The sensor should detect and relay heart rate changes within 2 seconds.
  - Sensitivity: The sensor should detect heart rates in the range of 40-180 BPM.
   
- **Display**:
  - GUI with 128x160 single-color bitmap display [16].
  - Refresh rate: The display should update at least every second to show real-time data.
   
- **Sound Alarm**:
  - Buzzer frequency: The buzzer should operate in the frequency range of 2kHz to 4kHz, which is easily audible to the human ear [17].
  - Volume control: The alarm should have adjustable volume settings.
   
- **LED Indicator**:
  - Luminosity: The red LED should have a luminosity between 50-150 mcd (millicandela) [18].
  - Power consumption: The LED should consume no more than 20mA when illuminated.

### Safety Requirements:

- The maximum voltage this project will carry is no more than 5V [9].
- The alarm must generate a sound of at least 70dB but not exceed 85dB [17].

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

[12] World Health Organization, "Cardiovascular diseases (CVDs)," WHO, [Online]. Available: https://www.who.int/news-room/fact-sheets/detail/cardiovascular-diseases-(cvds). [Accessed: Sep. 28, 2023]. 

[13] Author(s) Name (if provided), "Understanding Heart Aging and Reversing Heart Disease," Verywell Health, [Online]. Available: https://www.verywellhealth.com/understanding-heart-aging-and-reversing-heart-disease-2224231. [Accessed: Sep. 28, 2023]. 

[14] Statistics Canada, "Census Profile, 2021 Census," StatCan, [Online]. Available: https://www12.statcan.gc.ca/census-recensement/2021/dp-pd/prof/details/page.cfm?Lang=E&DGUIDlist=2021S0503541&GENDERlist=1&STATISTIClist=1&HEADERlist=0. [Accessed: Sep. 28, 2023].

[15] “STM32 Nucleo-F401RE Pinout, Specs & Datasheet - Components101,” Components101. [Online]. Available: https://components101.com/microcontrollers/stm32-nucleo-f401re-pinout-datasheet. [Accessed: Sep. 28, 2023].

[16] “Top 15+ Microcontroller Projects | Microcontroller Project Ideas,” Electronics For You. [Online]. Available: https://www.electronicsforu.com/microcontroller-projects-ideas. [Accessed: Sep. 28, 2023].

[17] “How much sound can your ears safely take? And for how long? | NCEH | CDC,” Centers for Disease Control and Prevention. [Online]. Available: https://www.cdc.gov/nceh/hearing_loss/toolkit/quiz-test.html. [Accessed: Sep. 28, 2023].

[18] “Why are danger signals red when the eye is most sensitive to yellow and green?,” Quora. [Online]. Available: https://www.quora.com/Why-are-danger-signals-red-when-the-eye-is-most-sensitive-to-yellow-and-green. [Accessed: Sep. 28, 2023].
