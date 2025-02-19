EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 8
Title "Bit Crusher Pedal"
Date "2020-08-16"
Rev "1"
Comp ""
Comment1 "creativecommons.org/licenses/by/4.0/"
Comment2 "License: CC by 4.0"
Comment3 "Author: Jordan Aceto"
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F3:STM32F334K6Tx U?
U 1 1 5F121594
P 5600 3200
AR Path="/5F121594" Ref="U?"  Part="1" 
AR Path="/5F120841/5F121594" Ref="U3"  Part="1" 
F 0 "U3" H 5000 4200 50  0000 C CNN
F 1 "STM32F334K6Tx" H 5050 4100 50  0000 C CNN
F 2 "Package_QFP:LQFP-32_7x7mm_P0.8mm" H 5100 2300 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00097745.pdf" H 5600 3200 50  0001 C CNN
	1    5600 3200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5F122A5D
P 5500 4200
F 0 "#PWR0103" H 5500 3950 50  0001 C CNN
F 1 "GND" H 5505 4027 50  0000 C CNN
F 2 "" H 5500 4200 50  0001 C CNN
F 3 "" H 5500 4200 50  0001 C CNN
	1    5500 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5F122E79
P 5600 4200
F 0 "#PWR0104" H 5600 3950 50  0001 C CNN
F 1 "GND" H 5605 4027 50  0000 C CNN
F 2 "" H 5600 4200 50  0001 C CNN
F 3 "" H 5600 4200 50  0001 C CNN
	1    5600 4200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0105
U 1 1 5F1231FD
P 5550 2200
F 0 "#PWR0105" H 5550 2050 50  0001 C CNN
F 1 "+3.3V" H 5400 2350 50  0000 C CNN
F 2 "" H 5550 2200 50  0001 C CNN
F 3 "" H 5550 2200 50  0001 C CNN
	1    5550 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2300 5600 2200
Wire Wire Line
	5600 2200 5550 2200
Wire Wire Line
	5500 2200 5500 2300
Connection ~ 5550 2200
Wire Wire Line
	5550 2200 5500 2200
Wire Wire Line
	5700 2300 5700 2200
$Comp
L power:+3.3VA #PWR0106
U 1 1 5F12860C
P 5700 2200
F 0 "#PWR0106" H 5700 2050 50  0001 C CNN
F 1 "+3.3VA" H 5800 2350 50  0000 C CNN
F 2 "" H 5700 2200 50  0001 C CNN
F 3 "" H 5700 2200 50  0001 C CNN
	1    5700 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5F12D38A
P 3350 2800
F 0 "C1" V 3098 2800 50  0000 C CNN
F 1 "20pF" V 3189 2800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3388 2650 50  0001 C CNN
F 3 "~" H 3350 2800 50  0001 C CNN
	1    3350 2800
	0    1    1    0   
$EndComp
$Comp
L Device:Crystal X1
U 1 1 5F12D911
P 3650 3150
F 0 "X1" V 3600 3300 50  0000 L CNN
F 1 "8MHz" V 3695 3281 50  0000 L CNN
F 2 "Crystal:Resonator-2Pin_W10.0mm_H5.0mm" H 3650 3150 50  0001 C CNN
F 3 "~" H 3650 3150 50  0001 C CNN
	1    3650 3150
	0    1    1    0   
$EndComp
$Comp
L Device:C C2
U 1 1 5F12DFF2
P 3400 3500
F 0 "C2" V 3148 3500 50  0000 C CNN
F 1 "20pF" V 3239 3500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3438 3350 50  0001 C CNN
F 3 "~" H 3400 3500 50  0001 C CNN
	1    3400 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 3100 4150 3100
Wire Wire Line
	4150 3100 4150 2800
Wire Wire Line
	3650 3000 3650 2800
Wire Wire Line
	3650 2800 3500 2800
Wire Wire Line
	3650 3300 3650 3500
Wire Wire Line
	3650 3500 3550 3500
Wire Wire Line
	4150 3500 4150 3200
Wire Wire Line
	4150 3200 5000 3200
Wire Wire Line
	3250 3500 3100 3500
Wire Wire Line
	3100 3500 3100 2800
Wire Wire Line
	3100 2800 3200 2800
$Comp
L power:GND #PWR0107
U 1 1 5F131E8D
P 3100 3500
F 0 "#PWR0107" H 3100 3250 50  0001 C CNN
F 1 "GND" H 3105 3327 50  0000 C CNN
F 2 "" H 3100 3500 50  0001 C CNN
F 3 "" H 3100 3500 50  0001 C CNN
	1    3100 3500
	1    0    0    -1  
$EndComp
Connection ~ 3100 3500
Text HLabel 6100 2900 2    50   Output ~ 0
DAC_out
Text HLabel 6100 2500 2    50   Input ~ 0
resolution_CV_in
Text HLabel 6100 2600 2    50   Input ~ 0
sample_rate_CV_in
Text HLabel 6100 3000 2    50   Input ~ 0
ADC_in
Text Label 5000 2500 2    50   ~ 0
NRST
Text Label 5000 2700 2    50   ~ 0
BOOT0
Text Label 6100 3800 0    50   ~ 0
SWDIO
Text Label 6100 3900 0    50   ~ 0
SWCLK
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 5F1988EF
P 10300 5600
F 0 "J3" H 10380 5592 50  0000 L CNN
F 1 "SWD_header" H 10380 5501 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 10300 5600 50  0001 C CNN
F 3 "~" H 10300 5600 50  0001 C CNN
	1    10300 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5F1997BE
P 9650 5800
F 0 "#PWR0108" H 9650 5550 50  0001 C CNN
F 1 "GND" H 9655 5627 50  0000 C CNN
F 2 "" H 9650 5800 50  0001 C CNN
F 3 "" H 9650 5800 50  0001 C CNN
	1    9650 5800
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0109
U 1 1 5F19A23B
P 10000 5400
F 0 "#PWR0109" H 10000 5250 50  0001 C CNN
F 1 "+3.3V" H 9850 5550 50  0000 C CNN
F 2 "" H 10000 5400 50  0001 C CNN
F 3 "" H 10000 5400 50  0001 C CNN
	1    10000 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 5400 10000 5500
Wire Wire Line
	10000 5500 10100 5500
Text Label 10000 5800 2    50   ~ 0
SWDIO
Text Label 10000 5600 2    50   ~ 0
SWCLK
Wire Wire Line
	10000 5600 10100 5600
Wire Wire Line
	10000 5800 10100 5800
Wire Wire Line
	9650 5800 9650 5700
Wire Wire Line
	9650 5700 10100 5700
$Comp
L Device:R R4
U 1 1 5F1A6FA3
P 10250 4500
F 0 "R4" H 10350 4500 50  0000 L CNN
F 1 "10k" V 10250 4450 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 10180 4500 50  0001 C CNN
F 3 "~" H 10250 4500 50  0001 C CNN
	1    10250 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5F1A77DE
P 10250 4650
F 0 "#PWR0110" H 10250 4400 50  0001 C CNN
F 1 "GND" H 10255 4477 50  0000 C CNN
F 2 "" H 10250 4650 50  0001 C CNN
F 3 "" H 10250 4650 50  0001 C CNN
	1    10250 4650
	1    0    0    -1  
$EndComp
Text Label 10250 4350 2    50   ~ 0
BOOT0
$Comp
L Device:R R1
U 1 1 5F1B21C2
P 3900 3500
F 0 "R1" V 3800 3500 50  0000 C CNN
F 1 "390" V 3900 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3830 3500 50  0001 C CNN
F 3 "~" H 3900 3500 50  0001 C CNN
	1    3900 3500
	0    1    1    0   
$EndComp
Connection ~ 3650 2800
Wire Wire Line
	3650 2800 4150 2800
Wire Wire Line
	4150 3500 4050 3500
Wire Wire Line
	3750 3500 3650 3500
Connection ~ 3650 3500
$Comp
L Device:C C3
U 1 1 5F1BCAE5
P 9550 4500
F 0 "C3" H 9665 4546 50  0000 L CNN
F 1 "100nF" H 9665 4455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9588 4350 50  0001 C CNN
F 3 "~" H 9550 4500 50  0001 C CNN
	1    9550 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5F1BD091
P 9550 4650
F 0 "#PWR0111" H 9550 4400 50  0001 C CNN
F 1 "GND" H 9555 4477 50  0000 C CNN
F 2 "" H 9550 4650 50  0001 C CNN
F 3 "" H 9550 4650 50  0001 C CNN
	1    9550 4650
	1    0    0    -1  
$EndComp
Text Label 9550 4350 2    50   ~ 0
NRST
$Comp
L Device:LED_Dual_ACA D1
U 1 1 5F293B3A
P 7500 3400
F 0 "D1" H 7500 3825 50  0000 C CNN
F 1 "rg_clipping_LED" H 7500 3734 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm-3" H 7500 3400 50  0001 C CNN
F 3 "~" H 7500 3400 50  0001 C CNN
	1    7500 3400
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5F2952B9
P 6950 3300
F 0 "R2" V 6850 3300 50  0000 C CNN
F 1 "330" V 6950 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6880 3300 50  0001 C CNN
F 3 "~" H 6950 3300 50  0001 C CNN
	1    6950 3300
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5F295B84
P 6950 3500
F 0 "R3" V 6850 3500 50  0000 C CNN
F 1 "330" V 6950 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6880 3500 50  0001 C CNN
F 3 "~" H 6950 3500 50  0001 C CNN
	1    6950 3500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5F295FC9
P 7900 3500
F 0 "#PWR0112" H 7900 3250 50  0001 C CNN
F 1 "GND" H 7905 3327 50  0000 C CNN
F 2 "" H 7900 3500 50  0001 C CNN
F 3 "" H 7900 3500 50  0001 C CNN
	1    7900 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3500 7900 3400
Wire Wire Line
	7900 3400 7800 3400
Wire Wire Line
	7100 3300 7200 3300
Wire Wire Line
	7100 3500 7200 3500
Wire Wire Line
	6800 3300 6100 3300
Wire Wire Line
	6100 3400 6600 3400
Wire Wire Line
	6600 3400 6600 3500
Wire Wire Line
	6600 3500 6800 3500
NoConn ~ 6100 2700
NoConn ~ 6100 2800
NoConn ~ 6100 3100
NoConn ~ 6100 3200
NoConn ~ 6100 3500
NoConn ~ 6100 3600
NoConn ~ 6100 3700
NoConn ~ 6100 4000
NoConn ~ 5000 4000
NoConn ~ 5000 3900
NoConn ~ 5000 3800
NoConn ~ 5000 3700
NoConn ~ 5000 3600
NoConn ~ 5000 3500
NoConn ~ 5000 3400
$EndSCHEMATC
